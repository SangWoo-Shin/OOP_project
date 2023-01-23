// Workshop 5 part 2
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-18
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }
    Portfolio::operator const char* () const
    {
        return m_stock;
    }
    Portfolio::operator char() const
    {
        return m_type;
    }
    Portfolio::operator bool() const
    {
        bool valid = false;
        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            valid = true;
        }
        return valid;
    }
    bool Portfolio::operator~() const
    {
        bool valid = false;
        if (m_value < 0)
        {
            valid = true;
        }
        return valid;
    }
    Portfolio& Portfolio::operator+=(double value)
    {
        if ((*this) && value > 0)
        {
            m_value = m_value + value;
        }
        return *this;
    }
    Portfolio& Portfolio::operator-=(double value)
    {
        if ((*this) && value > 0)
        {
            m_value = m_value - value;
        }
        return *this;
    }
    Portfolio& Portfolio::operator<< (Portfolio& portfolio)
    {
        m_value = m_value + portfolio.m_value;
        portfolio.emptyPortfolio();
        return *this;
    }
    Portfolio& Portfolio::operator>> (Portfolio& portfolio)
    {
        portfolio.m_value = portfolio.m_value + m_value;
        this->emptyPortfolio();
        return *this;
    }
    double operator+ (const Portfolio& left, const Portfolio& right)
    {
        double sum = 0;
        if ((left) && (right))
        {
            sum = left.m_value + right.m_value;
        }
        return sum;
    }
    double operator+= (double& value, const Portfolio& portfolio)
    {
        value = portfolio.m_value + value;
        return value;
    }

}