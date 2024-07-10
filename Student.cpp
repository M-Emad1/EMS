#include <sstream>
#include "Student.h"
#include "DataLoader.h"
#include "Helper.h"
Student::Student() 
{
	//id = -1;
	current_course = nullptr;
	
}
Student::Student(std::string line, std::vector<std::string> codes_)// line separated by space to use stringstream
{
	std::istringstream linein = std::istringstream(line);
	linein >> username >> password >> name >> email;
	codes = codes_;
	current_course = nullptr;
}  
Student::Student(std::string username_, std::string password_, std::string name_, std::string email_, std::vector<std::string> codes_)
{
	username = username_;
	password = password_;
	name = name_;
	email = email_;
	codes = codes_;
}
void Student::RegisterInCourse()
{
	//will choose from a list of courses (which should be a general one , or maybe a Course Manager?)
	std::cout << "Enter code of course: ";
	std::string code;
	std::cin >> code;
	if (dataloader.mp_code_course.find(code) == dataloader.mp_code_course.end()) {
		std::cout << "\nCourse not found.\n";
		return;
	}
	char c;
	std::cout << "\nAre you sure you want to enter "<< dataloader.mp_code_course[code].name << "?(Y/N):";
	std::cin >> c;
	if (std::tolower(c) == 'y')
	{
		courses.push_back(dataloader.mp_code_course[code]);
		codes.push_back(code);
		NotifyDoctorOfUpdate(code);
		std::cout << "\nregistered to Course successfully , good luck!\n";
		return;
	}
	std::cout << "\nDidn't register to the course.";
	return;

	
}
void Student::ListMyCourses()
{
	int i = 1;
	//that should be in the courses vector
	for (auto& course : courses)
		std::cout << i++ <<") " << course.info() << std::endl;
}
void Student::ViewCourse()
{
	//maybe show a menu object of the courses?
	int i;
	ListMyCourses();
	std::cout << "\n Which ith [1 - " << courses.size() <<"] course to view?: ";
	std::cin >> i;
	//check if i is within range
	if (WithinRange(i, 1, courses.size()))
	{
		std::cout << "\n" << courses[i - 1].fullreport();
		current_course = &courses[i - 1];
		return;
	}
	std::cout << "\nInvalid number!\n";
}
void Student::ViewGradesReport()
{
	//same as list courses but with some more information
	for (auto course : courses)
	{
		course.TotalGradeReportSingleCourse();
		std::cout << "Course Code " << course.code << " - Total submitted " << course.num_of_sumbmitted_assignments << " assignments - Grade " << course.total_grades << " / " << course.total_max_grades;
		std::cout << std::endl;
	}
}
void Student::UnregisterFromCourse()
{
	char choice;
	std::cout << "Are you sure you want to unregister from this course? (Y/N)?:";
	std::cin >> choice;
	if (std::tolower(choice) == 'y')
	{
		//delete from codes vector
		for (auto it = codes.begin(); it != codes.end();)
		{
			if (*it == current_course->code)
			{
				it = codes.erase(it);
				break;
			}
			else
				++it;
		}
		//delete from course vector
		for (auto it = courses.begin(); it != courses.end();)
		{
			if (it->code == current_course->code)
			{
				it = courses.erase(it);
				break;
			}
			else
				++it;
		}
		return;
	}
	std::cout << "\nunregistration canceled\n";
}
void Student::Print()
{
	std::cout << "Name: " << name << "\tEmail: " << email << "\tUsername: " << username;
}
void Student::submit_solution_assignment()
{
	int i;
	std::cout << "which ith " << "[1 - " << current_course->assignments.size() << "] assignment to submit ? : ";
	std::cin >> i;
	//Assignment& assignment = dataloader.mp_code_course[current_course->code].assignments[i - 1];
	Assignment& assignment = current_course->assignments[i - 1];
	assignment.Submit_Solution();
}

Course& Student::GetSpecificCourse(std::string code_)
{
	for (auto& course : courses)
	{
		if (course.code == code_)
		{
			return course;
		}

	}
}
bool Student::is_subscribed_to_course(std::string code_)
{
	for (const auto& code : codes)
	{
		if (code == code_)
			return true;
	}
	return false;
}

void Student::NotifyDoctorOfUpdate(const std::string &code)
{
	
		Doctor* doc = dataloader.FindDoctorByCourseCode(code);
		if (doc != nullptr)
			doc->UpdateStudentInfo();
	
}
