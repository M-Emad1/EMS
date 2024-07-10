#ifndef  MENU_H_
#define MENU_H_
#include<iostream>
#include<vector>
#include "UserManager.h"
class Menu
{
public:
	std::string menu_name;
	std::vector<std::string> list;
	Menu(std::string menu_name_ , std::vector<std::string> list_);
	void ShowMenu();
	int GetChoice();
};
bool MethodCallSelector(Menu & menu , int &go_next , UserManager& usermgmt);
#endif // ! MENU_H_
