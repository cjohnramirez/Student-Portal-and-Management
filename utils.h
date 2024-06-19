#ifndef UTILS_H
#define UTILS_H
#include <string>
using std::string;

class Utils
{
public:
    int returnButton(int choice);
    void logout();
    void delayAnimation();
    void studentInfo(string username);
};

#endif