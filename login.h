#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <fstream>
using std::string;

//add login features here, then define feature in login.cpp
class Login
{
public:
    string checkCredentials(const string& userName, const string& password); //reads input and searches file
    int getAccountType() const; //returns account type
private:
    int accountType;
};

#endif
