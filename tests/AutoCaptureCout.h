#pragma once

#include <sstream>
#include <streambuf>
#include <string>

namespace pp
{

class AutoCaptureCout
{
  public:
    AutoCaptureCout();
    ~AutoCaptureCout();
    std::string str();

  private:
    std::streambuf *m_Original = nullptr;
    std::ostringstream m_Oss;
};

} // namespace pp