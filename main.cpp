#include <iostream>
#include <windows.h>
#include "utils.cpp"
#include "login.cpp"
#include "student.cpp"
using namespace std;

//errors need to be fixed: wrong file search and some loop malfunctions

Utils utils1;

int main() {
    Login user;
    string username, password;

    // loop feature of program
    bool checkCredentials = true;
    bool logout = false;
    string check;

    while (checkCredentials || logout) {
        if (user.startMenu() == 1)
            return(0);
    
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        check = user.checkCredentials(username, password);
        cout << check << endl;

        if (check == "Login successful!") {
            checkCredentials = false; 
            utils1.delayAnimation();
        }

        else {
            checkCredentials = true; 
            utils1.delayAnimation();
        }
        
        int accountType = user.getAccountType();
        if (accountType == 1 && !checkCredentials){
            Student studentUser(username); 
            bool loop = studentUser.studentMenu();
            if (loop) break;
        }
    }
    
    return 0;
}