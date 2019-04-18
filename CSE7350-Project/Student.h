#pragma once
#include <vector>

class Course;

class Student
{
	public:
		Student(int number);
		~Student();
		
		int GetStudentId() const { return studentID; }
		int GetNumberOfCourses() const { return courses.size(); }
		std::vector<Course*> GetCourseList() const { return courses; }

		bool AddCourse(Course &c);
		void RemoveCourse(Course &c);

	private:
		int studentID;
		std::vector<Course*> courses;
};