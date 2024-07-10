#include "Course.h"
#include <sstream>
//Course::Course(std::string line)
//{
//	std::istringstream linein(line);
//	linein >> name >> code >> Doctor;
//}
Course::Course()
{

}
Course::Course(std::string name_ , std::string code_ , std::string Doctor_)// , std::string assignment_code_
{
	name = name_;
	code = code_;
	Doctor = Doctor_;
	//assignment_code = assignment_code_;
}
std::string Course::info()
{
	return name + " - Code " + code +"\n";
}
std::string Course::fullreport()
{
	std::ostringstream oss;
	int i = 1;
	//return name + " with code " + code + " - taught by " + Doctor + "\nCourse has assignments\n";
	oss << name << " with code " << code << " - taught by " << Doctor + "\nCourse has " << assignments.size() << " assignments\n";
	for (auto& Assignment : assignments)
	{
		oss << std::endl << "Assignment "<< i++ <<" " << Assignment.report();
	}
	return oss.str();

}
std::string Course::fullreportDoc()
{
	std::ostringstream oss;
	int i = 1;
	//return name + " with code " + code + " - taught by " + Doctor + "\nCourse has assignments\n";
	oss << name << " with code " << code << " - taught by " << Doctor + "\nCourse has " << assignments.size() << " assignments\n";
	for (auto& Assignment : assignments)
	{
		oss << std::endl << "Assignment " << i++ << " " << Assignment.reportDoc();
	}
	return oss.str();
}
void Course::TotalGradeReportSingleCourse()
{
	for (auto& assignment : assignments)
	{
		total_grades += assignment.grade;
		total_max_grades += assignment.max_grade;
		if (assignment.is_submitted)
			num_of_sumbmitted_assignments++;
	}
}