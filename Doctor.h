#ifndef  DOCTOR_H_
#define DOCTOR_H_
#include <iostream>
#include<vector>
#include<map>
#include "Student.h"
class Course;
class Doctor
{
public:
	std::string name , username , password;
	std::vector<std::string> codes; //will be filled in data loader
	std::map<std::string, Course*> mp_code_mycourse;
	std::vector<Student*> my_students;
	std::vector<Student*> current_students_same_course;
	Course* current_course;
	Assignment* current_assignment;
	Student* current_student;
	int current_assignment_index;
	Doctor(std::string username_,std::string password_ ,std::string name_, std::vector<std::string> codes_);
	void FillRelatedData();
	void ListCourses();
	void CreateCourse();
	void ViewCourse();
	void ListAssignments();
	void CreateAssignments();
	void ViewAssignments();
	void GradeReportAssignment();
	void ListSolutions();
	void ViewSolutions();
	void SetGrade();
	void SetComment();
	//void UpdateStudentInfo(Student* student, const std::string& code_course_to_be_updated);
	void UpdateStudentInfo();
};

#endif // ! DOCTOR_H_

