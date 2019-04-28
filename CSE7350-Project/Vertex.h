#pragma once

class AdjacencyList;
class DLL;

class Vertex
{
	public:
		Vertex();
		~Vertex();

		void SetCourse(int currentCourse) { course = currentCourse; }
		void AddEdgeList(AdjacencyList *list) { edgeList = list; }
		void SetEdgeDegree(int degree) { edgeDegree = degree; }

	private:
		int course;
		AdjacencyList *edgeList;
		int edgeDegree;
		DLL *sameEdgeVertices;
};