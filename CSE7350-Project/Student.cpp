#include "pch.h"

#include "Course.h"

#include "Student.h"

Student::Student(int id):
	studentID(id)
{}

Student::~Student()
{}

bool Student::AddCourse(Course &c)
{
	bool alreadyTakingCourse = false;

	std::vector<Course*>::const_iterator it,
										 itEnd = courses.end();
	for (it = courses.begin(); it != itEnd && !alreadyTakingCourse; it++)
	{
		Course *currentCourse = *it;
		if ( currentCourse != NULL )
		{ 
			alreadyTakingCourse = currentCourse->GetSectionID() == c.GetSectionID() && currentCourse->GetCourseID() == c.GetCourseID();
		}
	}

	if (!alreadyTakingCourse)
	{ 
		courses.push_back(&c);
	}

	return !alreadyTakingCourse;
}

void Student::RemoveCourse(Course &c)
{
	bool deleteCourse = false;
	int i = 0;
	for (auto &it : courses)
	{
		deleteCourse = (it->GetCourseID() == c.GetCourseID()) &&
					   (it->GetSectionID() == c.GetSectionID());
		if (deleteCourse)
		{
			break;
		}
		i++;
	}

	if (deleteCourse)
	{
		courses.erase(courses.begin() + i);
	}
}
