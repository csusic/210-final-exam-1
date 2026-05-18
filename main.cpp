// COMSC-210 | Final Exam 1 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;


int main() {
    ifstream fin("data.txt"); //open file
    int count = 0; //initialize count to zero
    string origin, dest; //string to read from file
    
    std::map<std::string, int> flights;
    
    cout << "All airport traffic counts:" << endl;
    cout << "Busiest airport(s) with count:" << count << endl;
    cout << "Airports with traffic in range [" << "]:" << endl;
    cout << "Airports with traffic in range [" << "]:" << endl;
    
    //read codes from file
    while (fin >> origin) {
        fin >> dest;
        flights.insert({origin, count});
        flights.insert({dest, count});
        count++;
    }
    
    fin.close(); //close file

    return 0;
}