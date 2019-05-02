#include "pch.h"

#include "ExecutionTimer.h"
#include "Course.h"
#include "Student.h"

#include "SectionCreator.h"

SectionCreator::SectionCreator(Student *studentList,
							   Course *courseList,
							   int studentTotal,
						       int coursesTotal,
							   int minSize,
							   int maxSize):
	students(studentList),
	courses(courseList),
	numberOfStudents(studentTotal),
	numberOfCourses(coursesTotal),
	minSectionSize(minSize),
	maxSectionSize(maxSize)
{
	std::cout << "SectionCreator" << std::endl;
}

SectionCreator::~SectionCreator()
{}

int SectionCreator::SimpleSectionSplit()
{
	int sectionsAdded = 0;

	ExecutionTimer<std::chrono::milliseconds> timer;
	for (int c = 0; c < numberOfCourses; c++)
	{
		if (courses[c].GetNumberOfStudents() > maxSectionSize)
		{
			if (minSectionSize == 0)
			{
				minSectionSize = 1;
			}

			int numberOfSections = courses[c].GetNumberOfStudents() / minSectionSize;
			int student = 0;
			for (int section = 1; section < numberOfSections; section++)
			{
				bool nextSection = false;
				int currentSectionSize = 0;
				for (; student < numberOfStudents && !nextSection; student++)
				{
					bool found = false;
					for (int c = 0; c < students[student].GetNumberOfCourses() && !found; c++)
					{
						if (students[student].GetCourseList()[c].GetCourseID() == courses[c].GetCourseID())
						{
							students[student].GetCourseList()[c].SetCourseID(students[student].GetCourseList()[c].GetCourseID() + section);
							courses[c].RemoveStudent();
							currentSectionSize++;
							found = true;
						}
					}
					nextSection = currentSectionSize >= minSectionSize;
				}
				sectionsAdded++;
			}
		}
	}
	timer.stop();

	return sectionsAdded;
}

/*
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
	// In order to reduce timeslot conflicts, students should have a similar schedule
	// have a least 25% of the students who are taking the same courses be in the same section

	timer.stop();

}
*/