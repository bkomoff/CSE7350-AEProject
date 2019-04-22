#pragma once

class Course;
class Student;

class SectionCreator
{
	public:
		SectionCreator(Student *studentList,
					   Course *coursesList,
					   int studentTotal,
					   int courseTotal,
					   int minize,
					   int maxSize);
		~SectionCreator();

		void SimpleSectionSplit();

/*
		void SimpleSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);

		void AdvanceSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);
*/
	private:
		Student *students;
		Course *courses;
		int numberOfStudents;
		int numberOfCourses;
		int minSectionSize;
		int maxSectionSize;
};