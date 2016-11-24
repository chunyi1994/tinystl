#ifndef CI_STRING_H
#define CI_STRING_H

#include <string>
#include <string.h>
namespace tinystl {
//为stl扩充的类
//大小写不敏感的string

struct ci_char_traits : public std::char_traits <char> {
    static bool eq(char c1, char c2) {
        return std::toupper(c1) == std::toupper(c2);
    }

    static bool lt(char c1, char c2) {
        return std::toupper(c1) < std::toupper(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n) {
        int m = n;
        while(m--) {
            if(std::toupper(*s1) != std::toupper(*s2)) {
                return -1;
            }
            s1++;
            s2++;
        }
        return 0;
    }

    static const char* find(const char* s, int n, char a) {
        while(n-- > 0 && std::toupper(*s) != std::toupper(a)) {
            ++s;
        }
        return n >= 0 ? s : 0;
    }
};


typedef std::basic_string<char, ci_char_traits> ci_string;


}
#endif // CI_STRING_H

