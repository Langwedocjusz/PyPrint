cmake_minimum_required(VERSION 3.30.2)

project(PyPrint)

include(cmake/utils.cmake)

#Declare interface library (header only)
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

#Build tests only if built as standalone project:
if(PROJECT_IS_TOP_LEVEL)
    #Fetch Catch2 for testing:
    include(FetchContent)

    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.4.0 # or a later release
    )

    FetchContent_MakeAvailable(Catch2)

    #Create target for tests:
    set(TestTargetName "PyPrintTest")

    add_executable(${TestTargetName})

    target_compile_features(${TestTargetName} PRIVATE cxx_std_20)

    enable_warnings(${TestTargetName})

    target_include_directories(${TestTargetName} PRIVATE ./tests)
    target_sources(${TestTargetName}
        PRIVATE
            tests/AutoCaptureCout.cpp
            tests/Tests.cpp
    )

    target_link_libraries(${TestTargetName} PRIVATE PyPrint)
    target_link_libraries(${TestTargetName} PRIVATE Catch2::Catch2WithMain)
endif()