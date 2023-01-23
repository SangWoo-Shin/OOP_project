// Workshop 4 part 2
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-08
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

#ifndef NAMESPACE_ROBOT_H
#define NAMESPACE_ROBOT_H

namespace sdds
{
	class Robot
	{
	private:
		char* Name;
		char* Location;
		double Weight;
		double Width;
		double Height;
		double Speed;
		bool Deployed;
	public:
		void resetInfo();
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		~Robot();
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		Robot& setLocation(const char*);
		Robot& setDeployed(bool status);
		char* getName() const;
		char* getLocation() const;
		bool isValid() const;
		bool isDeployed() const;
		double speed() const;
		void display() const;
		
	};

	int conrtolRooomReport(const Robot robot[], int num_robots);	
}

#endif