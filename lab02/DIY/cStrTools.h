/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: main.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date  2022/01/30     Reason
-----------------------------------------------------------*/
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
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
    void read(char* cString, unsigned int maxSize, char delimiter = '\n');
}
#endif