#pragma once

#include <list>
#include <vector>

class Course;
class Student;

class SectionConflictResolver
{
	public:
		SectionConflictResolver(std::vector<Course*> &courses);
		~SectionConflictResolver();

		int CountDistinctConflicts(std::vector<Student*> &students);
		void CreateAdjancenyList(std::vector<Student*> &students);
		void PrintNodes();

	private:
		struct Node
		{
			int section;
			int course;
		};

		int numberOfCourses;
		Node *verticies;
		std::vector< std::list<std::pair<Node,Node>>> edges;
};