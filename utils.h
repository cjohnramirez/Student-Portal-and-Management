#ifndef UTILS_H
#define UTILS_H
#include <string>
using std::string;

class Utils
{
public:
    static Utils& getInstance()
    {
        if (!instance) instance = new Utils();
        return *instance;
    }

    void studentGrades(string username);
    void studentInformation(string username);
    void studentsPerSection(string sectionName, string courseName, string teacherName);
    void modifyStudentGrades(string studentName, string courseName, int index, double grade);
    void modifyStudentInformation(string studentName, string toReplace, int index);
    void modifyAccount(string name, string newName);

    void copyCSVFile(const string& sourceFile, const string& tempFile);
    int returnButton(int choice);
    void logout();
    void delayAnimation(double seconds);

    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
private:
    Utils() {};
    ~Utils() {};
    static Utils* instance;
    int choice;
};

#endif