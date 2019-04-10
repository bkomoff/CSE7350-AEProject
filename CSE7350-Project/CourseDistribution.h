#pragma once
#include <vector>

class Course;
class Student;

class CourseDistribution
{
	public:
		CourseDistribution();
		~CourseDistribution();

		void UniformDistribution(std::vector<Student*> &students,
								 std::vector<Course*> &courses, 
								 int numberOfCoursesPerStudent);
		void TwoTierDistribution(std::vector<Student*> &students,
								 std::vector<Course*> &courses, 
								 int numberOfCourses, 
								 int numberOfCoursesPerStudent);
		void FourTierDistribution(std::vector<Student*> &students,
								  std::vector<Course*> &courses, 
								  int numberOfCourses, 
							      int numberOfCoursesPerStudent);
};