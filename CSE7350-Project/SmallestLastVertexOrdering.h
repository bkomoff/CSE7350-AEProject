#pragma once

class AdjacencyList;
class DLL;
class Vertex;

class SmallestLastVertexOrdering
{
	public:
		SmallestLastVertexOrdering(int length, AdjacencyList const *adj);
		~SmallestLastVertexOrdering() {};

		void ExecuteAlgorithm();
		void CreateSchedule();

		void PrintVertices();

	private:
		AdjacencyList const *adjList;
		DLL **edgeDegrees;
		int numberOfSessions;
		Vertex *vertices;
		int *deletedList;
		int largestEdgeDegree;
};