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
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Perishable.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Perishable::Perishable(char* handle) : Item()
	{
		Handle = nullptr;
		if (handle)
		{
			Handle = new char[strlen(handle) + 1];
			strcpy(Handle, handle);
		}
	}
	int Perishable::getSKU() const
	{
		int sku;
		sku = Item::getSKU();
		return sku;
	}
	const Date& Perishable::expiry() const
	{
		return expiryDate;
	}
	int Perishable::readSku(std::istream& is)
	{
		unitNum = ut.getInt(10000, 39999, "SKU: ", "Value out of range ");
		return unitNum;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr)const
	{
		Date date;
		date = expiryDate;
		if ((int)state == 0)
		{
			Item::save(ofstr);
			if (Handle != nullptr)
			{
				ofstr << '\t' << Handle << '\t' << date.formatted(false);
			}
			else
			{
				ofstr << '\t' << '\t' << date.formatted(false);
			}
		}

		return ofstr;
	}
	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		char handle[100];
		delete[] Handle;
		if (!ifstr.eof())
		{
			if (Item::load(ifstr))
			{
				if (ifstr.peek() == '\n')
				{
					ifstr.ignore();
					Handle = nullptr;
					expiryDate.setEmpty();
				}
				else if (ifstr.peek() == '\t')
				{
					ut.extractChar(ifstr, '\t');
					if (ifstr.peek() == '\t')
					{
						ut.extractChar(ifstr, '\t');
						Handle = nullptr;
						expiryDate.read(ifstr);
					}
					else
					{
						ifstr.get(handle, 100, '\t');
						Handle = new char[strlen(handle) + 1];
						strcpy(Handle, handle);
						expiryDate.read(ifstr);
					}
				}
			}
			else
			{
				Handle = nullptr;
			}
		}
		else
		{
			state = "Input file stream read (perishable) failed!";
		}
		return ifstr;
	}
	std::istream& Perishable::read(std::istream& istr)
	{
		char handle[100];
		Item::read(istr);
		delete[] Handle;
		Handle = nullptr;
		cout << "Expiry date (YYMMDD): ";
		expiryDate.read(istr);
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() == '\n')
		{
			Handle = nullptr;
		}
		else if (istr.fail() && istr.peek() != '\n')
		{
			cout << "Perishable console date entry failed!" << endl;
		}
		else
		{
			istr.get(handle, 35, '\n');
			Handle = new char[strlen(handle) + 1];
			strcpy(Handle, handle);
		}

		return istr;
	}
	std::ostream& Perishable::display(std::ostream& ostr)const
	{
		if ((int)state != 0)
		{
			ostr << state;
		}
		else if (flag)
		{
			Item::display(ostr);
			if (Handle != nullptr)
			{
				ostr << "*" << expiryDate;
			}
			else
			{
				ostr << " " << expiryDate;
			}
			return ostr;
		}
		else
		{
			ostr << "Perishable ";
			Item::display(ostr);
			ostr << "Expiry date: " << expiryDate << endl;
			if (Handle != nullptr)
			{
				ostr << "Handling Instructions: " << Handle << endl;
			}
		}
		return ostr;
	}
	Perishable::~Perishable()
	{
		if (Handle)
		{
			delete[] Handle;
			Handle = nullptr;
		}
	}
}