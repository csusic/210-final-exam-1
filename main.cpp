// COMSC-210 | Final Exam 1 | Christine Susic

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


int main() {
    ifstream fin("data.txt"); //open file
    int count = 0; //initialize count to zero
    string origin1, dest2; //strings to read from file
    
    std::map<std::string, int>

    //read codes from file one by one
    while (fin >> origin1) {
        (fin >> dest2);
        cout << origin1 << " " << dest2 << endl;
        count++;
    }
    
    fin.close(); //close file

    return 0;
}