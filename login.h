#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <fstream>
using std::string;

class Login
{
public:
    string checkCredentials(const string& userName, const string& password); //reads input and searches file
    int getAccountType() const; //returns account type
private:
    string password;
    string name;
    int accountType;
};

#endif
