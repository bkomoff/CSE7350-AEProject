#pragma once

class AdjacencyList;
class Vertex;

class SmallestLastVertexOrdering
{
	public:
		SmallestLastVertexOrdering(int length);
		~SmallestLastVertexOrdering() {};

		void CreateEdgeDegreeList(AdjacencyList const &currentSession);

	private:
		int numberOfSessions;
		Vertex *courses;

};