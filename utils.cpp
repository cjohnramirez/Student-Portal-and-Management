#include "utils.h"
#include "login.h"
#include "exceptions.cpp"
#include <windows.h>
#include <iostream>
using namespace std;

int Utils::returnButton(int choice) {
    while (true) {
        try {
            std::cout << "\033[31m[0]\033[0m Back" << std::endl;
            std::cout << "Enter your choice: \033[32m";
            std::cin >> choice;

            cout << "\033[0m";

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                throw std::invalid_argument("\033[31m[Not an integer. Try again.]\033[0m");
            }
            if (choice < 0 || choice > 9) {
                throw std::out_of_range("\033[31m[Choice out of valid range. Try again.]\033[0m");
            }
            break;

        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument error: " << e.what() << std::endl;
            delayAnimation(350); 
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range error: " << e.what() << std::endl;
            delayAnimation(350);
        }
    }

    delayAnimation(350);
    return choice;
}


void Utils::logout() 
{
    cout << "\033[32m[Redirecting to login page...]\033[32m" << endl;
    delayAnimation(350);
}

void Utils::delayAnimation(double seconds)
{
    Sleep(seconds);
    system("cls");
}