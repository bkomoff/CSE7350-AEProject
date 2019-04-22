#pragma once
#include <vector>

class Student;

class Course
{
	public:
		Course() { numberOfStudents = 0; };
		~Course() {};

		void SetSectionID(int id) { sectionID = id; }
		int GetSectionID() const { return sectionID; }
		void SetCourseID(int id) { courseID = id; }
		int GetCourseID() const { return courseID; }
		int GetNumberOfStudents() const { return numberOfStudents; }

		void AddStudent() { numberOfStudents++; }
		void RemoveStudent() { numberOfStudents--; }

	private:
		int courseID;
		int sectionID;
		int numberOfStudents;
};