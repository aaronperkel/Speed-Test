#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int size;
    // Get command line input
    if (argc > 1) {
        size = stoi(argv[1]);
    } else {
        size = 10000;
    }
    cout << "Looking for size: " << size << endl;
    
    // Declare a vector of longs to store the numbers
	vector<long> numbers;
    
    // Read size numbers from numbers.txt
    ifstream inFile("numbers.txt");

    string line;
    long number;
    for (int i = 0; i < size; i++) {
        if (inFile) {
            // https://www.geeksforgeeks.org/cpp-program-for-string-to-long-conversion/
            getline(inFile, line);
            number = stol(line);
        }
        numbers.push_back(number);
    }
    inFile.close();
    
    // Print the vector size (to make sure it matches the size printed above)
    cout << "Vector Size: " << numbers.size() << endl;
     
    // CS2240 Project 4
    // Bubble Sort the vector
    int numPasses = 0, i;
    long temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < numbers.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (numbers[i] > numbers[i+1]) {
                temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
    }

    // Print the first and last ten numbers from the vector to the console
    cout << "First ten numbers:";
    for (int i = 0; i < 10 && i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Last ten numbers: ";
    int start = numbers.size() - 10;
    for (int i = start; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
