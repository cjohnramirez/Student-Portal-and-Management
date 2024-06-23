#include "utils.h"
#include "login.h"
#include <windows.h>
#include <iostream>
using namespace std;

int Utils::returnButton(int choice) { 
    while (true) {
        cout << "[0] Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()){
            cout << "Not an integer. Try again." << endl;
            cin.clear();
            cin.ignore(256,'\n');
            continue;
        } else 
            break;
    }

    delayAnimation(250);
    return choice;
}

void Utils::logout() 
{
    delayAnimation(250);
    cout << "Redirecting to login page..." << endl;
    delayAnimation(250);
}

void Utils::delayAnimation(double seconds)
{
    Sleep(seconds);
    system("cls");
}