#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using std::string;

//add admin features
class Admin {
public:
    bool adminMenu(string name);
    int manageStudentGrades();
    int listSections();
    int listCourses(string sectionName);
    int listStudents(string sectionName, string courseName);
    
    int manageStudentInformation();
    int listStudents(string courseName);
    int listStudentInformation(string studentName, string sectionName);
private:
    int choice;
    int shift;
};

#endif