/*
	==================================================
	Work Shop 07
	==================================================
	Name   : Sangwoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca.ca
	Section: NCC
	Date   : 2022/3/17
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef PACK_H
#define PACK_H
#include "Container.h"
namespace sdds
{
	class Pack : public Container
	{
	private:
		char Content[50]{ '\0' };
		int Size;
		int unitSize;
		int numOfUnits;
	public:
		void setEmpty();
		Pack(const char* _content, int _size, int _unitSize = 330, int _numOfUnits = 0);
		int operator+=(int add);
		int operator-=(int subtract);
		int unit();
		int noOfUnits();
		int size();
		void clear(int _size, int _unitSize, const char* _content);
		std::ostream& print(std::ostream& os);
		std::istream& read(std::istream& is);
	};
	std::ostream& operator<< (std::ostream& os, Pack& pack);
	std::istream& operator>> (std::istream& is, Pack& pack);
}
#endif //PACK_H