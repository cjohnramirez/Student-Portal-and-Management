#include <iostream>
#include <windows.h>
#include "utils.cpp"
#include "login.cpp"
#include "student.cpp"
#include "admin.cpp"
#include "teacher.cpp"
using namespace std;

Utils* Utils::instance = nullptr; //Singleton design class

//main part of the program
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

        utilsMain.delayAnimation();

        string accountType = user.getAccountType();
        if (!checkCredentials){
            if (accountType == "0"){
                Admin adminUser(username);
                checkCredentials = adminUser.adminMenu();
            } else if (accountType == "1"){
                Student studentUser(username); 
                checkCredentials = studentUser.studentMenu();
            } else if (accountType == "2") {
                Teacher teacherUser(username);
                checkCredentials = teacherUser.teacherMenu();
            } 
        }
    }
    
    return 0;
}