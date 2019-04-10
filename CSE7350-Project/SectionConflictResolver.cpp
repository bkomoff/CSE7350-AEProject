#include "pch.h"

#include "Course.h"
#include "ExecutionTimer.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(std::vector<Course*> courses)
{
	for (auto it : courses)
	{
		Node node;
		node.section = it->GetSectionID();
		node.course = it->GetCourseID();
		nodes.push_back(node);
	}
}

SectionConflictResolver::~SectionConflictResolver()
{}

int SectionConflictResolver::CountConflicts(std::vector<Student*> students)
{
	int numberOfDistinctSectionConflicts = 0;

	ExecutionTimer<std::chrono::milliseconds> timer;
	for (auto st : students)
	{
	}
	timer.stop();

	return numberOfDistinctSectionConflicts;
}

