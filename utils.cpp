#include "utils.h"
#include "login.h"
#include <windows.h>
#include <iostream>
using std::cout, std::cin, std::endl;

int Utils::returnButton(int choice){ //button to return at student menu
    cout << "[0] Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    system("cls");
    return 1;
}

void Utils::logout() //button to return at main menu
{
    delayAnimation();
    cout << "Redirecting to login page..." << endl;
    delayAnimation();
}

void Utils::delayAnimation()
{
    Sleep(250);
    system("cls"); 
}