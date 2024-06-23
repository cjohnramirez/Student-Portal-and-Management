#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "readCSV.cpp"
using std::string;

class Utils : public ReadCSV
{
public:
    static Utils& getInstance()
    {
        if (!instance) instance = new Utils();
        return *instance;
    }

    int returnButton(int choice) override;
    void logout();
    void delayAnimation(double seconds) override;

    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
private:
    Utils() {};
    ~Utils() {};
    static Utils* instance;
    int choice;
};

#endif