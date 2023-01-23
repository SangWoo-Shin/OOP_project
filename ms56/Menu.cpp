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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"


using namespace std;
namespace sdds
{
	void Menu::setEmpty()
	{
		numOfOption = 0;
		menuContent = nullptr;
	}

	Menu::Menu(int num, const char* menu)
	{
		setEmpty();
		if (num >= 0 && num <= MAX_MENU && menu != nullptr)
		{
			numOfOption = num;
			menuContent = new char[strlen(menu) + 1];
			strcpy(menuContent, menu);
		}
	}

	int Menu::run() const
	{
		int input = 0;
		cout << menuContent;
		cout << "0- Exit" << endl;
		input = ut.getInt(0, numOfOption, "> ");
		return input;
	}
	const char* Menu::getMenuContent()
	{
		return menuContent;
	}
	int Menu::getNumOfOpt()
	{
		return numOfOption;
	}

	Menu& Menu::operator= (int num)
	{
		if (num >= 0 && num <= MAX_MENU)
		{
			numOfOption = num;
		}
		return *this;
	}

	Menu& Menu::operator = (const char* menu)
	{
		if (menu)
		{
			delete[] menuContent;
			menuContent = new char[strlen(menu) + 1];
			strcpy(menuContent, menu);
		}
		return *this;
	}

	Menu& Menu::clear()
	{
		if (menuContent)
		{
			delete[] menuContent;
			menuContent = nullptr;
		}
		numOfOption = 0;
		return *this;
	}
}