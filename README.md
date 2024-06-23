# Student Portal and Management 
![image](https://github.com/cjohnramirez/Student-Portal-and-Management/assets/135854006/48093d68-8c3f-46f1-a10d-c6737e68a129)
A Computer Programming 2 Final Project in USTP-CDO's Department of Computer Science

## Features
![image](https://github.com/cjohnramirez/Student-Portal-and-Management/assets/135854006/69e694f1-29f8-4511-9964-5823b45c0b16)
- Looping Feature: Ability to back and logout anywhere from the program
- Security Measures: Protects passwords by using hashes
- Revamped, Modern CLI
### Student
![image](https://github.com/cjohnramirez/Student-Portal-and-Management/assets/135854006/fe7feac6-996c-466d-bebc-78347cd96578)
- Read Grades from Record
- Read Student Information
### Admin
![image](https://github.com/cjohnramirez/Student-Portal-and-Management/assets/135854006/79e4e011-961e-47b3-a783-bedff64d0be8)
- Edit Students' Grades
- Edit Students' Information
- Add Student Account and Information
### Teacher
![image](https://github.com/cjohnramirez/Student-Portal-and-Management/assets/135854006/4120fafc-ea39-4899-a782-41e4384d5bd7)
- Read Grades from Subjects

## Updates
(Beta 1.0)
- Adds back button, menus, and logout features
- Add four classes: Admin, Login, Student, and Teacher class
- Changes txt file to csv for efficient tabulation of records
- Creates feature to read student records

(Beta 2.0)
- Defined admin and teacher class, and their menus
- Applied Simpleton design in Utils class
- Finished all classes
- Reduced redundancy in major parts of the program

(Beta 3.0)
- Ability to see teacher's courses and sections, as well as individual grades
- Major fixes in several classes
- Added person class (implementation to be followed)

(Alpha 1.0)
- New Feature: Read Student Information
- Modifiable delay animation
- Added Tabulate header file for customization

(Alpha 1.1)
- New Feature: Modify Grade Per Section, Course, and Student

(Alpha 1.2)
- New Feature: Modify Student Information

(Alpha 2.0)
- Moved most functions that modify CSV to one file

(Alpha 3.0)
- Final Version: Revamped UI
- New Feature: Ability to Create Student Account
- New Feature: Hashes for Security

## Classes
### Login Class
Facilitates the start menus and logging in credentials, as well as logout
### Admin Class
The administrator of the program. Has the ability to modify grades, information, accounts, and add/drop students, subjects, and teachers
### Teacher Class
Ability to see grades, and in the future, add assignments and attendance
### Student Class
Ability to see one's grades, information, and in the future, assignments and attendance
### ReadCSV Class
The largest class, facilitates all read and write functions in CSV files. Used by most classes
### Utils Class
Inherits ReadCSV Class and adds functionalities like delayAnimation, logout, and return button
