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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "AidMan.h"
#include "Date.h"

using namespace std;
namespace sdds
{

    AidMan::AidMan() : Menu()
    {
        for (int i = 0; i < sdds_max_num_items; i++)
        {
            prod[i] = nullptr;
        }
        fileName = nullptr;
        option = 7;
        option = "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n";
    }

    int AidMan::menu() const
    {
        int select;
        if (fileName)
        {
            cout << "Aid Management System" << endl;
            cout << "Date: " << Date() << endl;
            cout << "Data file: " << fileName << endl;
        }
        else
        {
            cout << "Aid Management System" << endl;
            cout << "Date: " << Date() << endl;
            cout << "Data file: No file" << endl;
        }
        cout << "---------------------------------" << endl;
        select = option.Menu::run();
        return select;
    }

    void AidMan::searchList(const char* menu, int select)
    {
        char list[30];
        int menuLen = 0;
        int count = 0;
        int j = 0;
        menuLen = (int)strlen(option.getMenuContent());
        if (select > 0)
        {
            for (int i = 0; i < menuLen; i++)
            {
                if (option.getMenuContent()[i] == '\n')
                {
                    count++;
                    if (count == select)
                    {
                        list[j] = '\0';
                        i = (int)strlen(option.getMenuContent());
                    }
                }
                if (count == select - 1)
                {
                    list[j] = option.getMenuContent()[i];
                    j++;
                }
            }
            if (select == count)
            {
                cout << "\n****";
                if (select == 1)
                {
                    for (int i = 3; list[i] != '\0'; i++)
                    {
                        cout << list[i];
                    }
                }
                else
                {
                    for (int i = 4; list[i] != '\0'; i++)
                    {
                        cout << list[i];
                    }
                }
                cout << "****" << endl;
            }
        }
    }
    int AidMan::list(const char* sub_desc)
    {
        int print = 0;
        ifstream file(fileName);
        if (file)
        {
            if (sub_desc == nullptr)
            {
                print = 1;
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
                for (int i = 0; i < numOfItems; i++)
                {
                    prod[i]->linear(true);
                    cout << "   ";
                    cout << print << " | ";
                    cout << *prod[i] << endl;
                    print++;
                }
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
                cout << "Enter row number to display details or <ENTER> to continue:\n> ";
                if (cin.peek() != '\n')
                {
                    int j;
                    cin >> j;
                    prod[j - 1]->linear(false);
                    cout << *prod[j - 1] << endl << endl;
                }
                else { cout << endl; }
            }
            else
            {
                int sku;
                
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
                for (int i = 0; i < numOfItems; i++)
                {
                    char descr[400];
                    file >> sku;
                    ut.extractChar(file, '\t');
                    file.get(descr, 400, '\t');
                    file.ignore(1000, '\n');
                    if (ut.strStr(descr, sub_desc) != nullptr)
                    {
                        prod[i]->linear(true);
                        cout << "   ";
                        cout << i+1 << " | ";
                        cout << *prod[i] << endl;
                        print++;
                    }
                }
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
            }
            if (print == 0)
            {
                cout << "The list is empty!" << endl;
            }
        }
        return print;
    }
    
    int AidMan::search(int sku) const
    {
        int index = -1;
        int temp;
        ifstream file(fileName);
        if (file)
        {
            for (int i = 0; i < numOfItems; i++)
            {
                temp = prod[i]->getSKU();
                if (temp == sku)
                {
                    index = i;
                }
            }
        }
        return index;
    }

