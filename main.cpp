#include <iostream>
#include "login.cpp"
#include "student.cpp"
using namespace std;

int main()
{
    Login user;
    string username, password;

    // loop feature of program
    bool checkCredentials = true;
    bool logout = false;
    string check;

    while (checkCredentials || logout)
    {
        cout << "Welcome!" << endl;
        
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        check = user.checkCredentials(username, password);
        cout << check << endl;
        if (check == "Login successful")
        {
            checkCredentials = false;
            system("cls");
        }
        else checkCredentials = true;

        int accountType = user.getAccountType();

        // shifts account to appropriate classes and loops back to start of while block if logout key is entered  
        if (accountType == 1 && !checkCredentials) // student
        {
            Student studentUser(username);
            studentUser.studentMenu();

            logout = studentUser.logout();
        }
    }
        
    return 0;
}