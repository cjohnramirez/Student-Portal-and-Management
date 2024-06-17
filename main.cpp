#include <iostream>
#include <windows.h>
#include "login.cpp"
#include "student.cpp"
using namespace std;

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
            Sleep(750); system("cls");
        }
        else {
            checkCredentials = true; 
            Sleep(750); system("cls");
        }
        
        int accountType = user.getAccountType();
        if (accountType == 1 && !checkCredentials){
            Student studentUser(username); 
            studentUser.studentMenu();
            logout = studentUser.logout();
        }
    }
    
    return 0;
}