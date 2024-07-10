#include "Assignment.h"
#include <sstream>
Assignment::Assignment() {

}
Assignment::Assignment(std::string course_code_, std::string solution_, int max_grade_, int grade_ , bool is_submitted_ )
{
	course_code = course_code_;
	solution = solution_;
	max_grade = max_grade_;
	grade = grade_;
	is_submitted = is_submitted_;

}
void Assignment::Submit_Solution()
{
	std::cout << "Enter the solution (no space):";
	std::cin >> solution;
	is_submitted = true;
}

std::string Assignment::report()
{
	/*std::string rep= "submitted - ";
	if (!is_submitted)
		rep = "NOT " + rep;
	if (grade == 0)
		rep += "NA";
	else
		rep += grade;
	rep += " / ";
	rep += max_grade;
	return rep;*/


	std::ostringstream oss;
	if (!is_submitted)
		oss << " NOT ";
	oss << "submitted - ";
	if (grade == 0)
		oss << "NA";
	else
		oss << (int)grade;
	oss << " / ";
	oss << (int)max_grade << std::endl;
	oss << "\tComment: ";
	if (solution_comment == "")
		oss << "Doctor hasn't commented on your solution";
	else
		oss << solution_comment;
	oss << std::endl;
	return oss.str();


}
std::string Assignment::reportDoc()
{
	std::ostringstream oss;
	oss << "Max grade: ";
	oss << (int)max_grade << std::endl;
	return oss.str();
}

std::string Assignment::solutionReport()
{
	std::ostringstream oss;
	oss << "Solution: ";
	if (solution == "")
		oss << "Didn't answer yet";
	else
		oss << solution;
	oss << "\n\tDoc's Comment: ";
	if (solution_comment == "")
		oss << "Doctor doesn't have a comment on your solution";
	else
		oss << solution_comment;

	return oss.str();

	//return "Solution: " + solution + "\n\tDoc's Comment: " + solution_comment;
}