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


#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds
{
	class Perishable : public Item
	{
	private:
		Date expiryDate;
		char* Handle;
	public:
		Perishable(char* handle = nullptr);
		const Date& expiry() const;
		int getSKU() const;
		int readSku(std::istream& is);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		~Perishable();
	};
}
#endif //PERISHABLE_H