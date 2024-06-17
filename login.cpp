#include "login.h"
#include "utils.h"
#include <iostream>
using std::cout, std::endl, std::cin;

Utils utils3;

int Login::startMenu() //main menu of program
{
    while (true){
        cout << "Welcome!" << endl;
        cout << "[0] Exit Program" << endl;     
        cout << "[1] Continue Program" << endl;

        cout << "Enter choice: ";
        int choice;
        cin >> choice;     

        if (choice == 0) {
            utils3.delayAnimation();
            return 1;
        }
        else if (choice == 1)
        {
            break;
        }
        else {
            cout << "Invalid input"; 
            utils3.delayAnimation();
            continue;
        }
    }

    return 0;     
}

string Login::checkCredentials(const string& userName, const string& userPassword) { //check if account exists
    string line;

    std::ifstream credentials;
    credentials.open("credentials.txt");

    while (getline(credentials, line)){
        size_t pos = line.find(userName) - 1;
        string accountType, name, password;
        
        while (credentials >> accountType >> name >> password) {
            this->accountType = std::stoi(accountType);
            if (name == userName && password == userPassword)
                return "Login successful!";
            else if (name != userName || password != userPassword)
                return "Wrong credentials, please try again";
            }
        }
    return 0;
    }

int Login::getAccountType() const { //check account type
    return accountType;
}
