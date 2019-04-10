#pragma once
#include <vector>

class Student;

class Course
{
	public:
		Course(int section, int course);
		~Course();

		int GetSectionID() const { return sectionID; }
		int GetCourseID() const { return courseID; }
		int GetNumberOfStudents() const { return students.size(); }
		std::vector<Student*> GetStudentList() const { return students; }

		void AddStudent(Student &s);
		void RemoveStudent(Student &s);

	private:
		int courseID;
		int sectionID;
		std::vector<Student*> students;
};