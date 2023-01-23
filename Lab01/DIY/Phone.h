#pragma once
//Workshop1 part2
//Name : Sang Woo, Shin
//Student ID : 119294213
//Email : sshin36@myseneca.ca
//Section Information Code : NCC

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"

const int MAX_NAME_LEN = 50;

#ifndef NAMESPACE_PHONE_H
#define NAMESPACE_PHONE_H

struct profile
{
    char name[MAX_NAME_LEN];
    char area[5];
    char prefix[5];
    char number[5];
};


namespace sdds
{
    void exit(const char* filename);
    int readTextFile(const char* programTitle, const char* filename, FILE* fptr, profile* detail);
    void findPhoneNumber(const char* programTitle, const char* filename, FILE* fptr, profile* detail);
    void phoneDir(const char* programTitle, const char* fileName);
}
#endif