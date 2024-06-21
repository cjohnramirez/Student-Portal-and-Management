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
void Utils::studentInfo(string username) { //student class: reads student record
    ifstream students("students.csv");

    cout << left;
    cout << setw(15) << "Course code";
    cout << setw(40) << "Course name";
    cout << setw(10) << "Units";
    cout << setw(10) << "Midterm";
    cout << setw(10) << "Final";
    cout << setw(10) << "Instructor" << "\n";

    vector<string> row;
    string line, word;

    while (getline(students, line))
    {
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word); 
        }

        if (row.empty()) continue;

        bool isFound;
        if (row[0] == username){
            isFound = true; continue;
        }
        else if (isFound && row[0] != "#"){
            cout << setw(15) << row[0];
            cout << setw(40) << row[1];
            cout << setw(10) << row[2];
            cout << setw(10) << row[3];
            cout << setw(10) << row[4];
            cout << setw(10) << row[5] << "\n";
        }

        else if (isFound && row[0] == "#") break;
    }

    students.close();
}

void Utils::studentsPerSection(string sectionName, string courseName, string teacherName) //teacher class: reads record of students per section 
{
    ifstream students("students.csv");

    cout << left;
    cout << setw(20) << "Name";
    cout << setw(15) << "Midterm";
    cout << setw(15) << "Final" << "\n";

    vector<string> row;
    string line, word;

    bool startFind, findCourse = false;
    string studentName;
    while (getline(students, line))
    {
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ','))
            row.push_back(word);

        if (row[0] == "#"){
            startFind = true;
            continue;
        }

        if (startFind){
            studentName = row[0];
            if (sectionName == row[2]){
                cout << setw(20) << studentName;
                findCourse = true;
                continue;
            }
        }

        if (findCourse){
            if (courseName == row[0]){
                cout << setw(15) << row[3];
                cout << setw(15) << row[4] << "\n";
            }
        }
    }

    students.close();

    returnButton(choice);
    if (choice == 0) return;
}

int Utils::returnButton(int choice){ //button to return at somewhere
    while (true) {
        cout << "[0] Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()){
            cout << "Not an integer. Try again." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            continue;
        } else 
            break;
    }

    delayAnimation();
    return choice;
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