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
#include "HtmlText.h"

using namespace std;
namespace sdds
{
	HtmlText::HtmlText(const char* title) : Text()
	{
		if (title)
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& html)
	{
		*this = html;
	}
	HtmlText& HtmlText::operator=(const HtmlText& html)
	{
		if (this != &html)
		{
			(Text&)*this = html;

			if (m_title) delete[] m_title;

			if (html.m_title) {
				m_title = new char[strlen(html.m_title) + 1];
				strcpy(m_title, html.m_title);
			}
			else m_title = nullptr;
		}

		return *this;
	}

	std::ostream& HtmlText::write(std::ostream& os) const
	{
		char temp;
		bool MS = false;
		os << "<html><head><title>";
		m_title != nullptr ? os << m_title : os << "No title";
		os << "</title></head>\n<body>" << endl;

		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>" << endl;
			for (int idx = 0; Text::operator[](idx) != '\0'; idx++)
			{
				temp = Text::operator[](idx);
				switch (temp)
				{
				case ' ':
					if (MS)
					{
						os << "&nbsp;";
					}
					else
					{
						os << temp;
						MS = true;
					}
					break;

				case '<':
					os << "&lt;";
					MS = false;
					break;

				case '>':
					os << "&gt;";
					MS = false;
					break;

				case '\n':
					os << "<br />\n";
					MS = false;
					break;

				default:
					os << temp;
					MS = false;
					break;
				}
			}
		}
		os << "</body>\n</html>";
		return os;
	}
	HtmlText::~HtmlText()
	{
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
	}
}