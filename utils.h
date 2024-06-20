#ifndef UTILS_H
#define UTILS_H
#include <string>
using std::string;

class Utils
{
public:
    static Utils& getInstance()
    {
        if (!instance){
            instance = new Utils();
        }
        return *instance;
    }

    int returnButton(int choice);
    void logout();
    void delayAnimation();
    void studentInfo(string username);

    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
private:
    Utils() {};
    ~Utils() {};
    static Utils* instance;
};

#endif