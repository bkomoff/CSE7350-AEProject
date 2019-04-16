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
			int sectionCourse;
			Node *prev;
		};

	public:
		SectionConflictResolver(std::vector<Course*> &courses);
		~SectionConflictResolver();

		int CountDistinctConflicts(std::vector<Student*> &students);
		void CreateAdjancenyList(std::vector<Student*> &students);
		void PrintNodes();

	private:

		void AddEdge(Node origin, Node dest);

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


		Node *verticies;
};