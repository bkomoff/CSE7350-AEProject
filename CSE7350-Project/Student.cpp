#include "pch.h"

#include "Course.h"

#include "Student.h"

Student::Student() :
	numberOfCourses(0)
{}

Student::~Student()
{}

void Student::EnrollStudent(int id, int courses)
{
	studentID = id;
	coursesPerStudent = courses;

	currentCourses = new Course[coursesPerStudent];
	for (int i = 0; i < coursesPerStudent; i++)
	{
		currentCourses[i].SetCourseID(-1);
	}
}

bool Student::AddCourse(int course, int section)
{
	bool found = false;

	int i = 0;
	for (; i < numberOfCourses && !found; i++)
	{
		found = currentCourses[i].GetCourseID() == course;
	}

	if (!found)
	{
		currentCourses[i].SetCourseID(course);
		numberOfCourses++;
	}

	return !found;
}