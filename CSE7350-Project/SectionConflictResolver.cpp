#include "pch.h"

#include "Course.h"
#include "ExecutionTimer.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(std::vector<Course*> &courses)
{
	verticies = new Node[courses.size()];
	for (int i = 0; i < courses.size(); i++)
	{
		verticies[i].course  = 0;
		verticies[i].section = 0;
	}

	std::vector<Course*>::iterator it,
								   itEnd = courses.end();
	int i = 0;
	for (it = courses.begin(); it != itEnd; it++, i++)
	{
		Course *current = *it;
		verticies[i].course = current->GetCourseID();
		verticies[i].section = current->GetSectionID();
	}
}

SectionConflictResolver::~SectionConflictResolver()
{}

int SectionConflictResolver::CountDistinctConflicts(std::vector<Student*> &students)
{
	int numberOfDistinctSectionConflicts = 0;

	ExecutionTimer<std::chrono::milliseconds> timer;
	for (auto st : students)
	{
		for (auto it : st->GetCourseList())
		{

		}
	}
	timer.stop();

	return numberOfDistinctSectionConflicts;
}

