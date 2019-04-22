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

		size_t CombieInts(size_t a, size_t b)
		{
			// a = 1 b = 0 = 10
			// a = 10 b = 0 = 100 
			// a = 10 b = 987 = 10987
			// a = 8 b = 547 = 8547
			size_t times = 10;
			while (times <= b)
				times *= 10;
			return a * times + b;
		}

		NodeList *verticies;
};