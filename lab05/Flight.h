// Workshop 5 part 1
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-16
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char*() const;
        bool operator~ () const;
        Flight& operator+= (double fuel);
        Flight& operator+= (int passenger);
        Flight& operator-= (double fuel);
        Flight& operator-= (int passenger);
        Flight& operator<< (Flight& flight);
        Flight& operator>> (Flight& flight);
        int operator+ (Flight& flight);
        friend int operator+= (int& value, const Flight& flight);
        Flight& operator= (int passenger);
        Flight& operator= (double fuel);
        Flight& operator= (Flight& flight);
    };

}
#endif // SDDS_FLIGHT_H