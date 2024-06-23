#include "ReadCSV.h"
#include "utils.h"
#include "login.h"
#include "hashes.cpp"
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
    cout << "\033[94m" << R"(   ____ ____      _    ____  _____ ____  
  / ___|  _ \    / \  |  _ \| ____/ ___| 
 | |  _| |_) |  / _ \ | | | |  _| \___  \
 | |_| |  _ <  / ___ \| |_| | |___ ___) |
  \____|_| \_\/_/   \_\____/|_____|____/ 
                                         )" << "\033[0m\n";
    ifstream students("students.csv");

    cout << "=====================================================================================================\n";
    cout << left;
    cout << setw(15) << "Course code";
    cout << setw(40) << "Course name";
    cout << setw(10) << "Units";
    cout << setw(10) << "Midterm";
    cout << setw(10) << "Final";
    cout << setw(10) << "Instructor" << endl;
    cout << "====================================================================================================\n";

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
    cout << "\n";
}

//STUDENT CLASS
void ReadCSV::studentInformation(string username){
    cout << "\033[94m" << R"( __     _____ _______        __                                
 \ \   / /_ _| ____\ \      / /                                
  \ \ / / | ||  _|  \ \ /\ / /                                 
   \ V /  | || |___  \ V  V /                                  
  __\_/  |___|_____|_ \_/\_/ __  __    _  _____ ___ ___  _   _ 
 |_ _| \ | |  ___/ _ \|  _ \|  \/  |  / \|_   _|_ _/ _ \| \ | |
  | ||  \| | |_ | | | | |_) | |\/| | / _ \ | |  | | | | |  \| |
  | || |\  |  _|| |_| |  _ <| |  | |/ ___ \| |  | | |_| | |\  |
 |___|_| \_|_|   \___/|_| \_\_|  |_/_/   \_\_| |___\___/|_| \_|
                                                               )" << "\033[0m\n";
    ifstream students("students.csv");

    cout << left;
    cout << "========================================\n";
    cout << setw(20) << "Label:" << setw(30) << "Information: " << endl;
    cout << "========================================\n";

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
    cout << "\n";
}

//TEACHER CLASS
int ReadCSV::teacherCourses(string name)
{
    while (true){
        cout << "\033[94mView Sections\033[0m" << endl;
        ifstream students("teachers.csv");

        cout << left;
        cout << endl;
        cout << "=============================\n";
        cout << setw(10) << "Number";
        cout << setw(10) << "Course";
        cout << setw(10) << "Section" << endl;
        cout << "=============================\n";

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> courses;
        vector<string> sections;
        bool checkname, printSection = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#" && printSection) break;

            if (row[0] == "#"){
                checkname = true;
                continue;
            }

            if (row[0] == name && checkname){
                printSection = true;
                continue;
            }

            if (printSection){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[0];
                cout << setw(10) << row[1] << "\n";

                courses.push_back(row[0]);
                sections.push_back(row[1]);
                continue;
            }
        }

        students.close();
        cout << endl;

        int userChoice = returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= sections.size() && userChoice <= courses.size()){
                int index = userChoice - 1;
                studentsPerSection(sections.at(index), courses.at(index), name);
            }
            else {
                cout << "\033[31m[Invalid number. Try again]\033[0m" << "\n";
                continue;
            }
        }
    }

    return 0;
}

void ReadCSV::studentsPerSection(string sectionName, string courseName, string teacherName) //teacher class: reads record of students per section 
{
    ifstream students("students.csv");
    cout << "\033[94mView Sections\033[0m" << endl;

    cout << left;
    cout << "======================================\n";
    cout << setw(20) << "Name";
    cout << setw(15) << "Midterm";
    cout << setw(15) << "Final" << endl;
    cout << "======================================\n";

    int countItems = 0;
    vector<string> row;
    string line, word;

    bool startFind, findCourse, showError = false;
    string studentName;

    while (true) {
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
        cout << endl;

        returnButton(choice);
        if (choice == 0){
            break; 
        } 
        else if (choice != 0){
            cout << "\033[31m[You can only press back.]\033[0m";
            cout << endl;
            break;
        }
    }

    return;
}

