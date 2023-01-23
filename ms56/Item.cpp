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
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{

	Item::Item() : iProduct()
	{
		Price = 0;
		Quantity = 0;
		neededQty = 0;
		Description = nullptr;
		state = nullptr;
		flag = false;
	}
	int Item::getSKU() const
	{
		return unitNum;
	}
	int Item::readSku(std::istream& is)
	{
		unitNum = ut.getInt(40000, 99999, "SKU: ", "Value out of range");
		return unitNum;
	}
	void Item::linear(bool valid)
	{
		flag = valid;
	}
	bool Item::getLinear()
	{
		return flag;
	}
	int Item::qtyNeeded() const
	{
		return this->neededQty;
	}
	int Item::qty() const
	{
		return this->Quantity;
	}
	Item::operator double() const
	{
		return Price;
	}
	Item::operator bool() const
	{
		bool valid = false;
		if (state == nullptr)
		{
			valid = true;
		}
		return valid;
	}
	int Item::operator-=(int value)
	{
		return this->Quantity -= value;
	}
	int Item::operator+=(int value)
	{
		return this->Quantity += value;
	}
	void Item::linearModi()
	{
		if (flag == false)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}
	bool Item::operator==(int sku)const
	{
		bool valid = false;
		if (unitNum == sku)
		{
			valid = true;
		}
		return valid;
	}
	bool Item::operator==(const char* description)const
	{
		bool valid = false;
		if (ut.strStr(Description, description) != nullptr)
		{
			valid = true;
		}
		return valid;
	}
	std::ofstream& Item::save(std::ofstream& ofstr)const
	{
		if ((int)state == 0)
		{
			ofstr << unitNum << "\t" << Description << "\t" << Quantity
				<< "\t" << neededQty << "\t" << Price;
		}

		return ofstr;
	}
	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		int sku;
		int qty;
		int qtyneeded;
		double price;
		delete[] Description;
		char descr[400];
		if (ifstr.fail())
		{
			cout << "Input file stream read failed!" << endl;
		}
		else if (!ifstr.eof())
		{
			ifstr >> sku;
			ut.extractChar(ifstr, '\t');
			ifstr.get(descr, 400, '\t');
			ut.extractChar(ifstr, '\t');
			ifstr >> qty;
			ut.extractChar(ifstr, '\t');
			ifstr >> qtyneeded;
			ut.extractChar(ifstr, '\t');
			ifstr >> price;
			Description = new char[strlen(descr) + 1];
			strcpy(Description, descr);
			unitNum = sku;
			neededQty = qtyneeded;
			Quantity = qty;
			Price = price;
		}
		return ifstr;
	}
	std::ostream& Item::display(std::ostream& ostr)const
	{
		if (flag == true)
		{
			ostr << setw(5) << unitNum << " | " << left;
			if (strlen(Description) > 35)
			{
				for (int i = 0; i < 35; i++)
					ostr << left << Description[i];
			}
			else
			{
				ostr << left << setw(35);
				ostr.fill(' ');
				ostr << Description;
			}
			ostr << " |" << right << setw(5);
			ostr.fill(' ');
			ostr << Quantity << " |";
			ostr.fill(' ');
			ostr << setw(5);
			ostr.fill(' ');
			ostr << neededQty << " |";
			ostr << setw(8);
			ostr.fill(' ');
			ostr << fixed << setprecision(2) << Price << " |";
		}
		else
		{
			ostr << "AMA Item:" << endl;
			ostr << unitNum << ": " << Description << endl;
			ostr << "Quantity Needed: " << neededQty << endl;
			ostr << "Quantity Available: " << Quantity << endl;
			ostr << "Unit Price: $" << Price << endl;
			double needToBuy = Price * (neededQty - Quantity);
			ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << needToBuy << endl;
		}
		return ostr;
	}
	std::istream& Item::read(std::istream& istr)
	{
		char descr[35];
		int flag = 1;
		double price;

		state.clear();
		cout << "AMA Item:" << endl;
		cout << "SKU: " << unitNum << endl;
		cout << "Description: ";
		istr.get(descr, 35, '\n');
		if (strlen(descr) > 35)
		{
			cout << "Console entry failed!" << endl;
		}
		delete[] Description;
		Description = new char[strlen(descr) + 1];
		strcpy(Description, descr);
		neededQty = ut.getInt(1, 9999, "Quantity Needed: ", "Value out of range ");
		Quantity = ut.getInt(0, neededQty, "Quantity On Hand: ", "Value out of range ");
		cout << "Unit Price: $";
		while (flag)
		{
			istr >> price;
			if (price > 9999.0 || price < 0.0)
			{
				cout << "Value out of range [0.00<=val<=9999.00]: ";
			}
			else if (istr.fail())
			{
				cout << "Invalid number, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (price <= 9999.0 && price >= 0.0)
			{
				flag = 0;
				Price = price;
			}
		}

		return istr;
	}
	void Item::clear()
	{
		Price = 0;
		Quantity = 0;
		neededQty = 0;
		state = "This object is in a good state!";
	}
	Item::~Item()
	{
		delete[] Description;
	}
}