#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <fstream>
using std::string;

//add login features here
class Login
{
public:
    int startMenu();
    string checkCredentials(const string& userName, const string& password);
    string getAccountType() const;
private:
    bool loop; 
    string accountType;
};

#endif