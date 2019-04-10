// CSE7350-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Course.h"
#include "CourseDistribution.h"
#include "SectionCreator.h"
#include "SectionConflictResolver.h"
#include "Student.h"

using namespace std;

void CommandLineInput(int &numberOfStudents,
					  int &numberOfCourses,
					  int &numberOfCoursesPerStudent,
					  int &sectionSize);
void OutputResults(int numberOfStudents,
				   int numberOfCourses,
	               int numberOfCoursesPerStudent,
	               int sectionSize,
				   int distribution,
	               int split);

int main()
{
	// 1) Input parameters
	int numberOfStudents, numberOfCourses, numberOfCoursesPerStudent, sectionSize = 0;

	CommandLineInput(numberOfStudents, 
					 numberOfCourses, 
					 numberOfCoursesPerStudent, 
					 sectionSize);

	std::vector<Student*> students;
	for (int i = 0; i < numberOfStudents; i++)
	{
		students.push_back(new Student(i));
	}

	std::vector<Course*> courses;
	for (int i = 0; i < numberOfCourses; i++)
	{
		courses.push_back(new Course(0, i));
	}

	// 1) Distribute classes to students (Inputs: # of students, # of courses, # of courses per student)
	cout << "Select Distribution: " << endl;
	cout << "1) Uniform Distribution" << endl;
	cout << "2) Two-Tier Distribution" << endl;
	cout << "3) Four-Tier Distribution" << endl;
	cout << "4) Custom Distribution" << endl;

	int whichDistribution = 0;
	cin >> whichDistribution;

	CourseDistribution distribution;
	switch (whichDistribution)
	{
		case 1:
			distribution.UniformDistribution(students, courses, numberOfCoursesPerStudent);
		break;

		case 2:
			distribution.TwoTierDistribution(students, courses, numberOfCourses,numberOfCoursesPerStudent);
		break;

		case 3:
			distribution.FourTierDistribution(students, courses, numberOfCourses, numberOfCoursesPerStudent);
		break;

		default:
		break;
	}

	for (const auto st : students)
	{
		cout << "Student: " << st->GetStudentId() << endl;
		for (const auto it : st->GetCourseList())
		{
			cout << "Course: " << it->GetCourseID() << "(" << it << ")" << " Section: " << it->GetSectionID() << endl;
		}
	}

	// 2) Sort Courses into sections
	SectionCreator creator;
	creator.SimpleSectionSplit(courses, static_cast<int>(sectionSize * 0.66), static_cast<int>(sectionSize * 1.33));


	OutputResults(numberOfStudents,
				  numberOfCourses,
				  numberOfCoursesPerStudent,
				  sectionSize,
				  whichDistribution,
				  1);

	//for (const auto it : courses)
	//{
	//	cout << "Course: " << it->GetCourseID() << "(" << it << ")" <<  " Section: " << it->GetSectionID() << endl;
	//	for (const auto st : it->GetStudentList())
	//	{
	//		cout << "Student: " << st->GetStudentId() << endl;
	//	}
	//}


	cout << "Press Any Key to End" << endl;
	char anyKey;
	cin >> anyKey;

	return 0;
}

void CommandLineInput(int &numberOfStudents,
					  int &numberOfCourses,
					  int &numberOfCoursesPerStudent,
					  int &sectionSize)
{
	cout << "Enter Number of Students: " << endl;
	cin >> numberOfStudents;
	cout << "Enter Number of Courses: " << endl;
	cin >> numberOfCourses;
	cout << "Enter Number of Courses Per Student: " << endl;
	cin >> numberOfCoursesPerStudent;
	cout << "Enter Section Size: " << endl;
	cin >> sectionSize;
}

void OutputResults(int numberOfStudents,
				   int numberOfCourses,
				   int numberOfCoursesPerStudent,
				   int sectionSize,
				   int distribution,
	               int split)
{
	cout << "Final Results: " << endl;
	cout << "    Numer Of Students: " << numberOfStudents << endl;
	cout << "    Numer Of Courses: " << numberOfCourses<< endl;
	cout << "    Numer Of Courses Per Student: " << numberOfCoursesPerStudent<< endl;
	cout << "    Course Section Size: " << sectionSize<< endl;

	switch (distribution)
	{
	case 1:
		cout << "    Distribution: Uniform" << endl;
		break;

	case 2:
		cout << "    Distribution: Two-Tier" << endl;
		break;

	case 3:
		cout << "    Distribution: Four-Tier" << endl;
		break;

	case 4:
		cout << "    Distribution: Custom" << endl;
		break;

	default:
		break;
	}

	switch (split)
	{
	case 1:
		cout << "    Split: Simple" << endl;
		break;

	case 2:
		cout << "    Split: Advance" << endl;
		break;

	default:
		break;
	}

	cout << "    Numer Of Distinct Pair-Wise Section Conflicts: 0" << endl;
	int conflicts = numberOfCoursesPerStudent * (numberOfCoursesPerStudent - 1);
	int total = conflicts / 2;
	cout << "    Numer Of Total Pair-Wise Section Conflicts: " << numberOfStudents * total <<endl;

}
