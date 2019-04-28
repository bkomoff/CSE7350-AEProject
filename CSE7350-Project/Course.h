#pragma once

class Student;

class Course
{
	public:
		Course() { numberOfStudents = 0; };
		~Course() {};

		void SetCourseID(int id) { courseID = id; }
		int GetCourseID() const { return courseID; }
		int GetNumberOfStudents() const { return numberOfStudents; }

		void AddStudent() { numberOfStudents++; }
		void RemoveStudent() { numberOfStudents--; }

	private:
		int courseID;
		int numberOfStudents;
};