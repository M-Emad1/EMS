#include "Doctor.h"
#include "DataLoader.h"
#include "Helper.h"
Doctor::Doctor(std::string username_,std::string password_,std::string name_, std::vector<std::string> codes_)
{
	current_course = nullptr;
	current_assignment = nullptr;
	current_student = nullptr;
	name = name_;
	codes = codes_;
	username = username_;
	password = password_;
	FillRelatedData();
}
void Doctor::FillRelatedData()
{
	my_students.clear();
	for (auto& code : codes) //Cs001 cs002 cs003
	{
		mp_code_mycourse[code] = &dataloader.mp_code_course[code];
		mp_code_mycourse[code]->Doctor = name;
		for (auto& s : dataloader.students) //this method is a problem as student may be pushed more than once
		{
			if (Helper::SearchVectorString(s->codes, code))
			{
				//my_students.push_back(s);
				if (std::find(my_students.begin(), my_students.end(), s) == my_students.end())
				{
					my_students.push_back(s);
				}
			}
		}
	}

}

void Doctor::ListCourses()
{
	int i = 1;
	std::cout << "Courses You Are Teaching: \n\n";
	for (auto& code : codes)
		std::cout << i++ <<") " << mp_code_mycourse[code]->info() << std::endl;
}
void Doctor::CreateCourse()
{
	std::string code_temp;
	std::string name_temp;
	std::cout << "Enter The New Course Code:"; std::cin >> code_temp; std::cout << std::endl;
	std::cout << "Enter The New Course Name:"; std::cin >> name_temp; std::cout << "\nCourse Added Successfully!\n";
	dataloader.mp_code_course[code_temp] = Course(name_temp, code_temp, name);
	codes.push_back(code_temp);
	//some repition here , i can just recall FillRelatedData();
	mp_code_mycourse[codes.back()] = &dataloader.mp_code_course[codes.back()];
	//FillRelatedData();

}
void Doctor::ViewCourse()
{
	int i;
	ListCourses();
	std::cout << "\n Which ith [1 - " << codes.size() << "] course to view?: ";
	std::cin >> i;
	std::cout << "\n" << dataloader.mp_code_course[codes[i - 1]].info();
	//std::cout << "\n" << dataloader.mp_code_course[codes[i - 1]].info();
	current_course = &dataloader.mp_code_course[codes[i - 1]]; // i will use the code of this course to search for the specific course in student vector
	//current_course = mp_code_mycourse[codes[i - 1]]; // i will use the code of this course to search for the specific course in student vector
	//current_course->fullreport();
}

void Doctor::ListAssignments()
{
	std::cout<< current_course->fullreportDoc(); // ineed to list assignments only not the full report in the future
}
void Doctor::CreateAssignments()
{
	int max_grade;
	std::cout << "Enter max grade: ";
	std::cin >> max_grade;
	//Assignment assignment_to_load = 
	current_course->assignments.push_back(Assignment(current_course->code , "" , max_grade));
	//dataloader.mp_code_course[current_course->code].assignments.push_back();
}

void Doctor::ViewAssignments()
{
	ListAssignments();
	int i;
	std::cout << "\n Which ith [1 - " << current_course->assignments.size() << "] assignment to view?: ";
	std::cin >> i;
	std::cout << "\n" << current_course->assignments[i - 1].reportDoc();
	current_assignment = &current_course->assignments[i - 1];
	current_assignment_index = i - 1;
}

void Doctor::GradeReportAssignment() // needs to be modified
{
	//and here comes the student
	int i = 1;
	for (auto& student : my_students)
	{
		//i need to find the assignment
		int grade_std = student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].grade;
		int gradeM_std = student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].max_grade;
		std::cout << "Student " << i++ << " " << student->name << " ";// << grade_std << " / " << gradeM_std << std::endl;
		if (grade_std != 0)
			std::cout << grade_std;
		else
			std::cout << "NA";
		std::cout << " / " << gradeM_std << std::endl;
		

	}

	

}

void Doctor::ListSolutions() //needs to be modified
{
	int i = 1;
	for (auto& student : my_students)
	{
		//i need to find the assignment
		//int grade_std = student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].grade;
		//int gradeM_std = student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].max_grade;
		if (student->is_subscribed_to_course(current_course->code))
		{
			if(std::find(current_students_same_course.begin(), current_students_same_course.end() , student) == current_students_same_course.end())
			current_students_same_course.push_back(student);

			std::string solution_std = student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].solution;
			std::cout << "Student " << i++ << " " << student->name << "\t";// << grade_std << " / " << gradeM_std << std::endl;
			if (solution_std != "")
				std::cout << "Solution: " << solution_std;
			else
				std::cout << "Didn't submit a solution";

			std::cout << std::endl;
		}
		else
		{
			continue;
		}

	}
}

void Doctor::ViewSolutions()
{
	ListSolutions();
	int i;
	std::cout << "\n Which ith [1 - " << current_students_same_course.size() << "] solution to view?: "; //not all students are in the same course!
	std::cin >> i;
	current_student = current_students_same_course[i - 1]; //need to be modified
	std::cout << current_student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].solutionReport();
	//std::cout << "\n" << current_course->assignments[i - 1].;
	current_assignment = &current_course->assignments[i - 1];
	//current_assignment_index = i - 1;
}

void Doctor::SetGrade()
{
	std::cout << "Enter grade: ";
	int grade;
	std::cin >> grade;
	current_student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].grade = grade;
}

void Doctor::SetComment()
{
	std::cout << "Enter commnet: ";
	std::string commnet_str;
	std::cin >> commnet_str;
	current_student->GetSpecificCourse(current_course->code).assignments[current_assignment_index].solution_comment = commnet_str;
}
void Doctor::UpdateStudentInfo()
{
	FillRelatedData();
}

//void Doctor::UpdateStudentInfo(Student* student, const std::string& code_course_to_be_updated)
//{
//	auto& students_vector = my_students[code_course_to_be_updated];
//	if (std::find(students_vector.begin(), students_vector.end(), student) == students_vector.end())
//	{
//		// Student not found in vector, so add them
//		students_vector.push_back(student);
//	}
//	else
//	{
//		// Student already exists in vector, no need to add
//	}
//}
////or he is not a new register , then i will do nothing