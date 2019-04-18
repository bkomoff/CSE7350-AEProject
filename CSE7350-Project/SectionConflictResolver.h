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
			int course;
			Node *next;
		};

		struct NodeList
		{
			Node *head;
		};


		void AddEdge(int src, int dest);
		Node *CreateNode(int sectionCourse);

	public:
		SectionConflictResolver(int courses);
		~SectionConflictResolver();

		int CountDistinctConflicts(std::vector<Student*> &students);
		void CreateAdjancencyList(std::vector<Student*> &students);
		void PrintNodes();

	private:
		int numberOfCourses;

		int CombieInts(int a, int b)
		{
			// a = 1 b = 0 = 10
			// a = 10 b = 0 = 100 
			// a = 10 b = 987 = 10987
			// a = 8 b = 547 = 8547
			int times = 10;
			while (times <= b)
				times *= 10;
			return a * times + b;
		}

		NodeList *verticies;
};