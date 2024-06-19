#include "student.h"
#include "utils.h"
#include "admin.h"
#include <iostream>
#include <windows.h>
using std::cout, std::cin, std::endl;

Utils utils4;

Admin::Admin(const string& name)
{
    this->name = name;
}

