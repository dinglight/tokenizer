#ifndef UTIL_H_
#define UTIL_H_
#include <string>
namespace util {

class StringUtil {
public:
    static void LTrim(std::string & s);
    static void RTrim(std::string & s);
    static void Trim(std::string & s);
};

}


#endif // UTIL_H_