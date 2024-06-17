#include "login.h"

string Login::checkCredentials(const string& userName, const string& userPassword){
    int offset;
    string accountType, name, password;
    string line;

    std::ifstream credentials;
    credentials.open("credentials.txt");

    while (getline(credentials, line))
    {
        size_t pos = line.find(userName) - 1;
        if (pos != string::npos)
        {
            credentials >> accountType >> name >> password;
            this->accountType = std::stoi(accountType);
            if (name == userName && password == userPassword)
                return "Login successful";
            else if (name != userName || password != userPassword)
                return "Wrong credentials";
        }
    }
    return 0;
}

int Login::getAccountType() const{
    return accountType;
}
