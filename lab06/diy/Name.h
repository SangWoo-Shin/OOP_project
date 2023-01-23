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

#ifndef NAME_H
#define NAME_H
	namespace sdds
	{
		class Name
		{
		private:
			char* firstName{};
			char* lastName{};
			char* middleName{};
			void setEmpty();
			void set(const char* f_Name, const char* m_Name = nullptr, const char* l_Name = nullptr);
			void allocateAndCopy(const char* name, int flag);
		public:
			Name(const char* f_Name = nullptr, const char* m_Name = nullptr, const char* l_Name = nullptr);
			Name(const Name& name);
			Name& operator= (const Name& name);
			Name& setShort(bool valid);
			Name& operator +=(const char str[]);
			std::istream& read(std::istream& is);
			std::ostream& print(std::ostream& os) const;
			operator bool() const;
			~Name();
		};
		std::ostream& operator <<(std::ostream& os, const Name& name);
		std::istream& operator >>(std::istream& is, Name& name);
	}
#endif