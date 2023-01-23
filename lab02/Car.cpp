/* ------------------------------------------------------
Workshop 2 part 1
ID: 119294213
Email: sshin36@myseneca.ca
Author	SangWoo Shin
Section: NCC
-----------------------------------------------------------
Date 2022/01/26      Reason
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"
#include "cStrTools.h"


using namespace std;

namespace sdds
{

    Car* car;
    int allocationSize;
    int numOfCars;
    int carArraySize;

    void VBPLE_Title(void)
    {
        cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:"
            << endl << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl
            << "Exit the program by entering the following:" << endl << "X,<ENTER>" << endl;
    }
    void initialize(int allocSize)
    {
        numOfCars = 0;
        carArraySize = allocSize;
        allocationSize = allocSize;
        car = new Car[allocationSize];
    }

    void deallocate(Car& C)
    {
        delete[] C.makeAndModel;
        C.makeAndModel = nullptr;
    }

    bool read(Car& C)
    {
        bool flag = false;
        int time = 0;
        char model[60] = { 0 };
        char LicensePlate[9] = { 0 };
        read(model, 60, ',');
        if (strCmp(model, "X") != 0)
        {
            flag = true;
            C.makeAndModel = new char[strLen(model)+1];
            strCpy(C.makeAndModel, model);

            read(LicensePlate, 8, ',');
            strCpy(C.licensePlate, LicensePlate);

            cin >> time;
            C.time = time;
        }
        return flag;
    }

    void print(const Car& C)
    {
        cout << C.time << ": " << C.makeAndModel << "," << C.licensePlate << endl;
    }

    void record(const Car& C)
    {
        Car* temCar = { 0 };
        if(numOfCars == carArraySize)
        {           
            carArraySize += allocationSize;
            temCar = new Car[carArraySize];
            for (int i = 0; i < numOfCars; i++)
            {
                temCar[i] = car[i];
            } 
            delete[] car;
            car = temCar;
            temCar = nullptr;
        }  
        car[numOfCars] = C;
        numOfCars++;       
    }

    void endOfDay(void)
    {
        for (int i = 0; i < numOfCars; i++)
        {
            print(car[i]);
            deallocate(car[i]); 
        }
        delete[] car;
        car = nullptr;
    }
}