    void AidMan::add()
    {
        if (numOfItems == sdds_max_num_items)
        {
            cout << "Database full!" << endl;
        }
        else
        {
            int select;
            int index;
            int sku;
            ofstream file(fileName, ios::app);
            cout << "1- Perishable\n2- Non-Perishable\n-----------------" << endl;
            cout << "0- Exit\n";

            select = ut.getInt(0, 2, "> ");
            if (select == 0)
            {
                cout << "Aborted" << endl;
            }
            else if (select == 1)
            {
                prod[numOfItems] = new Perishable;
                sku = prod[numOfItems]->readSku(cin);
                index = search(sku);
                if (index == -1)
                {
                    prod[numOfItems]->read(cin);
                    if (bool(prod[numOfItems]))
                    {
                        prod[numOfItems]->save(file);
                        file.put('\n');
                        numOfItems++;
                        file.flush();
                        file.close();
                    }
                    else
                    {
                        prod[numOfItems]->linear(true);
                        cout << *prod[numOfItems] << endl;
                        delete prod[numOfItems];
                    }
                }
                else
                {
                    delete prod[numOfItems];
                    cout << "Sku: " << sku <<
                        " is already in the system, try updating quantity instead.\n";
                }
            }
            else
            {
                prod[numOfItems] = new Item;
                sku = prod[numOfItems]->readSku(cin);
                index = search(sku);
                if (index == -1)
                {
                    prod[numOfItems]->read(cin);
                    if (bool(prod[numOfItems]))
                    {
                        prod[numOfItems]->save(file);
                        file.put('\n');
                        numOfItems++;
                        file.flush();
                        file.close();
                    }
                    else
                    {
                        prod[numOfItems]->linear(true);
                        cout << *prod[numOfItems] << endl;
                        delete prod[numOfItems];
                    }
                }
                else
                {
                    delete prod[numOfItems];
                    cout << "Sku: " << sku <<
                        " is already in the system, try updating quantity instead.\n";
                }
            }
        }
        cout << endl;
    }
    void AidMan::save()
    {
        if (fileName)
        {
            ofstream ofstr(fileName);
            for (int i = 0; i < numOfItems; i++)
            {
                prod[i]->save(ofstr);
                ofstr.put('\n');
            }
            ofstr.close();
        }
    }

    void AidMan::allocate()
    {
        ifstream ifstr(fileName);
        string line;
        if (ifstr.is_open())
        {
            for (int i = 0; ifstr.peek() != -1; i++)
            {
                delete prod[i];
                if (ifstr.peek() == '1' || ifstr.peek() == '2' || ifstr.peek() == '3')
                {
                    prod[i] = new Perishable;
                    numOfItems++;
                }
                else if (ifstr.peek() != '1' && ifstr.peek() != '2' && ifstr.peek() != '3')
                {
                    prod[i] = new Item;
                    numOfItems++;
                }
                else
                {
                    ifstr.setstate(ios_base::failbit);
                    break;
                }
                getline(ifstr, line, '\n');

            }
        }
    }

    void AidMan::load()
    {
        ifstream ifstr(fileName);

        if (ifstr.is_open())
        {
            for (int i = 0; i < numOfItems; i++)
            {
                prod[i]->load(ifstr);
            }
        }
        else
        {
            cout << "Falied to open " << fileName << " for reading!" << endl;
        }
        cout << numOfItems << " records loaded!\n" << endl;
    }

    void AidMan::run(void)
    {
        int select = 0;
        int numOfPrint = 0;
        char file[50];
        do
        {
            select = menu();
            if (select == 0)
            {
                cout << "Exiting Program!" << endl;
            }
            else if (fileName == nullptr || select == 7)
            {
                if (fileName == nullptr)
                {
                    select = 7;
                    searchList(option.getMenuContent(), select);
                    cout << "Enter file name: ";
                    cin >> file;
                    delete[] fileName;
                    fileName = new char[strlen(file) + 1];
                    strcpy(fileName, file);
                    allocate();
                    load();
                }
                else
                {
                    searchList(option.getMenuContent(), select);
                    save();
                }
            }
            else if (select == 1)
            {
                searchList(option.getMenuContent(), select);
                numOfPrint = list();
            }
            else if (select == 2)
            {
                searchList(option.getMenuContent(), select);
                add();
            }
            else if (select == 3)
            {
                int index;
                int choice;
                searchList(option.getMenuContent(), select);
                index = findSKUIndex(1);
                choice = ut.getInt(0, 1, "> ");
                if (index == -1)
                {
                    cout << "SKU not found!" << endl;
                }
                else if (choice == 1)
                {
                    cout << "Item removed!\n" << endl;
                    remove(index);
                    save();
                }
                else
                {
                    cout << "Aborted!" << endl;
                }
            }
            else if (select == 4)
            {
                int index;
                int choice;
                searchList(option.getMenuContent(), select);
                index = findSKUIndex(2);
                choice = ut.getInt(0, 2, "\n> ");
                if (index == -1)
                {
                    cout << "SKU not found!\n" << endl;
                }
                else
                {
                    addOrRemove(choice, index);
                }
            }
            else if (select == 5)
            {
                searchList(option.getMenuContent(), select);
                sort();
            }
            else if (select == 6)
            {
                searchList(option.getMenuContent(), select);
                shipOrder();
            }
        } while (select != 0);
    }

