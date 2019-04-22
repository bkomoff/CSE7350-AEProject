#pragma once
#include <vector>

class Course;
class Student;

class CourseDistribution
{
	public:
		CourseDistribution();
		~CourseDistribution();

		void UniformDistribution(Student *students,
								 int numberOfStudents,
								 int numberOfCourses);

		void TwoTierDistribution(Student *students,
								 int numberOfStudents,
								 int numberOfCourses);

		void FourTierDistribution(Student *students,
								  int numberOfStudents,
								  int numberOfCourses);
};