#pragma once
//Workshop1 part2
//Name : Sang Woo, Shin
//Student ID : 119294213
//Email : sshin36@myseneca.ca
//Section Information Code : NCC
#define _CRT_SECURE_NO_WARNINGS

#ifndef NAMESPACE_CSTRTOOLS_H 
#define NAMESPACE_CSTRTOOLS_H

namespace sdds
{
    char toLower(char ch);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    int strLen(const char* str);
    const char* strStr(const char* str, const char* find);
    void strCpy(char* des, const char* src);
    int isAlpha(char ch);
    int isSpace(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif