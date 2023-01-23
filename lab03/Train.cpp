

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
			strncpy(nameOfTrain, name, strlen(name)+1);
			numOfPeople = people;
			speedOFTrain = speed;
		}
		else
		{
			numOfPeople = 0; // Set an empty state
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
		if (numOfPeople == 0)
		{
			valid = true;
		}
		return valid;
	}
	void Train::display(void) const
	{
		if (numOfPeople != 0)
		{
			cout << "NAME OF THE TRAIN : " << getName() << endl
				<< "NUMBER OF PEOPLE  : " << getNumberOfPeople() << endl
				<< "SPEED             : " << getSpeed() << " km/h" << endl;
		}
		else
		{
			cout << "Safe Empty State!" << endl;
		}
	}
}
