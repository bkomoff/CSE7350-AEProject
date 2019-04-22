#pragma once

class Course;
class Student;

class CourseDistribution
{
	public:
		CourseDistribution(Student *studentList,
						   Course *coursesList,
						   int studentTotal,
						   int courseTotal);
		~CourseDistribution();

		void UniformDistribution();

		void TwoTierDistribution();

		void FourTierDistribution();
	private:
		Student *students;
		Course *courses;
		int numberOfStudents;
		int numberOfCourses;
};