#include "pch.h"
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(size_t sizeOfList)
{
	this->sizeOfList = sizeOfList;

	list = new NodeList[sizeOfList];

	for (int i = 0; i < sizeOfList; i++)
	{
		list[i].head = NULL;
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
	AdjacencyNode* newNode = CreateNode(dest);
	newNode->SetNext(list[src].head);
	list[src].head = newNode;

	newNode = CreateNode(src);
	newNode->SetNext(list[dest].head);
	list[dest].head = newNode;
}

bool AdjacencyList::EdgeExist(size_t src, size_t dest)
{
	bool found = false;

	return found;
}

void AdjacencyList::PrintNodes()
{
	int count = 0;
	for (int i = 0; i < sizeOfList; ++i)
	{
		if (list[i].head != NULL)
		{
			AdjacencyNode *crawl = list[i].head;
			std::cout << "Vertex: " << i;
			while (crawl)
			{
				count++;
				std::cout << " -> " << crawl->GetData();
				crawl = crawl->GetNext();
			}
			std::cout << std::endl;
		}
	}
	std::cout << "Adjacency List Length: " << count << std::endl;
}
