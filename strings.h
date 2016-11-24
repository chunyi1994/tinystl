#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
//为stl扩充的工具函数
//这里的函数都是可以在标准STL里使用的
using std::vector;
using std::string;
using std::copy;
using std::transform;



bool trimLeft(string& str)
{
    if (str.empty())
    {
        return false;
    }

    str.erase(0, str.find_first_not_of(" "));
    return true;
}

bool trimRight(string& str)
{
    if (str.empty())
    {
        return false;
    }

    str.erase( str.find_last_not_of(" ") + 1);

    return true;
}

bool trim(string& str)
{
    if (str.empty())
    {
        return false;
    }

    str.erase(0, str.find_first_not_of(" "));
    str.erase( str.find_last_not_of(" ") + 1);
    return true;
}

static int toLower(int c)
{
    return tolower(c);
}

// string转小写
static std::string strToLower(const std::string &str)
{
    string strTmp = str;
    transform(strTmp.begin(),strTmp.end(),strTmp.begin(), toLower);
    return strTmp;
}

static bool compareNoCase(const std::string &strA,const std::string &strB)
{
    std::string str1 = strToLower(strA);
    std::string str2 = strToLower(strB);
    return str1 == str2;
}

static std::wstring StringToWString(const std::string &str)
 {
     std::wstring wstr(str.length(),L' ');
     std::copy(str.begin(), str.end(), wstr.begin());
     return wstr;
 }

 //只拷贝低字节至string中
static  std::string WStringToString(const std::wstring &wstr)
 {
     string str(wstr.length(), ' ');
     copy(wstr.begin(), wstr.end(), str.begin());
     return str;
 }

static std::string int2string(const int i)
{
    std::stringstream is;
    is<<i;
    return is.str();
}

static int string2int(const std::string& s)
{
    if(s.length() == 0)
    {
        return 0;
    }
    std::istringstream is(s);
    int ret = 0;
    is>>ret;
    return ret;
}

static vector<string> split(const string& str, const string& dest)
{
    size_t pos1 = 0;
    size_t pos2 = 0;
    vector<string> vec;
    bool quit = false;
    while(!quit)
    {
        pos2 = str.find(dest, pos1);
        if(pos2 == string::npos)
        {
            pos2 = str.length();
            quit = true;
        }
        string subStr = str.substr(pos1, pos2 - pos1);
        vec.push_back(std::move(subStr));
        pos1 = pos2 + 1;

        if(pos1 >= str.length())
        {
            quit = true;
        }
    }

    return vec;
}

#endif // STRING_UTILS_H

