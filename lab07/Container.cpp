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
#include <cstring>
#include "Container.h"


using namespace std;
namespace sdds
{
	void Container::setEmpty()
	{
		Capacity = 0;
		ContentVolume = 0;
	}

	Container::Container(const char* content, int capacity, int contentVolume)
	{
		if (content == nullptr || (contentVolume > capacity))
		{
			setEmpty();
		}
		else
		{
			clear(capacity, content);
			ContentVolume = contentVolume;
		}
	}

	int Container::capacity()
	{
		return Capacity;
	}

	int Container::volume()
	{
		return ContentVolume;
	}

	int Container::operator+=(int volume)
	{
		int add = 0;
		if (volume + ContentVolume <= Capacity)
		{
			ContentVolume += volume;
			add = volume;
		}
		else
		{
			add = Capacity - ContentVolume;
			ContentVolume = Capacity;
		}
		return add;
	}

	int Container::operator-=(int volume)
	{
		int subtract = 0;
		if (ContentVolume - volume >= 0)
		{
			ContentVolume -= volume;
			subtract = volume;
		}
		else
		{
			subtract = ContentVolume;
			ContentVolume = 0;
		}
		return subtract;
	}

	Container::operator bool()
	{
		bool valid = true;
		if (!Content || (ContentVolume > Capacity))
		{
			valid = false;
		}
		return valid;
	}

	void Container::clear(int capacity, const char* content)
	{
		if (capacity > 0 && content != nullptr && strlen(content) < MAX_LENGTH)
		{
			Capacity = capacity;
			strcpy(Content, content);
		}
	}
	int Container::getInt(const char* prompt, std::istream& is)
	{
		int input = 0;
		char buffer;
		bool valid = false;
		if (prompt)
		{
			cout << prompt;
			do
			{
				is >> input;
				if (is.fail())
				{
					cout << "Invalid Integer, retry: ";
					is.clear();
					is.ignore(1000, '\n');
				}
				else
				{
					is.get(buffer);

					if (buffer != '\n')
					{
						cout << "Enter only an integer, try again: ";
						is.clear();
						is.ignore(1000, '\n');
					}
					else valid = true;
				}
			} while (!valid);
		}
		return input;
	}
	int Container::getInt(std::istream& is, int min, int max, const char* prompt,
		const char* errMes)
	{
		int input = 0;
		bool valid = false;
		input = getInt(prompt, is);
		do
		{
			if (input < min || input > max)
			{
				if (errMes)
				{
					cout << errMes << ", retry: ";
				}
				else
				{
					cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
				}
				is >> input;
			}
			else
			{
				valid = true;
			}
		} while (!valid);
		return input;
	}

	std::ostream& Container::print(std::ostream& os) const
	{
		if (Capacity != 0)
		{
			os << Content << ": (" << ContentVolume << "cc/" << Capacity << ")";
		}
		else
		{
			os << "****: (**cc/***)";
		}
		return os;
	}

	std::istream& Container::read(std::istream& is)
	{
		int add;
		if (Capacity != 0)
		{
			cout << "Add to ";
			print(cout);
			add = getInt(is, 1, 999, "\n> ");
			add = (*this += add);
			cout << "Added " << add << " CCs" << endl;
		}
		else
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.clear();
			is.ignore(1000, '\n');
		}
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Container& container)
	{
		return container.print(os);
	}
	std::istream& operator>>(std::istream& is, Container& container)
	{
		return container.read(is);
	}
}