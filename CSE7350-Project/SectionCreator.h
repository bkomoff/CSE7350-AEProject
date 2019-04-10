#pragma once

class Course;
class Student;

class SectionCreator
{
	public:
		SectionCreator();
		~SectionCreator();

		void SimpleSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);

		void AdvanceSectionSplit(std::vector<Course*> &courses,
			int minSectionSize,
			int maxSectionSize);
};