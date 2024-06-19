#include "utils.h"
#include "login.h"
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

//these are for utilities and tools in the program
void Utils::studentInfo(string username) {
    ifstream students("students.csv");

    vector<string> row;
    string line, word;

    while (getline(students, line))
    {
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word); 
        }

        if (row.empty())
            continue;

        bool isFound;
        if (row[1] == username){
            isFound = true;
            continue;
        }
        else if (isFound && row[0] != "#"){
            cout << left;
            cout << setw(15) << row[0];
            cout << setw(40) << row[1];
            cout << setw(10) << row[2];
            cout << setw(10) << row[3];
            cout << setw(10) << row[4];
            cout << setw(10) << row[5] << "\n";
        }

        else if (isFound && row[0] == "#")
            break;
    }

    students.close();
}

int Utils::returnButton(int choice){ //button to return at student menu
    cout << "[0] Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    system("cls");
    return 1;
}

void Utils::logout() //button to return at main menu
{
    delayAnimation();
    cout << "Redirecting to login page..." << endl;
    delayAnimation();
}

void Utils::delayAnimation()
{
    using namespace std::literals;
    std::this_thread::sleep_for(0.25s);

    cout << u8"\033[2J\033[1;1H"; 
}