#include "pch.h"
#include "Vertex.h"

#include "SmallestLastVertexOrdering.h"

SmallestLastVertexOrdering::SmallestLastVertexOrdering(int length)
{
	numberOfSessions = length;

	courses = new Vertex[numberOfSessions];

	for (int i = 0; i < numberOfSessions; i++)
	{
		courses[i] = nullptr;
	}
}

void SmallestLastVertexOrdering::CreateEdgeDegreeList(AdjacencyList const & currentSession)
{

}
