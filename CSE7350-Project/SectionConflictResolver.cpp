#include "pch.h"

#include "Course.h"
#include "ExecutionTimer.h"
#include "HashTable.h"
#include "HashSet.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(int courses)
{
	std::cout << "SectionConflictResolver" << std::endl;

	numberOfCourses = courses;

	verticies = new NodeList[numberOfCourses];

	for (int i = 0; i < numberOfCourses; i++)
	{
		verticies[i].head = NULL;
	}
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
			size_t currentCourse = CombieInts(students[s].GetCourseList()[c].GetCourseID(), students[s].GetCourseList()[c].GetSectionID());
			for (int i = index; i < students[s].GetNumberOfCourses(); i++)
			{
				size_t nextCourse = CombieInts(students[s].GetCourseList()[i].GetCourseID(), students[s].GetCourseList()[i].GetSectionID());
				size_t key = CombieInts(currentCourse, nextCourse);
				if (hash->GetValue(key) == -1)
				{
					hash->InsertNode(key, key);
					hash->InsertNode(CombieInts(nextCourse, currentCourse), CombieInts(nextCourse, currentCourse));
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

	HashMap *hash = new HashMap(numberOfCourses);
	for (int s = 0; s < numberOfStudents; s++)
	{
		int index = 1;
		for (int c = 0; c < students[s].GetNumberOfCourses(); c++)
		{
			size_t currentCourse = CombieInts(students[s].GetCourseList()[c].GetCourseID(), students[s].GetCourseList()[c].GetSectionID());
			for (int i = index; i < students[s].GetNumberOfCourses(); i++)
			{
				size_t nextCourse = CombieInts(students[s].GetCourseList()[i].GetCourseID(), students[s].GetCourseList()[i].GetSectionID());
				size_t key = CombieInts(currentCourse, nextCourse);
				if (hash->GetValue(key) == -1)
				{
					hash->InsertNode(key, key);
					hash->InsertNode(CombieInts(nextCourse, currentCourse), CombieInts(nextCourse, currentCourse));
					this->AddEdge(currentCourse, nextCourse);
				}
			}
			index++;
		}
	}
	timer.stop();

	delete hash;
	hash = NULL;

}

void SectionConflictResolver::AddEdge(size_t src, size_t dest)
{
	Node* newNode = CreateNode(dest);
	newNode->next = verticies[src].head;
	verticies[src].head = newNode;

	newNode = CreateNode(src);
	newNode->next = verticies[dest].head;
	verticies[dest].head = newNode;
}

SectionConflictResolver::Node *SectionConflictResolver::CreateNode(size_t course)
{
	Node* newNode = new Node;
	
	newNode->course = course;
	newNode->next = NULL;

	return newNode;
}

void SectionConflictResolver::PrintNodes()
{
	for (int i = 0; i < numberOfCourses; ++i)
	{
		Node *crawl = verticies[i].head;
		std::cout << "Vertex: " << i << std::endl;
		std::cout << "Head: ";
		while (crawl)
		{
			std::cout << " -> " << crawl->course;
			crawl = crawl->next;
		}
		std::cout << std::endl;
	}
}
