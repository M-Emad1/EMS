#include"UserManager.h"
#include "DataLoader.h"
#include<tuple>
UserManager::UserManager()
{
	//should include the dummydataloader to load dummy data into the mp_username_password map
	//mp_username_password.insert(std::pair<std::string, std::string>("s001", "s001"));
	//mp_username_password.insert(std::pair<std::string, std::string>("s002", "s002"));
	current_student = nullptr;
	current_doctor = nullptr;
	dataloader.FillUserManager(*this);
}
bool UserManager::Login(const std::string & username , const std::string& password)
{
	
	if (!mp_username_password.count(username))
	{
		std::cout << "\nNo Such Username!\n";
		return false;
	}
	
	if (mp_username_password[username] == password)
	{
		if (mp_username_user.count(username))
		{
			current_student = mp_username_user[username];
		std::cout << "\nWelcome " << current_student->name<<",You Are logged in\n\n";

		}
		else
		{
			current_doctor = mp_username_doctor[username];
			std::cout << "\nWelcome " << current_doctor->name << ",You Are logged in\n\n";
		}
		//current_student->Print();
		return true;
	}
	std::cout << "\nWrong Password!\n";
	return false;
}

void UserManager::Logout()
{
	current_student = nullptr;
	current_doctor = nullptr;
	//show the map of login again
	std::cout << "\nLog out Succeed , See you Later!\n";
}

bool UserManager::SignUp(const std::string& username, const std::string& password, const std::string& name, const std::string& email, const bool& is_doc)
{
	if (mp_username_password.count(username))
	{
		std::cout << "\nUsername Already Exists!\n";
		return false;
	}
	mp_username_password[username] = password;
	if (is_doc)
	{
		Doctor* new_doc = new Doctor(username, password, name, {});
		dataloader.doctors.push_back(new_doc);
		mp_username_doctor[username] = dataloader.doctors.back();
		current_doctor = mp_username_doctor[username];
	}
	else
	{
		Student* new_student = new Student(username, password, name, email, {});
		dataloader.students.push_back(new_student);
		mp_username_user[username] = dataloader.students.back();
		current_student = mp_username_user[username];
	}

}