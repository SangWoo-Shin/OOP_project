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

#include "Utils.h"

#ifndef MENU_H
#define MENU_H
namespace sdds
{
	const int MAX_MENU = 15;

	class Menu : public Utils
	{
	private:
		int numOfOption;
	protected:
		char* menuContent;
	public:
		void setEmpty();
		Menu(int num = -1, const char* menu = nullptr);
		const char* getMenuContent();
		int getNumOfOpt();
		int run() const;
		Menu& operator = (int num);
		Menu& operator = (const char* menu);
		Menu& clear();
	};
}

#endif //MENU_H