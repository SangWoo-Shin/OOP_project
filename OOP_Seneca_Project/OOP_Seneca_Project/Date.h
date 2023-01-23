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


#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "Status.h"
#include "Utils.h"


namespace sdds
{
    const int maximumYear = 2030;
    const int currentYear = 2022;

    class Date : public Status
    {
    private:
        int Year;
        int Month;
        int Day;
        Status State;
        bool validate();
        int uniqDateValue();
        const Status& state() const;
    protected:
        bool Formatted;
    public:
        void setEmpty();
        Date();
        Date(int year, int month, int day);
        bool operator== (Date& date);
        bool operator!= (Date& date);
        bool operator> (Date& date);
        bool operator< (Date& date);
        bool operator>= (Date& date);
        bool operator<= (Date& date);
        Date& formatted(bool valid);
        operator bool() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        ~Date();
    };
    std::ostream& operator<< (std::ostream& os, const Date& date);
    std::istream& operator>> (std::istream& is, Date& date);
}
#endif
