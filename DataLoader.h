#ifndef DATA_LOADER_H
#define DATA_LOADER_H
#include <iostream>
#include<vector>
#include "Student.h"
#include "Menu.h"
#include "UserManager.h"
#include"Course.h"
#include "Assignment.h"
#include<map>
#include "Doctor.h"
class Dataloader
{

public:
	std::vector<Student*> students;
	std::map<std::string,Course> mp_code_course;
	std::vector<Assignment> assignments_total;
	std::vector<Menu>  menusstudent;
	std::vector<Menu> menudoctor;
	std::vector<Doctor*> doctors;
	Doctor* FindDoctorByCourseCode(const std::string& course_code);
	Dataloader();
	void FillUserManager(UserManager& usermgmt);

};
extern Dataloader dataloader;
#endif
