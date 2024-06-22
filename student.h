#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;

//add student features
class Student
{
public:
    bool studentMenu(string name); //finished
    int viewInformation();
    int viewGrade();
private:
    int choice;
    string name;
};

#endif