#include "Menu.h"
#include "Helper.h"
//#include "UserManager.h"
Menu::Menu(std::string menu_name_, std::vector<std::string> list_)
{
	list = list_;
	menu_name = menu_name_;
}
void Menu::ShowMenu()
{
	std::cout << "please Make a Choice:\n\n";
	int i = 1;
	for (auto& option : list)
		std::cout << i++ << ") " << option << "\n\n";
}
int Menu::GetChoice()
{
	ShowMenu();
		int choice;
	while (true)
	{
		std::cout << "Enter choice: ";
		std::cin >> choice;
		if (choice < 1 || choice > list.size())
			continue;
		std::cout << std::endl;
		break;
	}
	return choice;
}
bool MethodCallSelector(Menu& menu, int& go_next , UserManager& usermgmt)
{
	int choice = menu.GetChoice();
	go_next = 0;
	//needs to be recoded to be non-case sensetive
		if (menu.menu_name == "accessmenu")
		{
			if (choice == 1)
			{
				ManageAccessSystem(usermgmt, "Login");
				go_next = 1;
				return true;
			}
			if (choice == 2)
			{		
				ManageAccessSystem(usermgmt, "SignUp");
				go_next = 1;
				return true;
			}
			if (choice == 3)
				std::cout << "\nnothing here\n";
		}
	if (usermgmt.current_student != nullptr)
	{
		if (menu.menu_name == "mainmenustudent")
		{
			if (choice == 1)
			{
				usermgmt.current_student->RegisterInCourse();
				return true;
			}
			if (choice == 2)
			{
				usermgmt.current_student->ListMyCourses();
				return true;
			}
			if (choice == 3)
			{
				usermgmt.current_student->ViewCourse();
				go_next = 1;
				return true;
			}
			if (choice == 4)
			{
				usermgmt.current_student->ViewGradesReport();
				return true;
			}
			if (choice == 5)
			{
				usermgmt.current_student = nullptr;
				return false;
			}
		}
		if (menu.menu_name == "coursemenu")
		{
			if (choice == 1)
			{
				usermgmt.current_student->UnregisterFromCourse();
				return false;
			}
			if (choice == 2)
			{
				usermgmt.current_student->submit_solution_assignment();
				return true;
			}
			if (choice == 3)
			{
				return false;
			}

		}
	}
	else
	{
		if (menu.menu_name == "mainmenudoctor")
		{
			if (choice == 1)
			{
				usermgmt.current_doctor->ListCourses();
				return true;
			}
			if (choice == 2)
			{
				usermgmt.current_doctor->CreateCourse();
				return true;
			}
			if (choice == 3)
			{
				usermgmt.current_doctor->ViewCourse();
				go_next = 1;
				return true;
			}
			if (choice == 4)
			{
				usermgmt.current_doctor = nullptr;
				return false;
			}
		}
		if (menu.menu_name == "courseviewmenu")
		{
			if (choice == 1)
			{
				usermgmt.current_doctor->ListAssignments();
				return true;
			}
			if (choice == 2)
			{
				usermgmt.current_doctor->CreateAssignments();
				return true;
			}
			if (choice == 3)
			{
				usermgmt.current_doctor->ViewAssignments();
				go_next = 1;
				return true;
			}
			if (choice == 4)
			{
				return false;
			}
		}
		if (menu.menu_name == "assignmentviewmenu")
		{
			if (choice == 1)
			{
				usermgmt.current_doctor->GradeReportAssignment();
				return true;
			}
			if (choice == 2)
			{
				usermgmt.current_doctor->ListSolutions();
				return true;
			}
			if (choice == 3)
			{
				usermgmt.current_doctor->ViewSolutions();
				go_next = 1;
				return true;
			}
			if (choice == 4)
			{
				return false;
			}
		}
		if (menu.menu_name == "solutionviewmenu")
		{
			if (choice == 1)
			{
				usermgmt.current_doctor->SetGrade();
				return true;
			}
			if (choice == 2)
			{
				usermgmt.current_doctor->SetComment();
				return true;
			}
			if (choice == 3)
			{
				return false;
			}
		}
	}
	return true;
}
