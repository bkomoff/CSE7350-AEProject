#include "pch.h"

#include "Course.h"
#include "CSVFile.h"
#include "ExecutionTimer.h"
#include "Student.h"

#include "CourseDistribution.h"

CourseDistribution::CourseDistribution(Student *studentList,
									   Course *coursesList,
									   int studentTotal,
									   int courseTotal):
	students(studentList),
	courses(coursesList),
	numberOfStudents(studentTotal),
	numberOfCourses(courseTotal)
{
	std::cout << "CourseDistribution" << std::endl;
}

CourseDistribution::~CourseDistribution()
{}

void CourseDistribution::UniformDistribution()
{

	ExecutionTimer<std::chrono::milliseconds> timer;
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<> dis(0, numberOfCourses - 1);

	for (int i = 0; i < numberOfStudents; i++)
	{
		for ( int s = students[i].GetNumberOfCourses(); s < students[i].GetNumberOfCoursesPerStudent();)
		{
			int courseNumber = dis(generator);

			if (students[i].AddCourse(courseNumber))
			{
				students[i].GetCourseList()[s].AddStudent();
				courses[courseNumber].AddStudent();
				s++;
			}
		}
	}
	timer.stop();
}

void CourseDistribution::TwoTierDistribution()
{
	std::default_random_engine generator;
	std::bernoulli_distribution distribution(0.5);

	std::random_device rand_dev;
	std::mt19937 generatorNumber(rand_dev());

	int first10PercentOfCourses = numberOfCourses * 0.1;
	int courseNumber = 0;
	ExecutionTimer<std::chrono::milliseconds> timer;

	for (int i = 0; i < numberOfStudents; i++)
	{
		while (students[i].GetNumberOfCourses() < students[i].GetNumberOfCoursesPerStudent())
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

			students[i].AddCourse(courseNumber);
			courses[courseNumber].AddStudent();
		}
	}
	timer.stop();
}

void CourseDistribution::FourTierDistribution()
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
	for (int i = 0; i < numberOfStudents; i++)
	{
		while (students[i].GetNumberOfCourses() < students[i].GetNumberOfCoursesPerStudent())
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

			if (courseNumber > -1 )
			{
				students[i].AddCourse(courseNumber);
				courses[courseNumber].AddStudent();
			}
		}
	}
	timer.stop();
}