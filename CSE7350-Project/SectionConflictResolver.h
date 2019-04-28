#pragma once

class AdjacencyList;
class Student;

class SectionConflictResolver
{
	public:
		SectionConflictResolver(int courses);
		~SectionConflictResolver();

		int CountDistinctConflicts(Student *students, int numberOfStudents);
		void CreateAdjancencyList(Student *students, int numberOfStudents);
		void RemoveConflicts();
		void PrintNodes();

		AdjacencyList *GetList() const { return list; }

	private:
		int numberOfCourses;
		AdjacencyList *list;
};