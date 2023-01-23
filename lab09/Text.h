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
#ifndef TEXT_H
#define TEXT_H

namespace sdds
{
	class Text
	{
	private:
		char* m_content{ nullptr };
		int getFileLength(std::istream& is);
	protected:
		const char& operator[](int index) const;
	public:
		Text(const char* content = nullptr);
		Text(const Text& text);
		Text& operator=(const Text& text);
		std::istream& read(std::istream& is);
		virtual std::ostream& write(std::ostream& os) const;
		virtual ~Text();
	};
	std::istream& operator >> (std::istream& is, Text& text);
	std::ostream& operator << (std::ostream& os, const Text& text);

}

#endif //TEXT_H