#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <vector>
//class Assignment;
#include "Assignment.h"
class Course
{
public:
	Course();
	std::string name, code, Doctor , assignment_code;
	int num_of_sumbmitted_assignments = 0;
	int total_grades = 0;
	int total_max_grades = 0;
	int num_of_assignments = 0;
	std::vector<Assignment> assignments;
	Course(std::string name_, std::string code_, std::string Doctor_);//, std::string assignment_code
	std::string info();
	std::string fullreport();
	std::string fullreportDoc();
	void TotalGradeReportSingleCourse();
};
#endif
