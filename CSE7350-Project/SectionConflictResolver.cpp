#include "pch.h"

#include "AdjacencyList.h"
#include "Course.h"
#include "ExecutionTimer.h"
#include "HashTable.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(int courses)
{
	std::cout << "SectionConflictResolver" << std::endl;

	numberOfCourses = courses;
	list = new AdjacencyList(numberOfCourses);
}

SectionConflictResolver::~SectionConflictResolver()
{}

int SectionConflictResolver::CountDistinctConflicts(Student *students, int numberOfStudents)
{
	int numberOfDistinctSectionConflicts = 0;

	HashMap *hash = new HashMap(numberOfCourses);

	for (int s = 0; s < numberOfStudents; s++)
	{
		int index = 1;
		for (int c = 0; c < students[s].GetNumberOfCourses(); c++)
		{
			size_t currentCourse = students[s].GetCourseList()[c].GetCourseID();
			for (int i = index; i < students[s].GetNumberOfCourses(); i++)
			{
				size_t nextCourse = students[s].GetCourseList()[i].GetCourseID();

				if (hash->GetValue(currentCourse) == -1 || hash->GetValue(nextCourse) == -1)
				{
					hash->InsertNode(currentCourse, nextCourse);
					hash->InsertNode(nextCourse, currentCourse);
					numberOfDistinctSectionConflicts++;
				}
			}
			index++;
		}
	}

	delete hash;
	hash = NULL;

	return numberOfDistinctSectionConflicts;
}

void SectionConflictResolver::CreateAdjancencyList(Student *students, int numberOfStudents)
{
	ExecutionTimer<std::chrono::milliseconds> timer;

	for (int s = 0; s < numberOfStudents; s++)
	{
		int index = 1;
		for (int c = 0; c < students[s].GetNumberOfCourses(); c++)
		{
			size_t currentCourse = students[s].GetCourseList()[c].GetCourseID();
			for (int i = index; i < students[s].GetNumberOfCourses(); i++)
			{
				size_t nextCourse = students[s].GetCourseList()[i].GetCourseID();
				list->AddEdge(currentCourse, nextCourse);
			}
			index++;
		}
	}
	timer.stop();
}

void SectionConflictResolver::RemoveConflicts()
{

}

void SectionConflictResolver::PrintNodes()
{
	list->PrintNodes();
}
