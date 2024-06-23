#include "login.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <string>
using std::cout, std::endl, std::cin;
using namespace tabulate;

Utils& utilsLogin = Utils::getInstance();

int Login::startMenu() //main menu of program
{
    while (true){
        utilsLogin.delayAnimation(500);

        std::setlocale(LC_ALL, "en_US.UTF-8");

        std::string text = u8"\n\n\n\t\033[94m░██████╗████████╗██╗░░░██╗██████╗░███████╗███╗░░██╗████████╗  ██████╗░░█████╗░██████╗░████████╗░█████╗░██╗░░░░░\n"
                       u8"\t██╔════╝╚══██╔══╝██║░░░██║██╔══██╗██╔════╝████╗░██║╚══██╔══╝  ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║░░░░░\n"
                       u8"\t╚█████╗░░░░██║░░░██║░░░██║██║░░██║█████╗░░██╔██╗██║░░░██║░░░  ██████╔╝██║░░██║██████╔╝░░░██║░░░███████║██║░░░░░\n"
                       u8"\t░╚═══██╗░░░██║░░░██║░░░██║██║░░██║██╔══╝░░██║╚████║░░░██║░░░  ██╔═══╝░██║░░██║██╔══██╗░░░██║░░░██╔══██║██║░░░░░\n"
                       u8"\t██████╔╝░░░██║░░░╚██████╔╝██████╔╝███████╗██║░╚███║░░░██║░░░  ██║░░░░░╚█████╔╝██║░░██║░░░██║░░░██║░░██║███████╗\n"
                       u8"\t╚═════╝░░░░╚═╝░░░░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚══╝░░░╚═╝░░░  ╚═╝░░░░░░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝\n";

        std::cout << text << "\n" << std::endl;
        
        
        std::cout << "\x1b[0m\t+";
        for (int i = 0; i < 109; ++i) {
            std::cout << "-";
            }
        std::cout << "+" << std::endl;
        
        cout << "\t|\t\t\t\t\t           \033[1mWelcome!\x1b[0m\t\t\t\t\t\t      |" << endl;
        cout << "\t|\t\t\t\t\t       \x1b[31m[0] Exit Program\x1b[0m\t\t\t\t\t\t      |"<< endl;     
        cout << "\t|\t\t\t\t\t     \x1b[32m[1] Continue Program\x1b[0m\t\t\t\t\t      |" << endl;
        
        std::cout << "\x1b[0m\t+";
        for (int i = 0; i < 109; ++i) {
            std::cout << "-";
            }
        std::cout << "+\n" << std::endl;


        Table table;
        
        table.add_row({"Welcome!\n[0] Exit Program\n[1] Continue Program"});

        table[0][0].format().width(118);
        table.column(0).format().font_align(FontAlign::center);
        std::cout << table << std::endl;
        
        //std::cout << "\n\n\x1b[0m\t+";
        //for (int i = 0; i < 109; ++i) {
        //    std::cout << "-";
        //    }
        //std::cout << "+" << std::endl;

        cout << "\t\t\t\t\t\t\x1b[1m   Enter choice: ";
        int choice;
        cin >> choice;
        
        //std::cout << "\x1b[0m\t+";
        //for (int i = 0; i < 109; ++i) {
            //std::cout << "-";
            //}
        //std::cout << "+\n" << std::endl;

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