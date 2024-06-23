#ifndef READCSV_H
#define READCSV_H
#include <string>
using std::string;

class ReadCSV {
public:
    void studentGrades(string username);
    void studentInformation(string username);
    void studentsPerSection(string sectionName, string courseName, string teacherName);
    int listSections(int shift);
    int listCourses(string sectionName);
    int listStudents(string sectionName, string courseName);
    void modifyStudentGrades(string studentName, string courseName, int index, double grade);
    int listStudents(string courseName);
    int listStudentInformation(string studentName, string sectionName);
    void modifyStudentInformation(string studentName, string toReplace, int index);
    void modifyAccount(string name, string newName);
    void copyCSVFile(const string& sourceFile, const string& tempFile);

    virtual int returnButton(int choice) = 0;
    virtual void delayAnimation(double seconds) = 0;
protected:
    int choice;
    int shift;
};

#endif
