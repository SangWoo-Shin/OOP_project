/*
	==================================================
	Mile Stone 4
	==================================================
	Name   : Sangwoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca,ca
	Section: NCC
	Date   : 2022/03/31
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct
	{
	private:
		double Price;
		int Quantity;
		int neededQty;
		char* Description;
	protected:
		Status state;
		bool flag;
		int unitNum;
		void linear(bool valid);
		bool getLinear();
	public:
		Item();
		virtual int readSku(std::istream& is);
		int qtyNeeded() const;
		int qty() const;
		operator double() const;
		operator bool() const;
		int operator-=(int value);
		int operator+=(int value);
		void linearModi();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		virtual std::ofstream& save(std::ofstream& ofstr)const;
		virtual std::ifstream& load(std::ifstream& ifstr);
		virtual std::ostream& display(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		void clear();
		virtual ~Item();
	};

}

#endif//ITEM_H