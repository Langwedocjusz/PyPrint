cmake_minimum_required(VERSION 3.30.2)

project(PyPrint)

option(PYPRINT_INCLUDE_AS_SYSTEM "Includes headers as system, so they won't trigger warnigns" OFF)

include(cmake/utils.cmake)

#Declare interface library (header only)
add_library(${PROJECT_NAME} INTERFACE)

if (PYPRINT_INCLUDE_AS_SYSTEM)
  target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE include)
else()
  target_include_directories(${PROJECT_NAME} INTERFACE include)
endif()

#Custom target to make lib source show up in IDEs
add_custom_target(PyPrintLib SOURCES "include/PyPrint.h")

#Build tests only if built as standalone project:
if(PROJECT_IS_TOP_LEVEL)
    if(MSVC)
        msvc_enable_multiprocess_global()
    endif()

    #Create target for tests:
    set(TestTargetName "PyPrintTest")

    add_executable(${TestTargetName})

    target_compile_features(${TestTargetName} PRIVATE cxx_std_20)

    target_include_directories(${TestTargetName} PRIVATE ./tests)

    #Also adding header files, to make them visible in IDEs
    target_sources(${TestTargetName}
        PRIVATE
            tests/AutoCaptureCout.h
            tests/AutoCaptureCout.cpp
            tests/TestCoutFn.h
            tests/Tests.cpp
    )

    #To enable usage of clang-tidy:
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
    
    enable_warnings(${TestTargetName})

    if(MSVC)
        msvc_startup_project(${TestTargetName})
        msvc_working_directory(${TestTargetName} ${CMAKE_SOURCE_DIR})
    endif()

    source_group(include REGULAR_EXPRESSION "include/*")
    source_group(tests REGULAR_EXPRESSION "tests/*") 

    #Fetch Catch2 for testing:
    include(FetchContent)

    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.4.0 # or a later release
    )

    FetchContent_MakeAvailable(Catch2)

    target_link_libraries(${TestTargetName} PRIVATE PyPrint)
    target_link_libraries(${TestTargetName} PRIVATE Catch2::Catch2WithMain)
endif()