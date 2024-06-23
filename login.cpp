#include "login.h"
#include "utils.h"
#include "hashes.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout, std::endl, std::cin;

Utils& utilsLogin = Utils::getInstance();

int Login::startMenu() //main menu of program
{
    while (true){
        std::cout << "\033[94m" << R"(  ____  ____       __  __ 
 / ___||  _ \ __ _|  \/  |
 \___ \| |_) / _` | |\/| |
  ___) |  __/ (_| | |  | |
 |____/|_|   \__,_|_|  |_|
                          )" << "\033[0m" << std::endl;
        cout << "Student Portal & Management\n" << endl;
        cout << "\033[31m" << "[0]\033[0m Exit Program" << endl;     
        cout << "\033[32m" << "[1]\033[0m Continue Program" << endl;

        cout << "Enter choice: \033[32m";
        int choice;
        cin >> choice;  
        cout << "\033[0m";

        if (choice < 0 || choice > 1 || cin.fail()) {
            cout << "[Invalid input. Try again.]"; 
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

        Hashes hash2;

        if ((row[1] == username && row[2] == userpassword) || (row[1] == username && row[2] == hash2.pretendre_md5(userpassword))){
            this->accountType = row[0];
            this->name = row[3];
            isFound = true;
            break;
        }
    }

    if (isFound)
        return "\033[32m\n[Login successful!]\033[0m";
    
    return "\033[31m\n[Invalid name or username. Please try again.]\033[0m";
}

string Login::getName() const {
    return name;
}

string Login::getAccountType() const { //check account type
    return accountType;
}