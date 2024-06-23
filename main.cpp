#include "utils.cpp"
#include "login.cpp"
#include "student.cpp"
#include "admin.cpp"
#include "teacher.cpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <string>
using namespace std;

Utils* Utils::instance = nullptr; 
std::atomic<bool> stop_loading(false);

void loading_screen(int dots) {
    std::cout << "\e[?25l";
    if (stop_loading) return;

    std::string loading_text = "Loading";
    for (int i = 0; i < dots; ++i) {
        loading_text += ".";
    }
    std::cout << "\r" << loading_text << std::string(7 - dots, ' ') << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    loading_screen((dots % 3) + 1); 
    std::cout << "\e[?25h";
}

int main() {
    Utils& utilsMain = Utils::getInstance(); 

    std::thread loading_thread(loading_screen, 1);

    std::cout << "\033[94mPress Enter to start\033[0m" << std::endl;
    std::cin.get();

    utilsMain.delayAnimation(10);

    stop_loading = true;

    if (loading_thread.joinable()) {
        loading_thread.join();
    }

    Login user;
    string username, password;
    bool checkCredentials = true;

    while (checkCredentials) {
        if (user.startMenu() == 1)
            return(0);
    
        utilsMain.delayAnimation(10);

        cout << "\033[94m" << R"(  _                _       
 | |    ___   __ _(_)_ __  
 | |   / _ \ / _` | | '_ \
 | |__| (_) | (_| | | | | |
 |_____\___/ \__, |_|_| |_|
             |___/         
                          )" << "\033[0m" << std::endl;
        
        cout << "Username: \033[32m";
        
        cin >> username;
        cout << "\033[0mPassword: \033[32m";
        cin >> password;

        cout << "\033[0m";

        string check = user.checkCredentials(username, password);
        cout << check << endl;

        if (check == "\033[32m\n[Login successful!]\033[0m") 
            checkCredentials = false; 
        else
            checkCredentials = true;

        utilsMain.delayAnimation(400);

        string accountType = user.getAccountType();
        string name = user.getName();

        if (!checkCredentials){
            if (accountType == "0"){
                Admin adminUser;
                checkCredentials = adminUser.adminMenu(name);
            } else if (accountType == "1"){
                Student studentUser; 
                checkCredentials = studentUser.studentMenu(name);
            } else if (accountType == "2") {
                Teacher teacherUser;
                checkCredentials = teacherUser.teacherMenu(name);
            } 
        }
    }
    
    return 0;
}