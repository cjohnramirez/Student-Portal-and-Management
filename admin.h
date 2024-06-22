#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using std::string;

//add admin features
class Admin {
public:
    bool adminMenu(string name);
    int manageStudent();
    int listSections();
    int listCourses(string sectionName);
    int listStudents(string sectionName, string courseName);

    int manageTeacher();
private:
    int choice;
};

#endif