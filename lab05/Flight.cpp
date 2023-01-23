 // Workshop 5 part 1
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-16
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    Flight::operator bool() const
    {
        bool valid = false;
        if (m_passengers > 0 && m_fuel > (m_passengers * 600))
        {
            valid = true;
        }
        return valid;
    }

    Flight::operator int() const
    {
        return m_passengers;
    }

    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator const char*() const
    {
        return m_title;
    }
    bool Flight::operator~ () const
    {
        bool valid = false;
        if (m_passengers == 0)
        {
            valid = true;
        }
        return valid;
    }

    Flight& Flight::operator+= (double fuel)
    {
        if (m_fuel > 0 && m_fuel < FuelTankCapacity)
        {
            m_fuel = m_fuel + fuel;
            if (m_fuel > FuelTankCapacity)
            {
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator+= (int passenger)
    {
        if (m_passengers > 0 && m_passengers < Boen747Capacity)
        {
            m_passengers = m_passengers + passenger;
            if (m_passengers > Boen747Capacity)
            {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator-= (double fuel)
    {
        if (fuel > 0 && m_fuel > 0)
        {
            m_fuel = m_fuel - fuel;
            if (m_fuel < 0)
            {
                m_fuel = 0;
            }
        }
        return *this;
    }
    Flight& Flight::operator-= (int passenger)
    {
        if (passenger > 0 && m_passengers > 0)
        {
            m_passengers = m_passengers - passenger;
            if (m_passengers < 0)
            {
                m_passengers = 0;
            }
        }
        return *this;
    }
    Flight& Flight::operator<< (Flight& flight)
    {
        if (m_passengers > 0 && m_passengers < Boen747Capacity &&
            int(flight.m_passengers) && int(m_passengers))
        {
            m_passengers = m_passengers + flight.m_passengers;
            if (m_passengers > Boen747Capacity)
            {
                flight.m_passengers -= (m_passengers - Boen747Capacity);
                m_passengers = Boen747Capacity;
            }
            else
            {
                flight.m_passengers = 0;
            }
        }
        return *this;
    }
    Flight& Flight::operator>> (Flight& flight)
    {
        if (m_passengers > 0 && m_passengers < Boen747Capacity &&
            int(flight.m_passengers) && int(m_passengers))
        {
            flight.m_passengers = m_passengers + flight.m_passengers;
            if (flight.m_passengers > Boen747Capacity)
            {
                m_passengers = (flight.m_passengers - Boen747Capacity);
                flight.m_passengers = Boen747Capacity;
            }
            else
            {
                m_passengers = 0;
            }
        }
        return *this;
    }
    int Flight::operator+ (Flight& flight)
    {
        int result = 0;
        if (int(m_passengers) && int(flight.m_passengers))
        {
            result = m_passengers + flight.m_passengers;
        }
        return result;
    }
    int operator+= (int& value, const Flight& flight)
    {
        if (flight.m_passengers > 0)
        {
            value = value + flight.m_passengers;
        }    
        return value;
    }
    Flight& Flight::operator= (int passenger)
    {
        m_passengers = passenger;
        return *this;
    }
    Flight& Flight::operator= (double fuel)
    {
        m_fuel = fuel;
        return *this;
    }
    Flight& Flight::operator= (Flight& flight)
    {
        m_passengers = flight.m_passengers;
        m_fuel = flight.m_fuel;
        strcpy(m_title, flight.m_title);
        flight.emptyPlane();
        return *this;
    }
}
