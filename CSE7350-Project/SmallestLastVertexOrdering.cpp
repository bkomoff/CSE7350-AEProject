#include "pch.h"
#include "Vertex.h"

#include "SmallestLastVertexOrdering.h"

SmallestLastVertexOrdering::SmallestLastVertexOrdering(int length)
{
	numberOfSessions = length;

	courses = new Vertex[numberOfSessions];
}

void SmallestLastVertexOrdering::CreateEdgeDegreeList(AdjacencyList const & currentSession)
{

}
