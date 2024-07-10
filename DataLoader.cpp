#include "DataLoader.h"
Dataloader::Dataloader()
{
	students.push_back(new Student("mo832 1234 Mohamed moha@gmail.com 1", {"CS001" , "CS002" , "CS003"}));
	students.push_back(new Student("ahm123 4567 Ahmed ahmed435@gmail.com 2", {"CS001" , "CS005" , "CS004"}));
	students.push_back(new Student("mostafa423 1248 Mostafa mostafa4@gmail.com 3", {"CS002" , "CS006" , "CS004"}));
	mp_code_course.insert(std::pair<std::string, Course>("CS001", Course("Course Prog 1", "CS001", "Doc.Mohamed Reda" ))); // delete assignment code
	mp_code_course.insert(std::pair<std::string, Course>("CS002", Course("Course Prog 2", "CS002", "Doc.Mohamed Emad")));
	mp_code_course.insert(std::pair<std::string, Course>("CS003", Course("Course Math 1", "CS003", "Doc.Mostafa Saad")));
	mp_code_course.insert(std::pair<std::string, Course>("CS004", Course("Course Calculus 2", "CS004", "Doc.Mohamed Reda")));
	mp_code_course.insert(std::pair<std::string, Course>("CS005", Course("Course Stat 1", "CS005", "Doc.Ahmed Nader")));
	mp_code_course.insert(std::pair<std::string, Course>("CS006", Course("Course Ai 1", "CS006", "Doc.Hamed Walid")));
	assignments_total.push_back(Assignment("CS001", "", 45 , 10 , true));
	assignments_total.push_back(Assignment("CS001", "", 78 , 20 , true));
	assignments_total.push_back(Assignment("CS001", "", 15 , 30 , true));
	assignments_total.push_back(Assignment("CS001", "", 48 , 40 , true));
	assignments_total.push_back(Assignment("CS001", "", 98 , 50 , true));
	assignments_total.push_back(Assignment("CS002", "", 15));
	assignments_total.push_back(Assignment("CS002", "", 62));
	assignments_total.push_back(Assignment("CS003", "", 53));
	assignments_total.push_back(Assignment("CS003", "", 78));
	assignments_total.push_back(Assignment("CS004", "", 112));
	assignments_total.push_back(Assignment("CS005", "", 47));
	assignments_total.push_back(Assignment("CS006", "", 45));
	assignments_total.push_back(Assignment("CS001", "", 24));
	assignments_total.push_back(Assignment("CS004", "", 54));
	menusstudent.push_back(Menu("accessmenu", { "1 - Login " , "2 - SignUp" , "3 - Shutdown System" }));
	menusstudent.push_back(Menu("mainmenustudent", { "1 - Register in course " , "2 - List my courses" , "3 - View Course," , "4 - Grades Report" , "5 - Logout"}));
	menusstudent.push_back(Menu("coursemenu", {"1 - Unregister From Course" , "2 - Submit Solution" , "3 - Back"}));
	menudoctor.push_back(Menu("accessmenu", { "1 - Login " , "2 - SignUp" , "3 - Shutdown System" }));
	menudoctor.push_back(Menu("mainmenudoctor", { "1 - List Courses" , "2 - Create Course" , "3 - View Course" , "4 - Log out"}));
	menudoctor.push_back(Menu("courseviewmenu", { "1 - List Assignments" , "2 - Create Assignments" , "3 - View Assignments" ,"4 - back"}));
	menudoctor.push_back(Menu("assignmentviewmenu", {"1 - View Grades Report" , "2 - List Solutions" , "3 - View solutions" , "4 - back"}));
	menudoctor.push_back(Menu("solutionviewmenu", {"1 - Set Grade" , "2 - Set comment" , "3 - back"}));
	doctors.push_back(new Doctor("Mohamed32","4875", "Doc.Mohamed Mostafa", {"CS001"}));
	doctors.push_back(new Doctor("HM123", "4877", "Doc.Hamed Walid", {"CS002"}));
	doctors.push_back(new Doctor("AN124","5781", "Doc.Ahmed Nader", {"CS003"}));
	doctors.push_back(new Doctor("MR15","7881", "Doc.Mohamed Reda", {"CS004"}));
	doctors.push_back(new Doctor("ME458","6454", "Doc.Mohamed Emad", {"CS005"}));
	doctors.push_back(new Doctor("MS457","1545", "Doc.Mostafa Saad", {"CS006"}));
}

void Dataloader::FillUserManager(UserManager & usermgmt)
{
	for (auto& student : students)
	{
		usermgmt.mp_username_password[student->username] = student->password;
		usermgmt.mp_username_user[student->username] = student;
	
	}
	for (auto& doctor : doctors)
	{
		usermgmt.mp_username_password[doctor->username] = doctor->password;
		usermgmt.mp_username_doctor[doctor->username] = doctor;

	}

	for (auto& assignment : assignments_total)
	{
		mp_code_course[assignment.course_code].assignments.push_back(assignment);
	}
	for (auto& student : students)
	{
		for (auto& code : student->codes)
		{
			student->courses.push_back(mp_code_course[code]);
		}
	}

}
Doctor* Dataloader::FindDoctorByCourseCode(const std::string& course_code)
{
	for (auto& doctor : doctors)
	{
		if (std::find(doctor->codes.begin(), doctor->codes.end(), course_code) != doctor->codes.end())
		{
			return doctor;
		}
	}
	return nullptr;
}

 Dataloader dataloader = Dataloader();