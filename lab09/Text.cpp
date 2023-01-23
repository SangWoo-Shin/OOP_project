/*
	==================================================
	WorkShop 9
	==================================================
	Name   : Sangwoo Shin
	ID     : 119294213
	Email  : sshin36@myseneca,ca
	Section: NCC
	Date   : 2022/03/29
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Text.h"

using namespace std;
namespace sdds
{
	Text::Text(const char* content)
	{
		m_content = nullptr;
	}
	const char& Text::operator[](int index) const
	{
		if (m_content) 
		{
			int len = strlen(m_content);
			if (index < len)
			{
				return m_content[index];
			}
		}
		return m_content[index];
	}
	Text::Text(const Text& text)
	{
		*this = text;
	}

	Text& Text::operator=(const Text& text) 
	{
		if (this != &text)
		{
			if (m_content) delete[] m_content;

			if (text.m_content)
			{
				m_content = new char[strlen(text.m_content) + 1];
				strcpy(m_content, text.m_content);
			}
			else 
			{
				m_content = nullptr;
			}
		}

		return *this;
	}
	std::istream& Text::read(std::istream& is)
	{
		delete[] m_content;
		m_content = new char[getFileLength(is) + 1];
		int len = getFileLength(is) + 1;
		is.get(m_content, len, EOF);

 		return is;
	}
	std::ostream& Text::write(std::ostream& os) const
	{
		if (m_content)
		{
			os << m_content;
		}
		return os;
	}
	int Text:: getFileLength(std::istream& is)
	{
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
	std::istream& operator >> (std::istream& is, Text& text)
	{
		return text.read(is);
	}
	std::ostream& operator << (std::ostream& os, const Text& text)
	{
		return text.write(os);
	}
	Text::~Text()
	{
		if (m_content)
		{
			delete[] m_content;
			m_content = nullptr;
		}
	}
}