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

	list = new AdjacencyList(courses);

	//numberOfCourses = courses;

	//verticies = new NodeList[numberOfCourses];

	//for (int i = 0; i < numberOfCourses; i++)
	//{
	//	verticies[i].head = NULL;
	//}
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
//					this->AddEdge(currentCourse, nextCourse);
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
	//for (int i = 0; i < numberOfCourses; ++i)
	//{
	//	if (verticies[i].head != NULL)
	//	{
	//		Node *crawl = verticies[i].head;
	//		std::cout << "Vertex: " << i;
	//		while (crawl)
	//		{
	//			std::cout << " -> " << crawl->course;
	//			crawl = crawl->next;
	//		}
	//		std::cout << std::endl;
	//	}
	//}
}
