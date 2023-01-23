// Workshop 4 part 2
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
// Date: 2022-02-08
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#define _CRT_SECURE_NO_WARNINGS
#include "Robot.h"

using namespace std;
namespace sdds
{
	void Robot::resetInfo()
	{
		Name = nullptr;
		Location = nullptr;
		Weight = 0;
		Width = 0;
		Height = 0;
		Speed = 0;
		Deployed = 0;
	}
	Robot::Robot()
	{
		resetInfo();
	}
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		if (name != nullptr && location != nullptr)
		{
			Name = new char[strlen(name) + 1];
			Location = new char[strlen(location) + 1];
			strcpy(Name, name);
			strcpy(Location, location);
			Weight = weight;
			Width = width;
			Height = height;
			Speed = speed;
			Deployed = deployed;
		}
		else
		{
			resetInfo();
		}
	}
	Robot::~Robot()
	{
		delete[] Name;
		delete[] Location;
		Name = nullptr;
		Location = nullptr;
	}
	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		delete[] Name;
		delete[] Location;
		Name = nullptr;
		Location = nullptr;
		Name = new char[strlen(name) + 1];		
		strcpy(Name, name);
		setLocation(location);
		Weight = weight;
		Width = width;
		Height = height;
		Speed = speed;
		setDeployed(deployed);

		return *this;
	}
	Robot& Robot::setLocation(const char* location)
	{
		Location = new char[strlen(location) + 1];
		strcpy(Location, location);
		return *this;
	}
	Robot& Robot::setDeployed(bool status)
	{
		Deployed = status;
		return *this;
	}
	char* Robot::getName() const
	{
		return Name;
	}
	char* Robot::getLocation() const
	{
		return Location;
	}
	bool Robot::isValid() const
	{
		bool valid = true;
		if (Name == nullptr || strcmp(Name, "Broken") == 0)
		{
			valid = false;
		}
		return valid;
	}
	bool Robot::isDeployed() const
	{
		bool deployed = false;
		if (Deployed)
		{
			deployed = true;
		}
		return deployed;
	}
	double Robot::speed() const
	{
		return Speed;
	}
	void Robot::display() const
	{
		const char* deployment = nullptr;
		deployment = isDeployed() ? "YES" : "NO";
		cout << "| " << left << setw(11) << getName() << "| " << setw(16) << getLocation() << "| ";
		cout << fixed;
		cout.precision(1);
		cout << right << setw(6) << Weight << " |" << setw(7) << Width << " | "
		    << setw(6) << Height << " | " << setw(6) << Speed << " | "
			<< left << setw(8) << deployment << " |" << endl;
	}

	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int j = 0;
		int value = 0;
		int count = 0;
		int fastestIndex = 0;
		cout << right << setw(55) << "------ Robot Control Room -----" << endl;
		cout << right << setw(59) << "---------------------------------------" << endl;
		cout << "| " << left << setw(11) << "Robot ID" << "| " << setw(16) << "Location" << "| "
			<< setw(7) << "Weight" << "|" << right << setw(7) << "Width" << " | " << setw(6) << "Height"
			<< " |  " << setw(5) << "Speed" << " | " << setw(8) << "Deployed" << " |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (int i = 0; i < num_robots; i++, j++)
		{
			if (robot[i].isValid())
			{
				value = i;
				robot[i].display();
				if (robot[i].isDeployed())
				{
					count++;
				}
				if (i > 0 && robot[i].speed() > robot[fastestIndex].speed())
				{
					fastestIndex = i;
				}
			}
			else
			{
				value = i;
				i = num_robots;
			}
		}
		if (j == num_robots)
		{
			cout << "|=============================================================================|" << endl;
			cout << "| " << setw(76) << "SUMMARY:" << "|" << endl;
			cout << "| " << setw(3) << count << setw(73) << "robots are deployed." << "|" << endl;
			cout << "| " << setw(76) << "The fastest robot is:" << "|" << endl;
			cout << "| " << left << setw(11) << "Robot ID" << "| " << setw(16) << "Location" << "| "
				<< setw(7) << "Weight" << "|" << right << setw(7) << "Width" << " | " << setw(6) << "Height"
				<< " |  " << setw(5) << "Speed" << " | " << setw(8) << "Deployed" << " |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			robot[fastestIndex].display();
			cout << "|=============================================================================|" << endl;
			value = -1;
		}
		return value;
	}
}