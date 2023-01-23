//Workshop1 part2
//Name : Sang Woo, Shin
//Student ID : 119294213
//Email : sshin36@myseneca.ca
//Section Information Code : NCC

#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"

using namespace std;
namespace sdds
{
    void exit(const char* filename)
    {
        cout << "Thank you for using " << filename << " directory."
            << endl;
    }

    int readTextFile(const char* programTitle, const char* filename, FILE* fptr, profile* detail)
    {
        int i = 0;
        int readNumber = 0;
        fptr = fopen(filename, "r"); 
        if(fptr)
        {
            while (!feof(fptr))
            {
                fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", detail[i].name, detail[i].area,
                    detail[i].prefix, detail[i].number);
                i++;
                readNumber = i;
            }
        }
        else
        {
            cout << filename << " file not found!" << endl;
            exit(programTitle);
        }
        fclose(fptr);
        return readNumber;
    }

    void findPhoneNumber(const char* programTitle, const char* filename, FILE* fptr, profile* detail)
    {
        int readNumber = 0;
        readNumber = readTextFile(programTitle, filename, fptr, detail);
        char searchName[MAX_NAME_LEN] = { 0 };
        if (readNumber != 0)
        {
            do
            {
                int inputLen = 0;
                char lowInput[MAX_NAME_LEN] = { 0 };
                char lowTextName[MAX_NAME_LEN] = { 0 };
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit"
                    << endl << "> ";
                cin >> searchName;
                inputLen = strLen(searchName);
                if (strCmp(searchName, "!") == 0)
                {
                    exit(programTitle);
                }
                else if (inputLen  > MAX_NAME_LEN)
                {
                    cout << "ERROR: Name can't be longer than " << MAX_NAME_LEN << endl;
                    exit(programTitle);
                }
                else
                {
                    for (int i = 0; i < readNumber; i++)
                    {
                        toLowerCaseAndCopy(lowInput, searchName);
                        toLowerCaseAndCopy(lowTextName, detail[i].name);
                        if (strStr(lowTextName, lowInput) != nullptr)
                        {
                            cout << detail[i].name << ": " << "(" << detail[i].area << ") "
                                << detail[i].prefix << "-" << detail[i].number << endl;
                        }
                    }
                }
            } while (strCmp(searchName, "!") != 0);
        }
    }

    void phoneDir(const char* programTitle, const char* fileName)
    {
        cout << programTitle << " phone direcotry search" << endl
            << "-------------------------------------------------------" <<
            endl;
        FILE* fptr = nullptr;
        profile detail[100] = { 0 };
        findPhoneNumber(programTitle, fileName, fptr, detail);
    }
}