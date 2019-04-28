#include "pch.h"

#include "DLL.h"

#include "Vertex.h"

Vertex::Vertex():
	course(0),
	edgeList(NULL),
	edgeDegree(0),
	sameEdgeVertices(NULL)
{}

Vertex::~Vertex()
{}

void Vertex::CreateSameDegreeVertexDLL(int session)
{
	sameEdgeVertices = new DLL;
	sameEdgeVertices->Push(session);
}

void Vertex::PushSameDegreeVertexDLL(int session)
{
	sameEdgeVertices->Push(session);
}
