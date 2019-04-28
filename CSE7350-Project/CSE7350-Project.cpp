// CSE7350-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include "AdjacencyList.h"
#include "Course.h"
#include "CourseDistribution.h"
#include "CSVFile.h"
#include "SectionCreator.h"
#include "SectionConflictResolver.h"
#include "SmallestLastVertexOrdering.h"
#include "Student.h"

using namespace std;

void CommandLineInput(int &numberOfStudents,
					  int &numberOfCourses,
					  int &numberOfCoursesPerStudent,
					  int &sectionSize);
void Shuffle(Student *arr, size_t n);
void OutputResults(int numberOfStudents,
				   int numberOfCourses,
	               int numberOfCoursesPerStudent,
	               int sectionSize,
				   int distribution,
	               int split,
				   int distinctConflicts);

int main()
{
	bool execute = true;
	while (execute)
	{
		// 1) Input parameters
		int numberOfStudents, numberOfCourses, numberOfCoursesPerStudent, sectionSize = 0;

		CommandLineInput(numberOfStudents,
						 numberOfCourses,
						 numberOfCoursesPerStudent,
						 sectionSize);

		Student *students = new Student[numberOfStudents];
		for (int s = 0; s < numberOfStudents; s++)
		{
			students[s].EnrollStudent(s, numberOfCoursesPerStudent);
		}

//		Shuffle(students, numberOfStudents);

		Course *courses = new Course[numberOfCourses];
		int c = 1000;
		for (int currentCourse = 0; currentCourse < numberOfCourses; currentCourse++)
		{
			courses[currentCourse].SetCourseID(currentCourse);
		}


		// 1) Distribute classes to students (Inputs: # of students, # of courses, # of courses per student)
		cout << "Select Distribution: " << endl;
		cout << "1) Uniform Distribution" << endl;
		cout << "2) Two-Tier Distribution" << endl;
		cout << "3) Four-Tier Distribution" << endl;
		cout << "4) Custom Distribution" << endl;

		int whichDistribution = 0;
		cin >> whichDistribution;

		CourseDistribution distribution(students,courses,numberOfStudents,numberOfCourses);
		switch (whichDistribution)
		{
		case 1:
			distribution.UniformDistribution();
			break;

		case 2:
			distribution.TwoTierDistribution();
			break;

		case 3:
			distribution.FourTierDistribution();
			break;

		default:
			break;
		}

		for (int s = 0; s < numberOfStudents; s++)
		{
			std::cout << "Student ID: " << students[s].GetStudentId() << " ";
			for (int c = 0; c < students[s].GetNumberOfCourses(); c++)
			{
				std::cout << " " << students[s].GetCourseList()[c].GetCourseID() << "";
			}
			std::cout << std::endl;
		}
/*
		//Create Histogram
		csvfile csv("Histogram.csv");
		csv << "Course" << "Students" << endrow;
		int *histCourse = new int[numberOfCourses];
		for (int i = 0; i < numberOfCourses; i++)
		{
			histCourse[i] = 0;
		}

		for (int s = 0; s < numberOfStudents; s++)
		{
			for (int c = 0; c < students[s].GetNumberOfCourses(); c++)
			{
				histCourse[students[s].GetCourseList()[c].GetCourseID()]++;
			}
		}

		for (int i = 0; i < numberOfCourses; i++)
		{
			if ( histCourse[i] > 0 )
			{ 
				csv << i << histCourse[i] << endrow;
			}
		}
*/
		// 2) Sort Courses into sections
		SectionCreator creator(students, courses, numberOfStudents, numberOfCourses, static_cast<int>(sectionSize * 0.66), static_cast<int>(sectionSize * 1.33));
		numberOfCourses += creator.SimpleSectionSplit();

		SectionConflictResolver resolver(numberOfCourses);
		int distinctConflicts = resolver.CountDistinctConflicts(students, numberOfStudents);
		resolver.CreateAdjancencyList(students, numberOfStudents);

		AdjacencyList *adjList = resolver.GetList();

		SmallestLastVertexOrdering slvo(numberOfCourses, adjList);
		slvo.PrintVertices();

		OutputResults(numberOfStudents,
					  numberOfCourses,
				      numberOfCoursesPerStudent,
					  sectionSize,
					  whichDistribution,
					  1,
					  distinctConflicts);


		delete[numberOfStudents] students;
		students = NULL;

		delete[numberOfCourses] courses;
		courses = NULL;

		cout << "Conintue? (Q to exit)" << endl;
		char anyKey;
		cin >> anyKey;

		switch (anyKey)
		{
			case 'q':
				execute = false;
				break;

			default:
				break;
		}
	}

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

void Shuffle(Student *arr, size_t n)
{
	if (n > 1)
	{
		size_t i;
		srand(time(NULL));
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			Student t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}

void OutputResults(int numberOfStudents,
				   int numberOfCourses,
				   int numberOfCoursesPerStudent,
				   int sectionSize,
				   int distribution,
	               int split,
				   int distinctConflicts)
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

	cout << "    Numer Of Distinct Pair-Wise Section Conflicts: " << distinctConflicts << endl;
	int conflicts = numberOfCoursesPerStudent * (numberOfCoursesPerStudent - 1);
	int total = conflicts / 2;
	cout << "    Numer Of Total Pair-Wise Section Conflicts: " << numberOfStudents * total <<endl;
}
