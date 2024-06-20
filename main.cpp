#include <iostream>
#include <windows.h>
#include "utils.cpp"
#include "login.cpp"
#include "student.cpp"
#include "admin.cpp"
using namespace std;

Utils utils1;

int main() {
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

        utils1.delayAnimation();

        string accountType = user.getAccountType();
        if (accountType == "0" && !checkCredentials){
            Admin adminUser(username);
            checkCredentials = adminUser.adminMenu();
        }
        else if (accountType == "1" && !checkCredentials){
            Student studentUser(username); 
            checkCredentials = studentUser.studentMenu();
        } else if (accountType == "2") {
            
        }
    }
    
    return 0;
}