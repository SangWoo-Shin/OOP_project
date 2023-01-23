/* ------------------------------------------------------
Workshop 2 part 1
ID: 119294213
Email: sshin36@myseneca.ca
Author	SangWoo Shin
Section: NCC
-----------------------------------------------------------
Date 2022/01/26     Reason
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef NAMCESPACE_CAR_H 
#define NAMESPACE_CAR_H

struct Car
{
    char licensePlate[9];
    char* makeAndModel;
    int time;
};

namespace sdds
{
    void VBPLE_Title(void);
    void initialize(int allocSize);
    void deallocate(Car& C);
    bool read(Car& C);
    void print(const Car& C);
    void record(const Car& C);
    void endOfDay(void);
}

#endif