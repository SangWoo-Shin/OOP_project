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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	const int sdds_testYear = 2022;
	const int sdds_testMon = 03;
	const int sdds_testDay = 31;
	class Utils {
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		int getInt(const char* prompt = nullptr);
		int getInt(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
		void extractChar(std::istream& istr, char ch) const;
		int strnCmp(const char* s1, const char* s2, int len);
		const char* strStr(const char* str, const char* find);
	};

	extern Utils ut;
}

#endif // !SDDS_UTILS_H
