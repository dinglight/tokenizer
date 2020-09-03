#include "util.h"
#include <algorithm>
#include <cctype>
#include <locale>
namespace util {

void StringUtil::LTrim(std::string & s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),[](int ch){
        return !std::isspace(ch);
    }));
}
void StringUtil::RTrim(std::string & s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),[](int ch){
        return !std::isspace(ch);
    }).base(), s.end());
}
void StringUtil::Trim(std::string & s)
{
    LTrim(s);
    RTrim(s);
}
}