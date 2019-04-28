#pragma once

class AdjacencyNode;
class DLL;

class Vertex
{
	public:
		Vertex();
		~Vertex();

		void SetCourse(int currentCourse) { course = currentCourse; }
		void AddEdgeList(AdjacencyNode *list) { edgeList = list; }
		void SetEdgeDegree(int degree) { edgeDegree = degree; }
		void SetSameEdgeVertices(DLL &list) { sameEdgeVertices = &list; }

		int GetEdgeDegree() const { return edgeDegree; }
		AdjacencyNode *GetEdgeList() const { return edgeList; }
		DLL &GetSameEdgeVerticesDLL() const { return *sameEdgeVertices; }

		void CreateSameDegreeVertexDLL(int session);
		void PushSameDegreeVertexDLL(int session);

	private:
		int course;
		AdjacencyNode *edgeList;
		int edgeDegree;
		DLL *sameEdgeVertices;
};