 /*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Sangwoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca,ca
	Section: NCC
	Date   : Mar 02, 2022 
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
#include <iomanip>
using namespace std;
namespace sdds {

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{		
		return name != nullptr && name[0] != 0 && number > 999999999 && number < 9999999999	&& vCode[1] && sNumber[8];
	}
	void HealthCard::setEmpty()
	{
		m_name = nullptr;
	}
	void HealthCard::allocateAndCopy(const char* name)
	{
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}
	void HealthCard::extractChar(std::istream& istr, char ch) const
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
	std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}
	HealthCard::HealthCard(const char* name, long long number, const char code[], const char sNumber[])
	{
		set(name, number, code, sNumber);
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this != &hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}
	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else
		{
			delete[] m_name;
			setEmpty();
		}
	}
	HealthCard::operator bool() const
	{
		bool valid = false;
		if (m_name != nullptr)
		{
			valid = true;
		}
		return valid;
	}
	HealthCard::~HealthCard()
	{
		delete[] m_name;
		m_name = nullptr;
	}
	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const
	{
		if (toFile)
		{
			if (*this)
			{
				ostr << m_name << ",";
				printIDInfo(ostr) << endl;
			}
		}
		else
		{
			ostr.width(50);
			ostr.fill('.');
			ostr << left << m_name;
			printIDInfo(ostr);
		}
		return ostr;
	}
	std::istream& HealthCard::read(istream& istr)
	{
		char name[MaxNameLength];
		long long number;
		char vCode[3];
		char sNumber[10];

		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');

		if (!istr.fail())
		{
			set(name, number, vCode, sNumber);
		}
		else
		{
			extractChar(istr, '\n');
		}
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
	{
		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, HealthCard& hc)
	{
		return hc.read(istr);
	}
}
