#include "ReadCSV.h"
#include "utils.h"
#include "login.h"
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <iostream>
using namespace std;

//STUDENT CLASS
void ReadCSV::studentGrades(string username) { 
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
        if (row[1] == username){
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

//STUDENT CLASS
void ReadCSV::studentInformation(string username){
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
        if (row[1] == username){
            isFound = true;
            if (isFound && row[0] != "#"){
                cout << setw(20) << "Name" << setw(30) << row[1] << "\n";
                cout << setw(20) << "Section" << setw(30) << row[2] << "\n"; 
                cout << setw(20) << "Program" << setw(30) << row[3] << "\n";
                cout << setw(20) << "School ID" << setw(30) << row[4] << "\n";
                cout << setw(20) << "Email" << setw(30) << row[5] << "\n"; 
                cout << setw(20) << "Phone Number" << setw(30) << row[6] << "\n";
            }
        }

        else if (isFound && row[0] == "#") break;
    }


    students.close();
}

//TEACHER CLASS
void ReadCSV::studentsPerSection(string sectionName, string courseName, string teacherName) //teacher class: reads record of students per section 
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
            studentName = row[1];
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
int ReadCSV::listSections(int shift){

    cout << "Select section:" << endl;

    while (true){
        ifstream students("sections.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> sections;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Section" << "\n";

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            sections.push_back(row[0]);
            countItems++;

            cout << setw(10) << countItems;
            cout << setw(10) << row[0] << "\n";
        }

        students.close();

        int userChoice = returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= sections.size()){
                int index = userChoice - 1;
                if (shift == 1) listCourses(sections.at(index));
                else if (shift == 2) listStudents(sections.at(index));
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }
}

//ADMIN CLASS
int ReadCSV::listCourses(string sectionName){
    cout << "Select course:" << endl;

    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> courses;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Course" << "\n";
        bool checkSection, printCourses = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#" && printCourses) break;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printCourses = true;
                continue;
            }

            if (printCourses){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[0] << "\n";

                courses.push_back(row[0]);
                continue;
            }
        }

        students.close();

        int userChoice = returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= courses.size()){
                int index = userChoice - 1;

                listStudents(sectionName, courses.at(index)); 
                delayAnimation(200);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

//ADMIN CLASS
int ReadCSV::listStudents(string sectionName, string courseName)
{
    while (true){
        ifstream students("students.csv");

        cout << left;
        cout << setw(15) << "Number";
        cout << setw(20) << "Name";
        cout << setw(15) << "Midterm";
        cout << setw(15) << "Final" << "\n";

        int countItem = 0;
        vector<string> row;
        string line, word;

        bool startFind, findCourse = false;
        string studentName;

        vector<string> names;
        vector<string> midterm;
        vector<string> final;

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
                studentName = row[1];
                if (sectionName == row[2]){
                    countItem++;

                    cout << setw(15) << countItem;
                    names.push_back(studentName);
                    cout << setw(20) << studentName;
                    findCourse = true;
                    continue;
                }
            }

            if (findCourse){
                if (courseName == row[0]){
                    midterm.push_back(row[3]);
                    final.push_back(row[4]);

                    cout << setw(15) << row[3];
                    cout << setw(15) << row[4] << "\n";
                }
            }
        }

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

        if (choice == 0){
            return 0; break;
        } else {
            if (choice > 0){
                int index = choice - 1;
                string semesterChoice; int semesterNumber;

                cout << "Enter semester [m/f]: ";
                cin >> semesterChoice;
                if (semesterChoice == "m") semesterNumber = 3;
                else if (semesterChoice == "f") semesterNumber = 4;
                else {
                    cout << "Invalid value. Try again" << "\n";
                    continue;
                }

                double grade;
                cout << "Enter grade: ";
                cin >> grade;
                "\n";

                if (cin.fail()){
                    cout << "Invalid value. Try again" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    continue;
                }

                modifyStudentGrades(names.at(index), courseName, semesterNumber, grade);
                delayAnimation(350);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

//ADMIN CLASS
void ReadCSV::modifyStudentGrades(string studentName, string courseName, int index, double grade) {
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

        if (startFind && row[1] == studentName){
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

    return;
}

//ADMIN CLASS
int ReadCSV::listStudents(string sectionName){
    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> studentList;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Student" << "\n";
        bool checkSection, printStudent = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printStudent = true;
            }

            if (printStudent){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[1] << "\n";

                studentList.push_back(row[1]);

                printStudent = false;
                continue;
            }
        }

        students.close();

        int userChoice = returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= studentList.size()){
                int index = userChoice - 1;

                listStudentInformation(studentList.at(index), sectionName); 
                
                delayAnimation(200);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }
}

//ADMIN CLASS
int ReadCSV::listStudentInformation(string studentName, string sectionName){
    
    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> studentList;

        bool checkSection, printStudent = false;

        cout << left;
        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printStudent = true;
            }

            if (studentName == row[1] && printStudent){
                cout << left;
                cout << setw(10) << "Number" << setw(30) << "Label" << setw(15) << "Information" << "\n";
                cout << setw(10) << "1" << setw(30) << "Name" << setw(15) << row[1] << "\n";
                cout << setw(10) << "2" << setw(30) << "Section" << setw(15) << row[2] << "\n"; 
                cout << setw(10) << "3" << setw(30) << "Program" << setw(15) << row[3] << "\n";
                cout << setw(10) << "4" << setw(30) << "Phone Number" << setw(15) << row[4] << "\n"; 
                cout << setw(10) << "5" << setw(30) << "Email" << setw(15) << row[5] << "\n";

                printStudent = false;
                break;
            }
        }

        students.close();

        int userChoice = returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= 5 && userChoice != 2 && userChoice != 3){
                int index = userChoice;

                cin.ignore();
                string toReplace;
                cout << "Enter Replacement: ";
                getline(cin, toReplace);

                modifyStudentInformation(studentName, toReplace, index); 
            } else if (userChoice == 2) {
                cout << "Changing section is not allowed here." << endl;
            } else if (userChoice == 3) {
                cout << "Changing program is not allowed here." << endl;
            } else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }
}

