 // Dynamic Memory Allocation in C++
 // - allocate an array of CHARACTERS dynamically (i.e. at run-time)
 // - 3 steps
 
 // matrix: g++ -std=c++11
 // updated on 9/08/2020

 // valgrind --tool=memcheck --leak-check=yes demo2

 #include <cstring>
 #include <iostream>
 using namespace std;

 int main() {


     /*Part 2 - Dynamic Memory Allocation */

     int m;
	
     cout << "\n>>> Please enter the number of characters in the English word: ";
     cin >> m;

     // Step 1. Declare a pointer of a given data type.
     char* word; // not initialized: = nullptr;        

     // Step 2. Allocate memory storage at run-time.

if (word == nullptr)
     word = new char [m+1];    // why m+1, not m?


     // assumption: memory allocation is successful
     // store a string at the memory storage

	  cout << ">>> Please enter the English word: ";
	
	  cin >> word;

	 cout << "### You have entered this English word: " << word
	      << "\n### It has " << strlen(word) << " characters." << endl;

     // Step 3. Release the memory storage to avoid MEMORY LEAK!
   
     delete [] word;   
     word = nullptr;
     
     return 0;
 }
