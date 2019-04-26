#pragma once
#include <vector>

class Course;

class Student
{
	public:
		Student();
		~Student();
		
		void EnrollStudent(int id, int courses);

		int GetStudentId() const { return studentID; }
		int GetNumberOfCourses() const { return numberOfCourses; }
		int GetNumberOfCoursesPerStudent() const { return coursesPerStudent; }
		Course *GetCourseList() const { return currentCourses; }

		void SetStudentID(int id) { studentID = id; }
		bool AddCourse(int course, int section = 0);

	private:
		int studentID;
		int coursesPerStudent;
		int numberOfCourses;
		Course *currentCourses;
};