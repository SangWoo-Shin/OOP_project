// Workshop 4 part 1
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-08
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"

using namespace std;
namespace sdds
{
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.00;
	}
	CarInventory::CarInventory()
	{
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if ((type != nullptr && brand != nullptr && model != nullptr) && year >= 1990 && price > 0 && code >= 100 && code <= 999)
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
	}

	CarInventory::~CarInventory()
	{
		delete[] m_brand;
		delete[] m_model;
		delete[] m_type;
		m_brand = nullptr;
		m_model = nullptr;
		m_type = nullptr;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_brand;
		delete[] m_model;
		delete[] m_type;
		m_brand = nullptr;
		m_model = nullptr;
		m_type = nullptr;
		m_type = new char[strlen(type) + 1];
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		
		return *this;
	}

	void CarInventory::printInfo() const
	{
		cout << "| " << left << setw(11) << m_type << "| " << left << setw(17) << m_brand
			<< "| " << left << setw(17) << m_model << "| " << m_year << " | " << right << setw(4)
			<< m_code << " | ";
		cout << fixed;
		cout.precision(2);
		cout << right << setw(9) << m_price << " |" << endl;
	}

	bool CarInventory::isValid() const
	{
		bool valid = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr
			&& m_year >= 1990 && m_price > 0 && m_code >= 100 && m_code <= 999)
		{
			valid = true;
		}

		return valid;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool valid = false;
		
		if (isValid())
		{
			if (strcmp(m_brand, car.m_brand) == 0 ||
				strcmp(m_model, car.m_model) == 0 ||
				strcmp(m_type, car.m_type) == 0 ||
				m_year == car.m_year)
			{
				valid = true;
			}
		}
		return valid;
	}

	bool find_similar(CarInventory car[], const int num_cars)
	{
		bool valid = false;
		for (int i = 0; i < num_cars; i++) 
		{
			for (int j = i + 1; j < num_cars; j++) 
			{
				if (car[i].isSimilarTo(car[j])) 
				{
					valid = true;
				}
			}
		}
		return valid;
	}
}