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
		currentCourses[i].SetSectionID(-1);
		currentCourses[i].SetCourseID(-1);
	}
}

bool Student::AddCourse(int course, int section)
{
	bool found = false;

	int i = 0;
	for (; i < numberOfCourses && !found; i++)
	{
		found = currentCourses[i].GetSectionID() == section &&
				currentCourses[i].GetCourseID() == course;
	}

	if (!found)
	{
		currentCourses[i].SetCourseID(course);
		currentCourses[i].SetSectionID(section);
		numberOfCourses++;
	}

	return !found;
}

bool Student::UpdateSection(int course, int section)
{
	bool found = false;

	int i = 0;
	for (; i < numberOfCourses && !found; i++)
	{
		found = currentCourses[i].GetCourseID() == course;
	}

	if (found)
	{
		currentCourses[i].SetSectionID(section);
	}

	return !found;
}
