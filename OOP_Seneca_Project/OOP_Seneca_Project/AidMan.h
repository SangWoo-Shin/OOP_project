/*
    ==================================================
    Mile Stone 5-6
    ==================================================
    Name   : Sangwoo Shin
    ID     : 119294213
    Email  : sshin36@myseneca,ca
    Section: NCC
    Date   : 2022/4/7
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef AIDMAN_H
#define AIDMAN_H
#include <iostream>
#include "Menu.h"
#include "iProduct.h"
#include "Item.h"
#include "Perishable.h"

namespace sdds
{
    const int sdds_max_num_items = 100;

    class AidMan : public Menu
    {
    private:
        char* fileName;
        Menu option;
        iProduct* prod[sdds_max_num_items];
        int numOfItems = 0;
    public:
        AidMan();
        int findSKUIndex(int flag);
        void shipOrder();
        void sort();
        void addOrRemove(int choice, int index);
        void remove(int index);
        void searchList(const char* menu, int select);
        int menu() const;
        void run();
        int list(const char* sub_desc = nullptr);
        int search(int sku) const;
        void add();
        void save();
        void allocate();
        void load();
        ~AidMan();
    };
}

#endif //AIDMAN_H
