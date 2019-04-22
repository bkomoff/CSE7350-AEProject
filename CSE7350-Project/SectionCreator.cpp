#include "pch.h"

#include "ExecutionTimer.h"
#include "Course.h"
#include "Student.h"

#include "SectionCreator.h"

SectionCreator::SectionCreator()
{
	std::cout << "SectionCreator" << std::endl;
}

SectionCreator::~SectionCreator()
{}

void SectionCreator::SimpleSectionSplit(Student *students,
										int numberOfStudents,
										int numberOfCourses,
									    int minSectionSize, 
										int maxSectionSize)
{
	ExecutionTimer<std::chrono::milliseconds> timer;

	// 1) Build up how many students in each course
	Course *courses = new Course[numberOfCourses];

	for (int currentCourse = 0; currentCourse < numberOfCourses; currentCourse++)
	{
		courses[currentCourse].SetCourseID(currentCourse);
		courses[currentCourse].SetSectionID(0);

		for (int s = 0; s < numberOfStudents; s++)
		{
			bool found = false;
			for (int c = 0; c < students[s].GetNumberOfCourses() && !found; c++)
			{
				if (students[s].GetCourseList()[c].GetCourseID() == courses[currentCourse].GetCourseID())
				{
					courses[currentCourse].AddStudent();
					found = true;
				}
			}
		}
	}

	//2) Divide Students Amoung Courses
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
						if (students[student].GetCourseList()[c].GetCourseID() == courses[c].GetCourseID() &&
							students[student].GetCourseList()[c].GetSectionID() != section)
						{
							students[student].GetCourseList()[c].SetSectionID(section);
							courses[c].RemoveStudent();
							currentSectionSize++;
							found = true;
						}
					}

					nextSection = currentSectionSize >= minSectionSize;
				}
			}
		}
	}
	timer.stop();
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