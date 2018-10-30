#include <iostream>


#ifndef MARMOSET_TESTING
int main();
#endif

struct FullName
{
	std::string first_name;
	std::string middle_name;
	std::string last_name;
};



struct Student {
	float grade;
	int studentID;

	FullName full_name;

};


void stats(int num_students, Student students[], float & max_grade, int & max_studentID,
		float & min_grade, int & min_studentID);

#ifndef MARMOSET_TESTING
int main ()
{
	Student input_students[6] = {{92.0, 1230292},{19, 948421},{54.3, 34922},{21, 178234},{94.7, 392020},{58.2, 746821}};

	input_students[0].full_name.first_name = "Billy";
	input_students[1].full_name.first_name = "Ashley";

	int num_students = 6;
	float output_max_grade = 0;
	int output_max_studentID = 0;
	float output_min_grade = 0;
	int output_min_studentID = 0;


	stats(num_students, input_students, output_max_grade, output_max_studentID, output_min_grade,
			output_min_studentID);

	std::cout << " " << std::endl;

	std::cout << input_students[0].full_name.first_name << " has the max grade of " << output_max_grade  << "%"<< std::endl << " his student id is " << output_max_studentID;
	std::cout << std::endl;

	std::cout  << input_students[1].full_name.first_name << " has min grade of " << output_min_grade <<"%" << std::endl << " her student id is "  << output_min_studentID;
	std::cout << std::endl;


	return 0;
}
#endif


void stats(int num_students, Student students[], float & max_grade, int & max_studentID,
		float & min_grade, int & min_studentID)
{

	min_grade = 100;
	max_grade = 0;

	for(int student_index = 0; student_index < num_students; student_index++)
	{
		if(students[student_index].grade > max_grade)
		{
			max_grade = students[student_index].grade;
			max_studentID = students[student_index].studentID;
		}

		if (students[student_index].grade < min_grade)
		{
			min_grade = students[student_index].grade;
			min_studentID = students[student_index].studentID;

		}

	}


}
