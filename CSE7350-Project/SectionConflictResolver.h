#pragma once

#include <list>
#include <vector>

class Course;
class Student;

class SectionConflictResolver
{
	private:
		struct Node
		{
			size_t course;
			Node *next;
		};

		struct NodeList
		{
			Node *head;
		};

		void AddEdge(size_t src, size_t dest);
		Node *CreateNode(size_t sectionCourse);

	public:
		SectionConflictResolver(int courses);
		~SectionConflictResolver();

		int CountDistinctConflicts(Student *students, int numberOfStudents);
		void CreateAdjancencyList(Student *students, int numberOfStudents);
		void PrintNodes();

	private:
		int numberOfCourses;
		NodeList *verticies;
};