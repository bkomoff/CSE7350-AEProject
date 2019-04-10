#include "pch.h"
#include "Student.h"
#include "Course.h"

Course::Course(int section, int course):
	sectionID(section),
	courseID(course)
{}

Course::~Course() 
{}

void Course::AddStudent(Student &s)
{
	students.push_back(&s);
}

void Course::RemoveStudent(Student &s)
{
	bool deleteStudent = false;
	int i = 0;
	for (const auto &st : students)
	{
		deleteStudent = st->GetStudentId() == s.GetStudentId();
		if (deleteStudent)
		{
			break;
		}
		i++;
	}

	if (deleteStudent)
	{
		students.erase(students.begin() + i);
	}
}
