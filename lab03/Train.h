
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>


#ifndef NAMESPACE_TRAIN_H
#define NAMESPACE_TRAIN_H

namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const double MAX_SPEED = 320;

	class Train
	{
	private:
		char nameOfTrain[MAX_NAME_LEN + 1];
		int numOfPeople;
		double speedOFTrain;
	public:
		void set(const char*, int, double);
		int getNumberOfPeople(void) const;
		const char* getName(void) const;
		double getSpeed(void) const;
		bool isSafeEmpty(void) const;
		void display(void) const;
	};
}

#endif
