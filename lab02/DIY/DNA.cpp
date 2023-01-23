/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: DNA.cpp
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

#include "DNA.h"
#include "cStrTools.h"

using namespace std;
namespace sdds
{
    FILE* fptr = nullptr;
    DNA* matchDNA = nullptr;
    int numOfMatch = 0;
    char fileName[256] = { 0 };

    int findMatches(const char* subDNA)
    {
        char dna[1001];
        int ID = 0;
        int num = 0;
        while (fscanf(fptr, "%d, %s/n", &ID, dna) != EOF)
        {
            if ((strStr(dna, subDNA) != nullptr))
            {
                num++;
            }
            else
            {
               ;
            }
        }
        rewind(fptr);
        return num;
    }
    

    bool beginSearch(const char* filename)
    {
        cout << "DNA search program" << endl;
        bool read = false;
        fptr = fopen(filename, "r");
        if (fptr)
        {
            read = true;            
        }
        rewind(fptr);
        return read;
    }

    bool read(const char* subDNA)
    {
        bool read = false;
        int i = 0;
        int len = 0;
        numOfMatch = findMatches(subDNA); 
        int tempID = 0;
        char tempDNA[1001] = { 0 };
        while (fscanf(fptr, "%d, %s/n", &tempID, tempDNA) != EOF)
        {
            if ((strStr(tempDNA, subDNA) != nullptr))
            {
                if (i == 0)
                {
                    matchDNA = new DNA[numOfMatch];
                }
                read = true;
                len = strLen(tempDNA);
                matchDNA[i].dnaRecord = new char[len + 1];
                strCpy(matchDNA[i].dnaRecord, tempDNA);
                matchDNA[i].ID = tempID;
                i++;
            }
        }
        rewind(fptr);
        return read;
    }

    void sort(void)
    {
        DNA sortID = { 0 };
        for (int i = 1; i < numOfMatch; i++)
        {
            sortID = matchDNA[i];
            int j = i - 1;
            while(j >= 0 && sortID.ID < matchDNA[j].ID)
            {
                matchDNA[j + 1] = matchDNA[j];
                j--;
            }
            matchDNA[j + 1] = sortID;
        }
    }

    void displayMatches(void)
    {
        cout << numOfMatch << " matches found:" << endl;
        for (int i = 0; i < numOfMatch; i++)
        {
            cout << i + 1 << ") " << matchDNA[i].ID << ":" << endl
                << matchDNA[i].dnaRecord << endl
                << "======================================================================" << endl;
        }
    }

    void deallocate(void)
    {

        for (int i = 0; i < numOfMatch; i++)
        {
            delete[] matchDNA[i].dnaRecord;
            matchDNA[i].dnaRecord = nullptr;
        }
        delete[] matchDNA;
        matchDNA = nullptr;
        numOfMatch = 0;
    }

    void endSearch(void)
    {
        cout << "DNA Search Program Closed." << endl;
        fclose(fptr);
    }
}
