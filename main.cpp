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
    
    //cout << "Busiest airport(s) with count:" << count << endl;
    //cout << "Airports with traffic in range [" << "]:" << endl;
    //cout << "Airports with traffic in range [" << "]:" << endl;
    
    //read codes from file
    while (fin >> origin) {
        fin >> dest;
        flights.insert({origin, count});
        flights.insert({dest, count});
        count++;
    }
    
    int max = 0;
    cout << "All airport traffic counts:" << endl;
    for (std::map<std::string, int>::iterator it = flights.begin(); it != flights.end(); it++) { 
        //it->first (origin), it->second (dest)
        cout << it->first << " " << it->second << endl; 
        //find max count
        if (it->second > max) {
            max = it->second;
        
        }
    }
    
    
    fin.close(); //close file

    return 0;
}