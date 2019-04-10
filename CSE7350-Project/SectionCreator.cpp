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
				if (courses[i]->GetNumberOfStudents() > maxSectionSize)
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
}
