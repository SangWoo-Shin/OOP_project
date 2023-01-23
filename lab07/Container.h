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


#ifndef CONTAINER_H
#define CONTAINER_H
namespace sdds
{
	const int MAX_LENGTH = 50;

	class Container
	{
	private:
		char Content[50]{'\0'};
		int Capacity;
		int ContentVolume;
	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		Container(const char* content, int capacity, int contentVolume = 0);
		int operator+=(int volume);
		int operator-=(int volume);
		operator bool();
		void clear(int capacity, const char* content);
		int getInt(const char* prompt, std::istream& is);
		int getInt(std::istream& is, int min, int max, const char* prompt, const char* errMes = nullptr);
		std::ostream& print(std::ostream& os) const; 
		std::istream& read(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const Container& container);
	std::istream& operator>>(std::istream& is, Container& container);

}
#endif //CONTAINER_H