#ifndef HELPER_H_
#define HELPER_H_
#include<vector>
#include<tuple>
#include <iostream>
class UserManager;
class Helper
{
public:
	static bool SearchVectorString(std::vector<std::string> v , std::string str_to_search);
//	std::pair<std::string, std::string> GetUserLoginInfo();
};
std::pair<std::string, std::string> GetUserLoginInfo();
std::tuple<std::string, std::string, std::string, std::string, bool> GetUserSignUpInfo();
void ManageAccessSystem(UserManager & m, std::string str);
bool WithinRange(int num ,int begin, int end);
void UpdateDoctorData();
#endif // !HELPER_H_
