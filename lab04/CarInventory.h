// Workshop 4 part 1
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-08
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

#ifndef NAMESPACE_CARINVENTORY_H
#define NAMESPACE_CARINVENTORY_H

namespace sdds
{
	class CarInventory
	{
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();

	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
		~CarInventory();
	};

	bool find_similar(CarInventory car[], const int num_cars);
}

#endif