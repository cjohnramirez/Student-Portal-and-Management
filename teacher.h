#ifndef TEACHER_H
#define TEACHER_H
#include <string>
using std::string;

//add teacher features
class Teacher {
public:
    bool teacherMenu(string name);
    int viewStudents();
    int teacherCourses();
private:
    int choice;
    string name;
};

#endif