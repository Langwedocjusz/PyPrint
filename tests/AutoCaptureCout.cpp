#include "AutoCaptureCout.h"

#include <iostream>

namespace pp{

AutoCaptureCout::AutoCaptureCout()
    : m_Original(std::cout.rdbuf())
{
    std::cout.rdbuf(m_Oss.rdbuf());
}

AutoCaptureCout::~AutoCaptureCout()
{
    std::cout.rdbuf(m_Original);
}

std::string AutoCaptureCout::str()
{
    return m_Oss.str();
}

}