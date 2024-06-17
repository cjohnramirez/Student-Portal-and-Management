#include <iostream>
#include "login.cpp"
using namespace std;

int main()
{
    Login user;
    cout << "Welcome!" << endl;
    string username, password;

    //check if account exists
    bool checkCredentials = true;
    while (checkCredentials)
    {
        cout << "Username: ";
        cin >> username;
        
        cout << "Password: ";
        cin >> password;

        string check = user.checkCredentials(username, password);
        cout << check << endl;

        if (check == "Login successful") checkCredentials = false;
        else checkCredentials = true;
    }

    //shifts account to appropriate classes
    return 0;
}