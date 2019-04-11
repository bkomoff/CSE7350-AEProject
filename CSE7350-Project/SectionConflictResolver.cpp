#include "pch.h"

#include "Course.h"
#include "ExecutionTimer.h"
#include "HashTable.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(std::vector<Course*> &courses)
{
	numberOfCourses = courses.size();

	verticies = new Node[numberOfCourses];
	for (int i = 0; i < numberOfCourses; i++)
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
	// Student A {0,0}, {1,1}, {0,2} ({0,0} - {1,1} {0,0} - {0,2} {1,1} - {0,2})
	// Student B {1,0}, {1,1}, {0,2} ({1,0} - {1,1} {1,0} - {0,2} {1,1} - {0,2})
	// 6 Total Conflicts
	// 5 Distinct Conflicts

	for (auto st : students)
	{
		int numberOfCourses = st->GetNumberOfCourses();
		int index = 0;
		std::vector<Course*>::iterator it,
									   itEnd = st->GetCourseList().end();
		for (it = st->GetCourseList().begin(); it != itEnd; ++it)
		{

		}
	}

	timer.stop();

	return numberOfDistinctSectionConflicts;
}

void SectionConflictResolver::CreateAdjancenyList(std::vector<Student*>& students)
{
	// For Each Student
	// Go through their classes and create an edge for each course taking

}

void SectionConflictResolver::PrintNodes()
{
	for (int i = 0; i < numberOfCourses; i++)
	{
		std::cout << "{" << verticies[i].section << "," << verticies[i].course << "}" << std::endl;
	}
}

