// COMSC-210 | Final Exam 1 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//function prototype
void printAirports(const map<string, int>& flights, int, int

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
            cout << it->first << " " << it-> second << endl;
        }
    }
    
    cout << "\nAirports with traffic in range [" << "]:" << endl;
    //printAirports(flights, 5, 8);
    
    cout << "\nAirports with traffic in range [" << "]:" << endl;
    //printAirports(flights, 9, 12);
    
    fin.close(); //close file

    return 0;
}