//FOR ADMIN CLASS
int ReadCSV::listSections(int shift){
    delayAnimation(10);
    while (true){
        cout << "\033[94mSelect Section:\033[0m" << endl;
        ifstream students("sections.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> sections;

        cout << left;
        cout << "==================\n";
        cout << setw(10) << "Number";
        cout << setw(10) << "Section" << "\n";
        cout << "==================\n";

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
        cout << "\n";

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
    while (true){
        cout << "\033[94mSelect Course:\033[0m" << endl;
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> courses;

        cout << "================\n";
        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Course" << endl;
        cout << "================\n";
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
        cout << endl;

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
                cout << "\033[31m[Invalid number. Try again]\033[0m" << "\n";
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
        cout << "\033[94mSelect Student:\033[0m" << endl;
        ifstream students("students.csv");

        cout << left;
        cout << "==========================================================\n";
        cout << setw(15) << "Number";
        cout << setw(20) << "Name";
        cout << setw(15) << "Midterm";
        cout << setw(15) << "Final" << endl;
        cout << "==========================================================\n";

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
            cout << "\033[31m[0]\033[0m Back" << endl;
            cout << "Enter your choice: \033[32m";
            cin >> choice;
            cout << "\033[0m";

            if (cin.fail()){
                cout << "\033[31m[Not an integer. Try again.]\033[0m" << endl;
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

                cout << "Enter semester [m/f]: \033[32m";
                cin >> semesterChoice;
                cout << "\033[0m";
                if (semesterChoice == "m") semesterNumber = 3;
                else if (semesterChoice == "f") semesterNumber = 4;
                else {
                    cout << "\033[31m[Invalid value. Try again] \033[0m" << "\n";
                    continue;
                }

                double grade;
                cout << "Enter grade: \033[32m";
                cin >> grade;
                cout << "\033[0m" << endl;

                if (cin.fail()){
                    cout << "\033[31m[Invalid value. Try again]\033[0m" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    continue;
                }

                modifyStudentGrades(names.at(index), courseName, semesterNumber, grade);
                delayAnimation(350);
            }
            else {
                cout << "\033[31m[Invalid number. Try again]\033[0m" << endl;
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
        cout << "\033[94mSelect Student:\033[0m" << endl;

        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> studentList;

        cout << left;
        cout << "=========================\n";
        cout << setw(10) << "Number";
        cout << setw(10) << "Student" << "\n";
        cout << "=========================\n";
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
        cout << "\n";

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
        cout << "\033[94mStudent Info:\033[0m" << endl;
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
                cout << "=======================================================" << endl;
                cout << setw(10) << "Number" << setw(20) << "Label" << setw(15) << "Information" << "\n";
                cout << "=======================================================" << endl;
                cout << setw(10) << "1" << setw(20) << "Name" << setw(15) << row[1] << "\n";
                cout << setw(10) << "2" << setw(20) << "Section" << setw(15) << row[2] << "\n"; 
                cout << setw(10) << "3" << setw(20) << "Program" << setw(15) << row[3] << "\n";
                cout << setw(10) << "4" << setw(20) << "Phone Number" << setw(15) << row[4] << "\n"; 
                cout << setw(10) << "5" << setw(20) << "Email" << setw(15) << row[5] << "\n";

                printStudent = false;
                break;
            }
        }

        students.close();
        cout << endl;

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
    string array[8] = {"Username", "Name", "Section", "Program", "ID Number", "Email", "Phone Number", "Password"};
    
    vector<string> row(8);
    string s;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    int i = 0;
    for (i; i < 8; i++){
        cout << "\033[94mAdd Student\033[0m" << endl;
        cout << "======================" << endl;

        for (int i = 0; i < 8; i++)
            cout << array[i] << ": " << row[i] << "\n";

        cout << endl;
        cout << "\033[31m[0]\033[0m Back" << endl;
        cout << "Enter " << array[i] << ": ";

        cout << "\033[32m";
        getline(cin, s); 
        cout << "\033[0m";

        if (s == "0") {
            string choice;
            cout << "Discard Changes? [\033[32m y \033[0m/\033[31m n \033[0m]";
            cout << "\033[32m";
            cin >> choice;
            cout << "\033[0m";

            if (choice == "y") break;
            else if (choice == "n"){
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cin.clear();

                cout << "\nEnter " << array[i] << ": ";
                getline(cin, s); 
                continue;
            }
            else {
                cout << "Invalid input. Try again." << endl;
                cout << "Discard Changes? [y/n]";
                cin >> choice;
            }
        }

        delayAnimation(150);
        row[i] = s;
    }

    copyCSVFile("students.csv", "temporary.csv");

    ifstream tempFile("temporary.csv");
    ofstream editFile("students.csv", ios::app);
    
    string readline;
    int currentRow = 0;

    string newline;
    std::stringstream updatedLine;
    for (int i = 0; i < 7; ++i){
        if (i > 0) updatedLine << ",";
        updatedLine << row[i];
    }
    newline = updatedLine.str();

    editFile << newline << "\n";
    editFile << "#,,,,,,"<< "\n";
    
    ofstream deleteTempFile("temporary.csv");

    editFile.close();
    tempFile.close();

    createAccount(row[0], row[7], row[1]);

    return 0;
}

void ReadCSV::createAccount(string username, string password, string name){
    copyCSVFile("accounts.csv", "temporary.csv");

    ifstream tempFile("temporary.csv");
    ofstream editFile("accounts.csv", ios::app);
    
    string readline;
    int currentRow = 0;

    Hashes hash1;
    string hashedPassword = hash1.pretendre_md5(password);

    string row[4] = {"1", username, hashedPassword, name};
    string newline;
    std::stringstream updatedLine;
    for (int i = 0; i < 4; ++i){
        if (i > 0) updatedLine << ",";
        updatedLine << row[i];
    }
    newline = updatedLine.str();

    editFile << newline << "\n";
    
    ofstream deleteTempFile("temporary.csv");

    editFile.close();
    tempFile.close();
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
