#include "utils.h"
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

bool Utils::logout(bool isTrue) //button to return at main menu
{
    delayAnimation();
    cout << "Redirecting to login page..." << endl;
    return isTrue;
}

void Utils::delayAnimation()
{
    Sleep(1350); 
    system("cls"); 
}