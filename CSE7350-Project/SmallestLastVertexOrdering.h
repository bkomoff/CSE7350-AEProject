#pragma once

class AdjacencyList;
class Vertex;

class SmallestLastVertexOrdering
{
	public:
		SmallestLastVertexOrdering(int length, AdjacencyList const *adj);
		~SmallestLastVertexOrdering() {};

		void PrintVertices();

	private:
		AdjacencyList const *adjList;
		int numberOfSessions;
		Vertex *vertices;

};