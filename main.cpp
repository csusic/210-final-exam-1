// COMSC-210 | Final Exam 1 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//function prototype
void printAirports(const map<string, int>&, int, int);

int main() {
    ifstream fin("data.txt"); //open file
    int max = 0; //initialize count and max count to zero
    string origin, dest; //string to read from file
    
    std::map<std::string, int> flights;
    
    //read codes from file
    while (fin >> origin) {
        fin >> dest;
        flights[origin]++; 
        flights[dest]++;
    }
    
    //All airport traffic
    cout << "All airport traffic counts:" << endl;
    for (std::map<std::string, int>::iterator it = flights.begin(); it != flights.end(); it++) { 
        //output it->first (origin), it->second (dest)
        cout << it->first << " " << it->second << endl; 
        //find max count
        if (it->second > max) {
            max = it->second;
        }
    }
    
    //Busiest airport traffic
    cout << "\nBusiest airport(s) with count: " << max << endl;
    for (std::map<std::string, int>::iterator it = flights.begin(); it != flights.end(); it++) {
        if (it->second == max) {
            cout << it->first << " " << it-> second << endl << endl;
        }
    }
    
    //call function to print airports in range 5-8
    printAirports(flights, 5, 8);
    //call function to print airports in range 9-12
    printAirports(flights, 9, 12);
    
    fin.close(); //close file

    return 0;
}

//function that prints airports in ranges
void printAirports(const map<string, int>& flights, int low, int high) {
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for (const auto& pair : flights) {
        if (pair.second >= low && pair.second <= high) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    cout << endl;
}