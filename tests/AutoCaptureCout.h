#pragma once

#include <string>
#include <streambuf>
#include <sstream>

namespace pp{

class AutoCaptureCout{
    public:
        AutoCaptureCout();
        ~AutoCaptureCout();
        std::string str();
    private:
        std::streambuf* m_Original = nullptr;
        std::ostringstream m_Oss;
};

}