// Workshop 5 part 2
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-18
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        void emptyPortfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        std::ostream& display() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const; 
        bool operator~() const;
        Portfolio& operator+=(double);
        Portfolio& operator-=(double);
        Portfolio& operator<< (Portfolio& portfolio);
        Portfolio& operator>> (Portfolio& portfolio);
        friend double operator+ (const Portfolio& left, const Portfolio& right);
        friend double operator+= (double& value, const Portfolio& portfolio);
    };
}
#endif // SDDS_Portfolio_H_