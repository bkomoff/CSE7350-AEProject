#include "pch.h"

#include "Course.h"
#include "ExecutionTimer.h"
#include "HashTable.h"
#include "Student.h"

#include "SectionConflictResolver.h"

SectionConflictResolver::SectionConflictResolver(int courses)
{
	numberOfCourses = courses;

	verticies = new NodeList[numberOfCourses];

	for (int i = 0; i < numberOfCourses; i++)
	{
		verticies[i].head = NULL;
	}
}

SectionConflictResolver::~SectionConflictResolver()
{}

int SectionConflictResolver::CountDistinctConflicts(std::vector<Student*> &students)
{
	int numberOfDistinctSectionConflicts = 0;

	HashMap *hash = new HashMap(numberOfCourses);

	std::vector<Student*>::iterator st,
									stEnd = students.end();
	for (st = students.begin(); st != stEnd; ++st)
	{
		Student *currentStudent = *st;

		int index = 1;
		for (int courses = 0; courses < currentStudent->GetNumberOfCourses(); courses++)
		{
			int currentCourse = CombieInts(currentStudent->GetCourseList().at(courses)->GetCourseID(), currentStudent->GetCourseList().at(courses)->GetSectionID());

			for (int i = index; i < currentStudent->GetNumberOfCourses(); i++)
			{				
				int nextCourse = CombieInts(currentStudent->GetCourseList().at(i)->GetCourseID(), currentStudent->GetCourseList().at(i)->GetSectionID());
				int key = CombieInts(currentCourse, nextCourse);
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

void SectionConflictResolver::CreateAdjancencyList(std::vector<Student*> &students)
{
	ExecutionTimer<std::chrono::milliseconds> timer;

	HashMap *hash = new HashMap(numberOfCourses);

	std::vector<Student*>::iterator st,
		stEnd = students.end();
	for (st = students.begin(); st != stEnd; ++st)
	{
		Student *currentStudent = *st;

		int index = 1;
		for (int courses = 0; courses < currentStudent->GetNumberOfCourses(); courses++)
		{
			int currentCourse = CombieInts(currentStudent->GetCourseList().at(courses)->GetCourseID(), currentStudent->GetCourseList().at(courses)->GetSectionID());

			for (int i = index; i < currentStudent->GetNumberOfCourses(); i++)
			{
				int nextCourse = CombieInts(currentStudent->GetCourseList().at(i)->GetCourseID(), currentStudent->GetCourseList().at(i)->GetSectionID());
				int key = CombieInts(currentCourse, nextCourse);
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

void SectionConflictResolver::AddEdge(int src, int dest)
{
	Node* newNode = CreateNode(dest);
	newNode->next = verticies[src].head;
	verticies[src].head = newNode;

	newNode = CreateNode(src);
	newNode->next = verticies[dest].head;
	verticies[dest].head = newNode;
}

SectionConflictResolver::Node *SectionConflictResolver::CreateNode(int course)
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
