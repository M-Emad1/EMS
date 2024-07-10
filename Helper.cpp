#include "Helper.h"
#include "UserManager.h"
bool  Helper::SearchVectorString(std::vector<std::string> v, std::string str_to_search)
{
	for (auto& e : v)
	{
		if (str_to_search == e)
			return true;
	}
	return false;
}

std::pair<std::string, std::string> GetUserLoginInfo()
{
	std::string username, password;
	std::cout << "Please Enter Username & Password:\nUsername: ";
	std::cin >> username;
	std::cout << "\nPassword: ";
	std::cin >> password;
	return { username , password };
}
std::tuple<std::string, std::string, std::string, std::string, bool> GetUserSignUpInfo()
{
	char t;
	std::string  username, password, name, email;
	bool is_doc = false;
	std::cout << "Please enter Fill the Info:\n";
	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "\nPassword: ";
	std::cin >> password;
	std::cout << "\nName: ";
	std::cin >> name;
	std::cout << "\nEmail: ";
	std::cin >> email;
	std::cout << "\nAre you a Doctor? (Y/N)?:";
	std::cin >> t;
	if (t == 'Y' || t == 'y')
		is_doc = true;

	return { username , password , name , email , is_doc };

}

void ManageAccessSystem(UserManager& m, std::string str)
{
	if (str == "Login")
	{
		while (true)
		{
			//auto [username , password] is called a structured binding (C++17)
			auto [username, password] = GetUserLoginInfo();
			if (!m.Login(username, password))
				continue;
			break;
		}
	}
	else
	{
		while (true)
		{
			auto [username, password, name, email, is_doc] = GetUserSignUpInfo();
			if (!m.SignUp(username, password, name, email, is_doc))
				continue;
			break;
		}

	}
}
bool WithinRange(int num, int begin, int end )
{
	if (num >= begin && num <= end)
		return true;
	return false;
}

