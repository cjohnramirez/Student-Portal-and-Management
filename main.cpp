#include "tabulate.hpp"
#include "utils.cpp"
#include "login.cpp"
#include "student.cpp"
#include "admin.cpp"
#include "teacher.cpp"
#include <iostream>
using namespace std;

Utils* Utils::instance = nullptr; 

int main() {
    Utils& utilsMain = Utils::getInstance();

    Login user;
    string username, password;
    bool checkCredentials = true;

    while (checkCredentials) {
        if (user.startMenu() == 1)
            return(0);
    
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        string check = user.checkCredentials(username, password);
        cout << check << endl;

        if (check == "Login successful!") 
            checkCredentials = false; 
        else
            checkCredentials = true;

        utilsMain.delayAnimation(250);

        string accountType = user.getAccountType();
        string name = user.getName();

        if (!checkCredentials){
            if (accountType == "0"){
                Admin adminUser;
                checkCredentials = adminUser.adminMenu(name);
            } else if (accountType == "1"){
                Student studentUser; 
                checkCredentials = studentUser.studentMenu(name);
            } else if (accountType == "2") {
                Teacher teacherUser;
                checkCredentials = teacherUser.teacherMenu(name);
            } 
        }
    }
    
    return 0;
}