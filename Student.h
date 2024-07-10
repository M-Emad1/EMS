#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include<vector>
#include "Course.h"
class Student
{
public:

	std::string username, password, name, email;
	//int id = -1;
	std::vector<std::string> codes;
	std::vector<Course> courses;
	Course *current_course;
	//vector of courses here
	Student();
	Student(std::string line , std::vector<std::string> codes_); // line separated by space to use stringstream
	Student(std::string username_, std::string password_, std::string name_, std::string email_, std::vector<std::string> codes_);
	void RegisterInCourse();
	void ListMyCourses();
	void ViewCourse();
	void ViewGradesReport();
	void Print();
	void UnregisterFromCourse();
	void submit_solution_assignment();
	bool is_subscribed_to_course(std::string code_);
	void NotifyDoctorOfUpdate(const std::string& code);
	Course& GetSpecificCourse(std::string code_);

};
#endif