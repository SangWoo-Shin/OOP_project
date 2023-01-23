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
#ifndef HTMLTEXT_H
#define HTMLTEXT_H
#include "Text.h"

namespace sdds
{
	class HtmlText : public Text
	{
	private:
		char* m_title{ nullptr };
	public:
		HtmlText(const char* title = nullptr);
		HtmlText(const HtmlText& html);
		std::ostream& write(std::ostream& os) const;
		HtmlText& operator=(const HtmlText& html);
		~HtmlText();
	};
}

#endif //HTMLTEXT_H