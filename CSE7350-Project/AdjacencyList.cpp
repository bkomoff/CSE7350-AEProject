#include "pch.h"
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(size_t sizeOfList)
{
	this->sizeOfList = sizeOfList;

	list = new NodeList[sizeOfList];

	for (int i = 0; i < sizeOfList; i++)
	{
		list[i].head = nullptr;
	}
}

AdjacencyNode *AdjacencyList::CreateNode(size_t sectionCourse)
{
	AdjacencyNode *newNode = new AdjacencyNode;

	newNode->SetData(sectionCourse);
	newNode->SetNext(NULL);

	return newNode;
}

void AdjacencyList::AddEdge(size_t src, size_t dest)
{
	// Check for Duplicate
	if (!CheckForDuplicates(src, dest))
	{
		AdjacencyNode* newNode = CreateNode(dest);
		newNode->SetNext(list[src].head);
		list[src].head = newNode;

		newNode = CreateNode(src);
		newNode->SetNext(list[dest].head);
		list[dest].head = newNode;
	}
}

int AdjacencyList::GetDegree(size_t index) const
{
	int degree = 0;
	AdjacencyNode *crawl = list[index].head;
	while (crawl != NULL)
	{
		degree++;
		crawl = crawl->GetNext();
	}

	return degree;
}

void AdjacencyList::PrintNodes() const
{
	int count = 0;
	for (int i = 0; i < sizeOfList; ++i)
	{
		if (list[i].head != NULL)
		{
			int numberOfDegrees = 0;
			AdjacencyNode *crawl = list[i].head;
			std::cout << "Vertex: " << i;
			while (crawl != NULL)
			{
				numberOfDegrees++;
				count++;
				std::cout << " -> " << crawl->GetData();
				crawl = crawl->GetNext();
			}
			std::cout << " Degree: " << numberOfDegrees << std::endl;
		}
	}
	std::cout << "Adjacency List Length: " << count << std::endl;
}

bool AdjacencyList::CheckForDuplicates(size_t src, size_t dest)
{
	bool found = false;
	if (list[src].head != NULL)
	{
		AdjacencyNode *currentNode = list[src].head->GetNext();
		while (currentNode != NULL && !found)
		{
			found = currentNode->GetData() == dest;
			currentNode = currentNode->GetNext();
		}
	}

	return found;
}
