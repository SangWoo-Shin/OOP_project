/*
    ==================================================
    Mile Stone 5-6
    ==================================================
    Name   : Sangwoo Shin
    ID     : 119294213
    Email  : sshin36@myseneca,ca
    Section: NCC
    Date   : 2022/4/7
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    int getInt(const char* prompt)
    {
        int _input;
        char _buffer;
        bool _flag = false;


        if (prompt) cout << prompt;

        do {
            cin >> _input;

            if (!cin) {
                cout << "Invalid Integer, retry:  ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cin.get(_buffer);

                if (_buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else _flag = true;
            }
        } while (!_flag);

        return _input;
    }

    int Utils::getInt(int min, int max, const char* prompt,
        const char* errMes)
    {
        bool showRangeAtError = true;
        int _input;
        char _buffer;
        bool _flag = false;

        if (prompt) cout << prompt;

        do {
            cin >> _input;

            if (!cin) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cin.get(_buffer);

                if (_buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                else if (_input < min || _input > max) {
                    if (errMes) cout << errMes;
                    if (showRangeAtError) cout << "[" << min << "<=val<=" << max << "]: ";
                }
                else
                {
                    _flag = true;
                }
            }
        } while (!_flag);

        return _input;
    }
    void Utils::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
        {
            istr.ignore();
        }
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    int Utils::strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    const char* Utils::strStr(const char* str, const char* find)
    {
        const char* faddress = nullptr;
        int i;
        int flen = (int)strlen(find);
        int slen = (int)strlen(str);
        for (i = 0; i <= slen - flen && strnCmp(&str[i], find, flen); i++);
        if (i <= slen - flen) faddress = &str[i];
        return faddress;
    }
}
