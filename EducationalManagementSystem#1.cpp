#include <iostream>
#include "UserManager.h"
#include <stack>
#include "Menu.h"
#include "DataLoader.h"

void RunSystem(std::vector<Menu> menus , std::stack<Menu> & s , int  go_next , UserManager& m)
{
	
	std::vector<Menu> menusloader = menus;
	int i = 1;
	int go_next_ = 0;
	s.push(menusloader[i]);
	while (true)
	{
		if (s.size() == 1)
			break;
		std::cout << std::endl;
		go_next_ = 0;
		if (!MethodCallSelector(s.top(), go_next_, m))
		{
			--i;
			s.pop();
			continue;
		}
		
		if (go_next_ == 1 && menusloader.size() > i)
			s.push(menusloader[++i]);
		

	}
	return;
}

	int main()
	{

		//logging in
		/*while (true)
		{
			if (!m.Login())
				continue;
			break;


		}*/
		/*m.current_student->ListMyCourses();
		m.current_student->RegisterInCourse();
		m.current_student->ListMyCourses();*/
		//m.current_student->ViewCourse();
		//m.current_student->ViewCourse();
		//m.current_student->ViewCourse();
		//m.current_student->ViewCourse();
		//m.current_student->ViewGradesReport();
		//std::cout << "1 - View Course\n2 -Register in Course\n 3 - List My courses\n4 - View Grades Report\n 5 - Exit\n";
		//while (true)
		//{
		//	std::cout << "Enter a choice: ";
		//	int choice;
		//	std::cin >> choice;
		//	if (choice == 1)
		//	{
		//		m.current_student->ViewCourse();
		//		m.current_student->UnregisterFromCourse();
		//	}
		//	if (choice == 2)
		//		m.current_student->RegisterInCourse();
		//	if (choice == 3)
		//		m.current_student->ListMyCourses();
		//	if (choice == 4)
		//		m.current_student->ViewGradesReport();
		//	if (choice == 5)
		//		break;

		//}





		//UserManager m;
		//std::vector<Menu> menusloader = dataloader.menusstudent;
		//int go_next = 0;
		//std::stack<Menu> s;
		//int i = 0;
		//s.push(menusloader[i]);
		//while (true)
		//{
		//	std::cout << std::endl;
		//	go_next = 0;
		//	if (!MethodCallSelector(s.top(), go_next, m))
		//	{
		//		--i;
		//		s.pop();
		//		continue;
		//	}
		//	if (m.current_doctor != nullptr && i == 0) //i will definetly increase to go to the second after the access menu
		//		i = 2;
		//	if (m.current_student != nullptr && i > 2)
		//		i = 2;
		//	if (go_next == 1 && menusloader.size() > i)
		//		s.push(menusloader[++i]);

		//	

		//}
		UserManager m;
		int go_next = 0;
		std::stack<Menu> s;
		while (true)
		{
			while (!s.empty())
				s.pop();
			s.push(dataloader.menusstudent[0]);
			MethodCallSelector(s.top(), go_next, m);
			if (m.current_student == nullptr)
			{
				s.pop();
				s.push(dataloader.menudoctor[0]);
				RunSystem(dataloader.menudoctor, s, go_next, m);
				continue;
			}
			else if (m.current_doctor == nullptr)
			{
				RunSystem(dataloader.menusstudent, s, go_next, m);
				continue;
			}
		}
}