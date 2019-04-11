#include "pch.h"

#include "ExecutionTimer.h"
#include "Course.h"
#include "Student.h"

#include "SectionCreator.h"

SectionCreator::SectionCreator()
{}

SectionCreator::~SectionCreator()
{}

void SectionCreator::SimpleSectionSplit(std::vector<Course*> &courses, int minSectionSize, int maxSectionSize)
{
	ExecutionTimer<std::chrono::milliseconds> timer;
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i]->GetNumberOfStudents() > maxSectionSize)
		{
			int numberOfSections = courses[i]->GetNumberOfStudents() / minSectionSize;
			int numberOfStudentsPerSection = courses[i]->GetNumberOfStudents() / numberOfSections;

			for (int t = 1; t < numberOfSections; t++)
			{
				if (courses[i]->GetNumberOfStudents() > numberOfStudentsPerSection)
				{
					Course *newCourse = new Course(t, courses[i]->GetCourseID());

					int currentSectionSize = 0;
					for (auto &st : courses[i]->GetStudentList())
					{
						courses[i]->RemoveStudent(*st);
						newCourse->AddStudent(*st);

						st->RemoveCourse(*courses[i]);
						st->AddCourse(*newCourse);

						if (currentSectionSize == minSectionSize)
							break;

						currentSectionSize++;
					}

					courses.push_back(newCourse);
				}
			}
		}
	}
	timer.stop();
}

void SectionCreator::AdvanceSectionSplit(std::vector<Course*> &courses, int minSectionSize, int maxSectionSize)
{
	ExecutionTimer<std::chrono::milliseconds> timer;
	for (int i = 0; i < courses.size(); i++)
	{
		int numberOfSections = courses[i]->GetNumberOfStudents() / minSectionSize;
		for (int t = 1; t < numberOfSections; t++)
		{
			courses.push_back(new Course(t, courses[i]->GetCourseID()));
		}

		int numberOfStudentsPerSection = courses[i]->GetNumberOfStudents() / numberOfSections;
		int currentSectionSize = 0;
		for (auto &st : courses[i]->GetStudentList())
		{
			// Randomly place them in a section
			std::random_device rand_dev;
			std::mt19937 generator(rand_dev());
			std::uniform_int_distribution<> dis(0, numberOfSections);

			int sectionNumber = dis(generator);

			// If section number is 0 then they stay in course
			if (sectionNumber > 0)
			{
				courses[i]->RemoveStudent(*st);
				st->RemoveCourse(*courses[i]);

				// Find the section for the course
				std::vector<Course*>::reverse_iterator it,
														itEnd = courses.rend();
				bool found = false;
				for (it = courses.rbegin(); it != itEnd && !found; ++it)
				{
					Course* current = *it;
					if (sectionNumber == current->GetSectionID()) 
					{
						current->AddStudent(*st);
						st->AddCourse(*current);
						found = true;
					}
				}
			}
		}
	}
	timer.stop();

}
