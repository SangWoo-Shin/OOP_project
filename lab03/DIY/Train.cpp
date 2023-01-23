// Workshop3 part 2
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include"Train.h"

using namespace std;
namespace sdds
{

	void Train::set(const char* name, int people, double speed)
	{
		if (name != nullptr && strlen(name) <= MAX_NAME_LEN && strlen(name) > 0
			&& people <= MAX_PEOPLE && people >= 0 && speed <= MAX_SPEED && speed >= 0)
		{
			strncpy(nameOfTrain, name, strlen(name) + 1);
			numOfPeople = people;
			speedOFTrain = speed;
		}
		else
		{
			strcpy(nameOfTrain, "empty train"); // Set an empty state
		}
	}
	int Train::getNumberOfPeople(void) const
	{
		return numOfPeople;
	}
	const char* Train::getName(void) const
	{
		return nameOfTrain;
	}
	double Train::getSpeed(void) const
	{
		return speedOFTrain;
	}
	bool Train::isSafeEmpty(void) const
	{
		bool valid = false;
		if (strcmp(nameOfTrain, "empty train") == 0)
		{
			valid = true;
		}
		return valid;
	}
	void Train::display(void) const
	{
		if (strcmp(nameOfTrain, "empty train") != 0)
		{
			cout << "NAME OF THE TRAIN : " << getName() << endl
				<< "NUMBER OF PEOPLE  : " << getNumberOfPeople() << fixed << setprecision(2) << endl
				<< "SPEED             : " << getSpeed() << " km/h" << endl;
		}
		else
		{
			cout << "Safe Empty State!" << endl;
		}
	}
	bool Train::loadPeople(int change)
	{
		bool valid = false;
		if (strcmp(nameOfTrain, "empty train") != 0)
		{
			if ((numOfPeople + change) < 0)
			{
				numOfPeople = 0;
				valid = true;
			}
			else if ((numOfPeople + change) > MAX_PEOPLE)
			{
				numOfPeople = MAX_PEOPLE;
				valid = true;
			}
			else
			{
				numOfPeople += change;
				valid = true;
			}
		}
		return valid;
	}

	bool Train::changeSpeed(int change)
	{
		bool valid = false;
		if (strcmp(nameOfTrain, "empty train") != 0)
		{
			if ((speedOFTrain + change) < 0)
			{
				speedOFTrain = 0.00;
				valid = true;
			}
			else if ((speedOFTrain + change) > MAX_SPEED)
			{
				speedOFTrain = MAX_SPEED;
				valid = true;
			}
			else
			{
				speedOFTrain += change;
				valid = true;
			}
		}
		return valid;
	}

	int transfer(Train& firstTrain, Train& secondTrain)
	{
		int result = 0;
		int firstPeople = 0;
		int secondPeople = 0;

		firstPeople = firstTrain.getNumberOfPeople();
		secondPeople = secondTrain.getNumberOfPeople();

		if (firstTrain.isSafeEmpty() == false && secondTrain.isSafeEmpty() == false)
		{
			if (MAX_PEOPLE - firstPeople >= secondPeople)
			{
				firstTrain.loadPeople(secondPeople);
				secondTrain.loadPeople(-1 * secondPeople);
				result = secondPeople;
			}
			else if (MAX_PEOPLE - firstPeople < secondPeople)
			{
				firstTrain.loadPeople(MAX_PEOPLE - firstPeople);
				secondTrain.loadPeople(-1 * (MAX_PEOPLE - firstPeople));
				result = MAX_PEOPLE - firstPeople;
			}
		}
		else
		{
			result = -1;
		}
		return result;
	}
}
