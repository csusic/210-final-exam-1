// COMSC-210 | Final Exam 1 | Christine Susic

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//function prototype
void printAirports(const map<string, int>&, int, int);

int main() {
    ifstream fin("data.txt"); //open file
    int max = 0; //initialize maximum count to zero
    string origin, dest; //strings to read from file
    
    //map with flights origin(string), destination(string), and count
    std::map<std::string, int> flights;
    
    //read codes from file
    while (fin >> origin) {
        fin >> dest;
        flights[origin]++; 
        flights[dest]++;
    }
    
    //All airport traffic with counts
    cout << "All airport traffic counts:" << endl;
    for (std::map<std::string, int>::iterator it = flights.begin(); it != flights.end(); it++) { 
        //output it->first (string), it->second (int)
        cout << it->first << " " << it->second << endl; 
        //find maximum count
        if (it->second > max) {
            max = it->second;
        }
    }
    
    //Busiest airport traffic with counts
    cout << "\nBusiest airport(s) with count: " << max << endl;
    for (std::map<std::string, int>::iterator it = flights.begin(); it != flights.end(); it++) {
        //output maximum count
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
        //if count is within range, ouput count
        if (pair.second >= low && pair.second <= high) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    cout << endl;
}