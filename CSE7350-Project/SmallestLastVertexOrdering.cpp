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

		// DLL of vertices with same degree
		// Check previos session w/ same edge exist.
		bool found = false;
		
		for (int t = 0; t < i && !found; t++)
		{
			if (vertices[i].GetEdgeDegree() == vertices[t].GetEdgeDegree())
			{
				DLL &dllList = vertices[t].GetSameEdgeVerticesDLL();
				vertices[i].SetSameEdgeVertices(dllList);
				vertices[i].PushSameDegreeVertexDLL(i);
				found = true;
			}
		}
		
		if (!found)
		{
			vertices[i].CreateSameDegreeVertexDLL(i);
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

		vertices[i].GetSameEdgeVerticesDLL().PrintDLL();
		std::cout << std::endl;
		std::cout << std::endl;
	}
}