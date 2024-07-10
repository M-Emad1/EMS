#ifndef USER_MANAGER_H
#define USER_MANAGER_H
#include<map>
#include<iostream>
#include "Student.h"
#include "Doctor.h"
//class Student; //forward declaration
class UserManager
{
	
public:
	bool is_filled = false;
	std::map<std::string,std::string> mp_username_password;
	std::map<std::string, Student*> mp_username_user; //User is not yet implemented
	std::map<std::string, Doctor*> mp_username_doctor;
	Student* current_student;
	Doctor* current_doctor;
	
	UserManager();
	bool Login(const std::string& username, const std::string& password);
	void Logout();
	bool SignUp(const std::string& username, const std::string& password, const std::string& name, const std::string& email, const bool& is_doc);
};
#endif