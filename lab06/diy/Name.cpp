/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Sangwoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca,ca
	Section: NCC
	Date   : Mar 05, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Name.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	void Name::setEmpty()
	{
		firstName = nullptr;
		lastName = nullptr;
		middleName = nullptr;
	}
	void Name::set(const char* f_Name, const char* m_Name, const char* l_Name)
	{
		if (f_Name == nullptr && m_Name == nullptr && l_Name == nullptr)
		{
			delete[] firstName;
			delete[] lastName;
			delete[] middleName;
			setEmpty();
		}
		else
		{
			allocateAndCopy(f_Name, 0);
			if (m_Name != nullptr)
			{
				allocateAndCopy(m_Name, 1);
			}
			if (l_Name != nullptr)
			{
				allocateAndCopy(l_Name, 2);
			}
		}
	}
	void Name::allocateAndCopy(const char* name, int flag)
	{
		if (flag == 0)
		{
			delete[] firstName;
			firstName = new char[strlen(name) + 1];
			strcpy(firstName, name);
		}
		else if (flag == 1)
		{
			delete[] middleName;
			middleName = new char[strlen(name) + 1];
			strcpy(middleName, name);
		}
		else if(flag == 2)
		{
			delete[] lastName;
			lastName = new char[strlen(name) + 1];
			strcpy(lastName, name);
		}
	}
	Name::Name(const char* f_Name, const char* m_Name, const char* l_Name)
	{
		set(f_Name, m_Name, l_Name);
	}
	Name::Name(const Name& name)
	{
		if (name)
		{
			set(name.firstName, name.middleName, name.lastName);
		}
	}
	Name& Name::operator= (const Name& name)
	{
		if (this != &name)
		{
			set(name.firstName, name.middleName, name.lastName);
		}
		return *this;
	}

	Name& Name::setShort(bool valid)
	{
		char s_middle[3] = {};
		if (middleName)
		{
			if (valid)
			{
				s_middle[0] = middleName[0];
				s_middle[1] = '.';
				allocateAndCopy(s_middle, 1);
			}
		}
		return *this;
	}	
	Name& Name::operator +=(const char str[])
	{
		int flag = 1;
		int max = strlen(str);
		if (firstName != nullptr && middleName != nullptr && lastName != nullptr)
		{
			delete[] firstName;
			delete[] lastName;
			delete[] middleName;
			setEmpty();
		}
		else if (strlen(str) != 0)
		{
			for (int i = 0; i < max; i++)
			{
				if (str[i] == ' ')
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				if (firstName == nullptr)
				{
					allocateAndCopy(str, 0);
				}
				else if (middleName == nullptr)
				{																								
					allocateAndCopy(str, 1);
				}
				else if (lastName == nullptr)
				{
					allocateAndCopy(str, 2);
				}
			}
		}
		return *this;
	}

	std::istream& Name::read(std::istream& is)
	{
		int count = 0;
		char fullName[60] = {};
		char Name_1[20] = {};
		char Name_2[20] = {};
		char Name_3[20] = {};
		int j = 0;
		int k = 0;
		
		delete[] firstName;
		firstName = nullptr;				
		delete[] middleName;
		middleName = nullptr;
		delete[] lastName;
		lastName = nullptr;
		
		is.get(fullName, 60, '\n');
		int max = strlen(fullName);
		for (int i = 0; i < max; i++)
		{
			if (count == 0 && fullName[i] != ' ')
			{
				Name_1[i] = fullName[i];
			}
			if (count == 1 && fullName[i] != ' ')
			{
				Name_2[j] = fullName[i];
				j++;
			}
			if (count == 2 && fullName[i] != ' ')
			{
				Name_3[k] = fullName[i];
				k++;
			}
			if (fullName[i] == ' ')
			{
				count++;
			}
		}

		if (count <= 2)
		{
			if (count == 0)
			{
				set(Name_1);
			}
			else if (count == 1)
			{
				set(Name_1, nullptr, Name_2);
			}
			else if (count == 2)
			{
				set(Name_1, Name_2, Name_3);
			}
			is.ignore(1000, '\n');
		}
		return is;
	}
	std::ostream& Name::print(std::ostream& os) const
	{
		os << firstName;
		if (middleName)
		{
			os << " " << middleName;	
		}
		if (lastName)
		{
			os << " " << lastName;
		}

		return os;
	}
	Name::operator bool() const
	{
		bool valid = false;
		if (firstName != nullptr)
		{
			valid = true;
		}
		return valid;
	}
	Name::~Name()
	{
		delete[] firstName;
		delete[] lastName;
		delete[] middleName;
		firstName = nullptr;
		lastName = nullptr;
		middleName = nullptr;
	}
	std::ostream& operator << (std::ostream& os, const Name& name)
	{
		if (name)
		{
			name.print(os);
		}
		else
		{
			os << "Bad Name";
		}
		return os;
	}
	std::istream& operator >> (std::istream& is, Name& name)
	{		
		return name.read(is);
	}
}