    void AidMan::sort()
    {
        for (int i = 0; i < numOfItems - 1; i++)
        {
            for (int j = 1; j < numOfItems; j++)
            {
                iProduct* temp;
                if (prod[j-1]->qtyNeeded() - prod[j-1]->qty() < prod[j]->qtyNeeded() - prod[j]->qty())
                {
                    temp = prod[j-1];
                    prod[j-1] = prod[j];
                    prod[j] = temp;
                }
            }
        }
        save();
        cout << "Sort completed!\n" << endl;
    }

    void AidMan::shipOrder()
    {
        ut.testMode();
        int print = 1;
        ofstream ofstr;
        ofstr.open("shippingOrder.txt");
        ofstr << "Shipping Order, Date: " << Date() << endl;
        ofstr << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
        ofstr << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
        for (int i = 0; i < numOfItems; i++)
        {
            if (prod[i]->qtyNeeded() == prod[i]->qty())
            {
                prod[i]->linear(true);
                ofstr << "   ";
                ofstr << print << " | ";
                ofstr << *prod[i] << endl;
                print++;
                remove(i);
                save();
            }
        }
        ofstr << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
        cout << "Shipping Order for " << numOfItems << " times saved!\n" << endl;
    }

    void AidMan::addOrRemove(int choice, int index)
    {
        int amount;
        if (choice == 1)
        {
            if (prod[index]->qtyNeeded() == prod[index]->qty())
            {
                cout << "Quantity Needed already fulfilled!\n" << endl;
            }
            else
            {
                amount = ut.getInt(1, prod[index]->qtyNeeded(), "Quantity to add: ", "Value out of range ");
                *prod[index] += amount;
                cout << amount << " items added!\n" << endl;
                save();
            }
        }
        else if (choice == 2)
        {
            if (prod[index]->qty() == 0)
            {
                cout << "Quantity on hand is zero!\n" << endl;
            }
            else
            {
                amount = ut.getInt(1, prod[index]->qty(), "Quantity to reduce: ", "Value out of range ");
                *prod[index] -= amount;
                cout << amount << " items removed!\n" << endl;
                save();
            }
        }
        else
        {
            cout << "Aborted!\n" << endl;
        }
    }

    int AidMan::findSKUIndex(int flag)
    {
        char descr[100];
        cout << "Item description: ";
        cin.get(descr, 100, '\n');
        list(descr);
        int findSku;
        int sku;
        int index = -1;
        ifstream file(fileName);
        findSku = ut.getInt(10000, 99999, "Enter SKU: ");
        for (int i = 0; i < numOfItems; i++)
        {
            file >> sku;
            file.ignore(1000, '\n');
            if (findSku == sku)
            {
                if (flag == 1) // for Remove
                {
                    cout << "Following item will be removed: " << endl;
                    prod[i]->linear(false);
                    cout << *prod[i] << endl;
                    cout << "Are you sure?" << endl << "1- Yes!" << endl
                        << "0- Exit" << endl;
                    index = i;
                    i = numOfItems;
                }
                else if (flag == 2) // for Update quantity
                {
                    cout << "1- Add" << endl << "2- Reduce" << endl << "0- Exit";
                    index = i;
                    i = numOfItems;
                }
            }
        }
        return index;
    }
    void AidMan::remove(int index)
    {
        iProduct* temp;
        for (int j = index; j < numOfItems - 1; j++)
        {
            temp = prod[j + 1];
            prod[j + 1] = prod[j];
            prod[j] = temp;
        }
        delete prod[numOfItems - 1];
        numOfItems--;
    }
    AidMan::~AidMan()
    {
        option.clear();
        if (fileName)
        {
            delete[] fileName;
            fileName = nullptr;
        }

        for (int i = 0; i < numOfItems; i++)
        {
            if (prod[i])
            {
                delete prod[i];
                prod[i] = nullptr;
            }
        }
    }
}
