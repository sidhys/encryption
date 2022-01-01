#include <iostream>

using namespace std; 

int main()
{
    int number = 1321;
    int* memoryAddr = &number;
    cout << "Before dumb memory trolling: \n"
        << "Number: " << number << "\n"
        << "Memory Address " << memoryAddr << "\n";

    
    cout << *memoryAddr;
}