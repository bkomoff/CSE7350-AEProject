#include "pch.h"

#include "Course.h"
#include "CSVFile.h"
#include "ExecutionTimer.h"
#include "Student.h"

#include "CourseDistribution.h"

CourseDistribution::CourseDistribution()
{}

CourseDistribution::~CourseDistribution()
{}

void CourseDistribution::UniformDistribution(std::vector<Student*> &students,
											 std::vector<Course*> &courses, 
											 int numberOfCoursesPerStudent)
{
	ExecutionTimer<std::chrono::milliseconds> timer;
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<> dis(0, courses.size() - 1);

	for (auto &st : students)
	{
		while (st->GetNumberOfCourses() < numberOfCoursesPerStudent)
		{
			int courseNumber = dis(generator);

			if (st->AddCourse(*courses.at(courseNumber)))
			{
				courses.at(courseNumber)->AddStudent(*st);
			}
		}
	}
	timer.stop();

	csvfile csv("UniformHistogram.csv");
	csv << "Course" << "Students" << endrow;
}

void CourseDistribution::TwoTierDistribution(std::vector<Student*> &students,
											 std::vector<Course*> &courses, 
											 int numberOfCourses, 
											 int numberOfCoursesPerStudent)
{
	std::default_random_engine generator;
	std::bernoulli_distribution distribution(0.5);

	std::random_device rand_dev;
	std::mt19937 generatorNumber(rand_dev());

	int first10PercentOfCourses = numberOfCourses * 0.1;
	int courseNumber = 0;
	ExecutionTimer<std::chrono::milliseconds> timer;
	for (auto &st : students)
	{
		while (st->GetNumberOfCourses() < numberOfCoursesPerStudent)
		{
			if (distribution(generator))
			{
				std::uniform_int_distribution<> dis(0, first10PercentOfCourses);
				courseNumber = dis(generatorNumber);
			}
			else
			{
				std::uniform_int_distribution<> dis(first10PercentOfCourses, (numberOfCourses - 1));
				courseNumber = dis(generatorNumber);
			}

			if (st->AddCourse(*courses.at(courseNumber)))
			{
				courses.at(courseNumber)->AddStudent(*st);
			}
		}
	}
	timer.stop();

	csvfile csv("TwoTierHistogram.csv");
	csv << "Course" << "Students" << endrow;
	for (auto it : courses)
	{
		csv << it->GetCourseID() << it->GetNumberOfStudents() << endrow;
	}
}

void CourseDistribution::FourTierDistribution(std::vector<Student*> &students,
											  std::vector<Course*> &courses, 
											  int numberOfCourses, 
											  int numberOfCoursesPerStudent)
{
	std::default_random_engine generator;
	std::bernoulli_distribution fortyPercentdistribution(0.4);
	std::bernoulli_distribution thirtyPercentdistribution(0.3);
	std::bernoulli_distribution twentyPercentdistribution(0.2);
	std::bernoulli_distribution tenPercentdistribution(0.1);

	std::random_device rand_dev;
	std::mt19937 generatorNumber(rand_dev());

	int firstTwentyFivePercent = numberOfCourses * 0.25;
	int secondTwentyFivePercent = numberOfCourses * 0.50;
	int thirdTwentyFivePercent = numberOfCourses * 0.75;

	ExecutionTimer<std::chrono::milliseconds> timer;
	for (auto &st : students)
	{
		while (st->GetNumberOfCourses() < numberOfCoursesPerStudent)
		{
			int courseNumber = -1;

			if (fortyPercentdistribution(generator))
			{
				std::uniform_int_distribution<> dis(0, (firstTwentyFivePercent - 1));
				courseNumber = dis(generatorNumber);
			}
			else if (thirtyPercentdistribution(generator))
			{
				std::uniform_int_distribution<> dis(firstTwentyFivePercent, (secondTwentyFivePercent - 1));
				courseNumber = dis(generatorNumber);
			}
			else if (twentyPercentdistribution(generator))
			{
				std::uniform_int_distribution<> dis(secondTwentyFivePercent, (thirdTwentyFivePercent - 1));
				courseNumber = dis(generatorNumber);
			}
			else if (tenPercentdistribution(generator))
			{
				std::uniform_int_distribution<> dis(thirdTwentyFivePercent, numberOfCourses - 1);
				courseNumber = dis(generatorNumber);
			}

			if (courseNumber > 0 && st->AddCourse(*courses.at(courseNumber)))
			{
				courses.at(courseNumber)->AddStudent(*st);
			}
		}
	}
	timer.stop();

	csvfile csv("FourTierHistogram.csv");
	csv << "Course" << "Students" << endrow;
	for (auto it : courses)
	{
		csv << it->GetCourseID() << it->GetNumberOfStudents() << endrow;
	}
}


