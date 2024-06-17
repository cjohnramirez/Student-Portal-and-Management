#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <fstream>
using std::string;

//add login features here, then define feature in login.cpp
class Login
{
public:
    int startMenu(); //ofc a start menu, duhhh
    string checkCredentials(const string& userName, const string& password); //reads input and searches file
    int getAccountType() const; //returns account type
    int logout();
private:
    bool loop;
    int accountType;
};

#endif
