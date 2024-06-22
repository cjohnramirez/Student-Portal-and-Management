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

//FOR STUDENT CLASS
void Utils::studentGrades(string username) { 
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

void Utils::studentInformation(string username){
        ifstream students("students.csv");

    cout << left;
    cout << setw(20) << "Label:" << setw(30) << "Information:" << "\n\n";

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
            isFound = true;
            if (isFound && row[0] != "#"){
                cout << setw(20) << "Name" << setw(30) << row[0] << "\n";
                cout << setw(20) << "Course" << setw(30) << row[5] << "\n"; 
                cout << setw(20) << "Section" << setw(30) << row[2] << "\n";
                cout << setw(20) << "Email" << setw(30) << row[3] << "\n"; 
                cout << setw(20) << "Phone Number" << setw(30) << row[4] << "\n";
                cout << setw(20) << "School ID" << setw(30) << row[6] << "\n";
            }
        }

        else if (isFound && row[0] == "#") break;
    }


    students.close();
}

//FOR TEACHER CLASS
void Utils::studentsPerSection(string sectionName, string courseName, string teacherName) //teacher class: reads record of students per section 
{
    ifstream students("students.csv");

    cout << left;
    cout << setw(20) << "Name";
    cout << setw(15) << "Midterm";
    cout << setw(15) << "Final" << "\n";

    int countItems = 0;
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

//FOR ADMIN CLASS
void Utils::modifyStudentGrades(string studentName, string courseName, int index, double grade) {
    ifstream students("students.csv");

    int countLines = 0;
    vector<string> row;
    string line, word;
    string newline;

    bool startFind, findCourse = false;

    while (getline(students, line))
    {
        countLines++;
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word);
        }
            
        if (row[0] == "#"){
            startFind = true;
            continue;
        }

        if (startFind && row[0] == studentName){
            findCourse = true;
            continue;
        }

        if (findCourse && row[0] == courseName){
            std::ostringstream ss;
            ss << grade;
            std::string s(ss.str());

            row[index] = s;
        
            std::stringstream updatedLine;
            for (int i = 0; i < row.size(); ++i) {
                if (i > 0) updatedLine << ",";
                updatedLine << row[i];
            }
            newline = updatedLine.str();

            break;
        }
    }

    copyCSVFile("students.csv", "temporary.csv");
    students.close();

    ifstream tempFile("temporary.csv");
    ofstream editFile("students.csv", ios::trunc);
    
    string readline;
    int currentRow = 0;
    while (getline(tempFile, readline, '\n')) {
        ++currentRow;
        if (currentRow == countLines) {
            editFile << newline << '\n';
        } else {
            editFile << readline << '\n';
        } 
    }
    
    ofstream deleteTempFile("temporary.csv");

    students.close();
    editFile.close();

    returnButton(choice);
    if (choice == 0) return;
}

void Utils::copyCSVFile(const string& sourceFile, const string& tempFile) {
    ifstream infile(sourceFile);
    ofstream outfile(tempFile);

    if (!infile) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }
    if (!outfile) {
        cerr << "Error: Cannot create temporary file." << endl;
        return;
    }

    string line;
    
    // Read each line from the source CSV file and write to the temporary file
    while (getline(infile, line)) {
        outfile << line << endl;
    }

    infile.close();
    outfile.close();
}

//GLOBAL FUNCTIONS
int Utils::returnButton(int choice) { //button to return at somewhere
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

    delayAnimation(250);
    return choice;
}

void Utils::logout() //button to return at main menu
{
    delayAnimation(250);
    cout << "Redirecting to login page..." << endl;
    delayAnimation(250);
}

void Utils::delayAnimation(double seconds)
{
    Sleep(seconds);
    system("cls");
}