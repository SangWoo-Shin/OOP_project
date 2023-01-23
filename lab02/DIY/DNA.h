/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: DNA.h
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date  2022/01/30     Reason
-----------------------------------------------------------*/
//Name: SangWoo Shin
// ID: 119294213
// Email: sshin36@myseneca.ca
//Section Information Code : NCC

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"

#ifndef NAMESPACE_DNA_H
#define NAMESPACE_DNA_H

struct DNA
{
    char* dnaRecord;
    int ID;
};

namespace sdds
{
    int findMatches(const char* subDNA, FILE* fptr);
    bool beginSearch(const char* filename);
    bool read(const char* subDNA);
    void sort(void);
    void displayMatches(void);
    void deallocate(void);
    void endSearch(void);
}

#endif