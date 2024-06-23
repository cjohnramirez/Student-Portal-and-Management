#include "login.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout, std::endl, std::cin;

Utils& utilsLogin = Utils::getInstance();

int Login::startMenu() //main menu of program
{
    while (true){
        cout << "Welcome!" << endl;
        cout << "[0] Exit Program" << endl;     
        cout << "[1] Continue Program" << endl;

        cout << "Enter choice: ";
        int choice;
        cin >> choice;     

        if (choice < 0 || choice > 1 || cin.fail()) {
            cout << "Invalid input. Try again."; 
            cin.clear();
            cin.ignore(256,'\n');
            
            utilsLogin.delayAnimation(500);
            continue;
        }

        if (choice == 0) {
            utilsLogin.delayAnimation(10);
            return 1;
        }
        else if (choice == 1) break;
    }

    return 0;     
}

string Login::checkCredentials(const string& username, const string& userpassword) { 
    std::fstream accounts;
    accounts.open("accounts.csv", std::ios::in);

    bool isFound = false;
    std::vector<string> row;
    string line, word;

    string accountType;

    while (getline(accounts, line) && !accounts.eof())
    {
        row.clear();
        std::stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word); 
        }

        if (row[1] == username && row[2] == userpassword){
            this->accountType = row[0];
            this->name = row[3];
            isFound = true;
            break;
        }
    }

    if (isFound)
        return "Login successful!";
    
    return "Invalid name or username. Please try again.";
}

string Login::getName() const {
    return name;
}

string Login::getAccountType() const { //check account type
    return accountType;
}