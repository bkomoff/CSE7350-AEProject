#pragma once
#include <vector>

class Course;
class Student;

class SectionConflictResolver
{
	public:
		SectionConflictResolver(std::vector<Course*> courses);
		~SectionConflictResolver();

		int CountConflicts(std::vector<Student*> students);

	private:
		struct Node
		{
			int section;
			int course;
		};

		std::vector<Node> nodes;
};