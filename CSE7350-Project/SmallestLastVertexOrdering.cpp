#include "pch.h"
#include "AdjacencyList.h"
#include "DLL.h"
#include "Vertex.h"

#include "SmallestLastVertexOrdering.h"

SmallestLastVertexOrdering::SmallestLastVertexOrdering(int length, AdjacencyList const *adj)
{
	adjList = adj;
	numberOfSessions = length;

	vertices = new Vertex[numberOfSessions];

	for (int i = 0; i < numberOfSessions; i++)
	{
		vertices[i].SetCourse(i);
		vertices[i].AddEdgeList(adjList->GetList()[i].head);
		vertices[i].SetEdgeDegree(adjList->GetDegree(i));
	}

	largestEdgeDegree = 0;
	for (int i = 0; i < numberOfSessions; i++)
	{
		if (vertices[i].GetEdgeDegree() > largestEdgeDegree)
		{
			largestEdgeDegree = vertices[i].GetEdgeDegree();
		}
	}

	edgeDegrees = new DLL*[largestEdgeDegree];

	for (int i = 0; i <= largestEdgeDegree; i++)
	{
		edgeDegrees[i] = new DLL;
	}

	for (int d = 1; d <= largestEdgeDegree; d++)
	{
		for (int i = 0; i < numberOfSessions; i++)
		{
			if (vertices[i].GetEdgeDegree() == d)
			{
				DLLNode *currentNode = edgeDegrees[d]->Push(vertices[i].GetCourse());
				if (currentNode->GetPrev() != NULL)
				{
					vertices[currentNode->GetPrev()->GetData()].SetNextEdge(currentNode);
					vertices[currentNode->GetData()].SetPreviousEdge(currentNode->GetPrev());
				}
			}
		}
	}

	deletedList = new int[numberOfSessions];
	for (int i = 0; i < numberOfSessions; i++)
	{
		deletedList[i] = 0;
	}
}

void SmallestLastVertexOrdering::ExecuteAlgorithm()
{
	int deletedIndex = 0;
	int currentDegree = 1;
	for (int i = 1; i <= largestEdgeDegree; i++)
	{
		if (edgeDegrees[i] != NULL)
		{
			// Grab the degree node (DLL)
			DLLNode const *node = edgeDegrees[i]->GetHead();
			while(node != NULL)
			{ 
				// From the DLL get the Edge List from the Adj List and loop through
				// the list to remove them from the DLL
				Vertex currentVertex = vertices[node->GetData()];
				AdjacencyNode *current = currentVertex.GetEdgeList();
				while (current != NULL)
				{
					if (!currentVertex.GetDeleted())
					{
						int course = currentVertex.GetCourse();
						int currentDegree = currentVertex.GetEdgeDegree();

						Vertex nextVertexInAdjList = vertices[course];
						int newDegree = currentDegree - 1;

						nextVertexInAdjList.SetEdgeDegree(newDegree);
						if (nextVertexInAdjList.GetEdgeDegree() == 0)
						{
							nextVertexInAdjList.Deleted();
						}

						// Remove vertex from the current degree DLL
						edgeDegrees[currentDegree]->Remove();

						// Push to the new degree DLL
						DLLNode *currentNode = edgeDegrees[newDegree]->Push(course);

						//Update the current vertex pointers
						int previous = currentNode->GetData();

//						vertices[previous].SetNextEdge
					}

					current = current->GetNext();
				}
				
				node = node->GetNext();
			}
		}
	}
}

void SmallestLastVertexOrdering::CreateSchedule()
{
	int color = 1;
	for (int i = 0; i < numberOfSessions; i++)
	{
		int currentDeleted = deletedList[i];
		if (i == 0)
		{
			vertices[currentDeleted].SetColor(color);
		}
		else
		{
			AdjacencyNode *node = vertices[currentDeleted].GetEdgeList();
		}
	}
}

void SmallestLastVertexOrdering::PrintVertices()
{
	adjList->PrintNodes();

	std::cout << std::endl;

	for (int i = 0; i < numberOfSessions; i++)
	{
		std::cout << "Vertex: " << i << std::endl;

		AdjacencyNode *crawl = vertices[i].GetEdgeList();
		while (crawl != NULL)
		{
			std::cout << " -> " << crawl->GetData();
			crawl = crawl->GetNext();
		}
	
		std::cout << std::endl;

		std::cout << "# of Degrees: " << vertices[i].GetEdgeDegree() << std::endl;

		std::cout << std::endl;

		if (vertices[i].GetPreviouisEdge() != NULL)
		{
			std::cout << "Previous Vertex: " << vertices[i].GetPreviouisEdge()->GetData() << std::endl;
		}
		if (vertices[i].GetNextEdge() != NULL)
		{ 
			std::cout << "Next Vertx: " << vertices[i].GetNextEdge()->GetData() << std::endl;
		}

		std::cout << std::endl;
	}
}