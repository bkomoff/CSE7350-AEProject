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
		verticies[i].sectionCourse  = 0;
		verticies[i].prev = NULL;
	}

	std::vector<Course*>::iterator it,
								   itEnd = courses.end();
	int i = 0;
	for (it = courses.begin(); it != itEnd; it++, i++)
	{
		Course *current = *it;
		verticies[i].sectionCourse = CombieInts(current->GetSectionID(), current->GetCourseID());

		if ( i > 0 )
		{ 
			verticies[i].prev = &verticies[i - 1];
		}
	}
}

SectionConflictResolver::~SectionConflictResolver()
{}

int SectionConflictResolver::CountDistinctConflicts(std::vector<Student*> &students)
{
	int numberOfDistinctSectionConflicts = 0;

	HashMap *hash = new HashMap(numberOfCourses);

	ExecutionTimer<std::chrono::milliseconds> timer;
	// Student A {0}, {11}, {2} ({0} - {11}, {0} - {2}, {11} - {2})
	// Student B {10}, {11}, {2} ({10} - {11}, {10} - {2}, {11} - {2})
	// 6 Total Conflicts
	// 5 Distinct Conflicts

	std::vector<Student*>::iterator st,
								   stEnd = students.end();
	for ( st = students.begin(); st != stEnd; ++st )
	{
		Student *currentStudent = *st;
	
		int index = 1;
		for (int courses = 0; courses < currentStudent->GetNumberOfCourses(); courses++ )
		{
			for (int i = index; i < currentStudent->GetNumberOfCourses(); i++)
			{
				int section = CombieInts(currentStudent->GetCourseList().at(courses)->GetSectionID(), currentStudent->GetCourseList().at(courses)->GetCourseID());

				if (hash->GetValue(hash->GetHashKey(section)) == -1)
				{ 
					int nextSection = CombieInts(currentStudent->GetCourseList().at(i)->GetSectionID(), currentStudent->GetCourseList().at(i)->GetCourseID());
					hash->InsertNode(section, nextSection);
					numberOfDistinctSectionConflicts++;
				}
			}
			index++;
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
		std::cout << "{" << verticies[i].sectionCourse << "}" << std::endl;
	}
}

void SectionConflictResolver::AddEdge(Node origin, Node dest)
{
}

