#pragma once

class Course;
class Student;

class SectionCreator
{
	public:
		SectionCreator();
		~SectionCreator();

		void SimpleSectionSplit(Student *students,
								int numberOfStudents,
							    int numberOfCourses,
								int minSectionSize,
								int maxSectionSize);

/*
		void SimpleSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);

		void AdvanceSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);
*/
};