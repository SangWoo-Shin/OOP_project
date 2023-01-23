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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Pack.h"
using namespace std;
namespace sdds
{
	void Pack::setEmpty()
	{
		Size = 0;
		unitSize = 0;
		numOfUnits = 0;
	}

	Pack::Pack(const char* _content, int _size, int _unitSize, int _numOfUnits)
		:Container(_content, _size*_unitSize, _numOfUnits*_unitSize)
	{
		if (_unitSize > 0)
		{
			strcpy(Content, _content);
			Size = _size;
			unitSize = _unitSize;
			numOfUnits = _numOfUnits;
		}
		else
		{
			Container::setEmpty();
			setEmpty();
		}
	}

	int Pack::operator+=(int add)
	{
		int result = Container::operator+=(add * unitSize) / unitSize;
		int sum = numOfUnits + result;
		if (sum <= unitSize)
		{
			numOfUnits += result;
		}
		else
		{
			numOfUnits = unitSize;
			result = unitSize - result;
		}
		return result;
	}
	int Pack::operator-=(int subtract)
	{
		int result = Container::operator-=(subtract * unitSize) / unitSize;
		int sum = numOfUnits - result;
		if (sum <= 0)
		{
			result += sum;
			numOfUnits -= result;
		}
		else 
		{
			numOfUnits -= result;
		}
		return result;
	}
	int Pack::unit()
	{
		return unitSize;
	}
	int Pack::noOfUnits()
	{
		return numOfUnits;
	}
	int Pack::size()
	{
		return Size;
	}
	void Pack::clear(int _size, int _unitSize, const char* _content)
	{
		if (unitSize > 0) 
		{
			Container::clear(_size * _unitSize, _content);
			Size = _size;
			unitSize = _unitSize;
			numOfUnits = 0;
		}
	}
	std::ostream& Pack::print(std::ostream& os)
	{
		Container::print(os);
		if (unitSize != 0)
		{
			os << ", " << numOfUnits << " in a pack of " << Size;
		}
		return os;
	}
	std::istream& Pack::read(std::istream& is)
	{
		int input;
		if (numOfUnits == Size)
		{
			is.ignore();
			cout << "Pack is full!, press <ENTER> to continue..." << endl;
		}
		else if (numOfUnits < Size)
		{
			cout << "Add to ";
			print(cout);
			int max = Size - numOfUnits;
			input = Container::getInt(is, 1, max, "\n> ");
			input = (*this += input);
			cout << "Added " << input << endl;
		}
		else
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.ignore();
		}
		return is;
	}
	std::ostream& operator<< (std::ostream& os, Pack& pack)
	{
		return pack.print(os);
	}
	std::istream& operator>> (std::istream& is, Pack& pack)
	{
		return pack.read(is);
	}
}