//ADMIN CLASS
void ReadCSV::modifyStudentInformation(string studentName, string toReplace, int index) {
    ifstream students("students.csv");

    int countLines = 0;
    vector<string> row;
    string line, word;
    string newline;

    bool startFind, findInfo = false;

    while (getline(students, line))
    {
        countLines++;
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')) row.push_back(word);
        
        if (row[0] == "#"){
            startFind = true;
            continue;
        }

        if (startFind && row[1] == studentName){
            if (index == 1) modifyAccount(studentName, toReplace);
            row[index] = toReplace;
        
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
        if (currentRow == countLines) 
            editFile << newline << '\n';
        else 
            editFile << readline << '\n';
    }
    
    ofstream deleteTempFile("temporary.csv");

    students.close();
    editFile.close();
}

//ADMIN CLASS
void ReadCSV::modifyAccount(string name, string newName){
    ifstream students("accounts.csv");

    int countLines = 0;
    vector<string> row;
    string line, word;
    string newline;

    while (getline(students, line))
    {
        countLines++;
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')) row.push_back(word);

        if (row[3] == name){
            row[3] = newName;
        
            std::stringstream updatedLine;
            for (int i = 0; i < row.size(); ++i) {
                if (i > 0) updatedLine << ",";
                updatedLine << row[i];
            }
            newline = updatedLine.str();
            break;
        }
    }

    copyCSVFile("accounts.csv", "temporary.csv");
    students.close();

    ifstream tempFile("temporary.csv");
    ofstream editFile("accounts.csv", ios::trunc);
    
    string readline;
    int currentRow = 0;
    while (getline(tempFile, readline, '\n')) {
        ++currentRow;
        if (currentRow == countLines) 
            editFile << newline << '\n';
        else 
            editFile << readline << '\n';
    }
    
    ofstream deleteTempFile("temporary.csv");

    students.close();
    editFile.close();

    return;
}

int ReadCSV::listInformationNeeded(){

}

void ReadCSV::createStudent(const string& row){
    
}

//ADMIN CLASS (OR TEACHER CLASS)
void ReadCSV::copyCSVFile(const string& sourceFile, const string& tempFile) {
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
    while (getline(infile, line)) outfile << line << endl;

    infile.close();
    outfile.close();
}
