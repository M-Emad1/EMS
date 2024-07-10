#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_
#include <iostream>
class Assignment
{
public:
	std::string course_code , solution , solution_comment;
	bool is_submitted;
	int max_grade, grade;
	Assignment();
	Assignment(std::string course_code_, std::string solution_, int max_grade_, int grade_ = 0, bool is_submitted = false);
	void Submit_Solution();
	std::string report();
	std::string reportDoc();
	std::string solutionReport();
};
#endif
