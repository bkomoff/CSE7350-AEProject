#pragma once

class AdjacencyNode;
class DLL;

class Vertex
{
	public:
		Vertex():
			course(0),
			edgeList(NULL),
			edgeDegree(0),
			previousEdge(NULL),
			nextEdge(NULL),
			color(-1),
			deleted(false)
		{}

		~Vertex() {}

		void SetCourse(int currentCourse) { course = currentCourse; }
		void AddEdgeList(AdjacencyNode *list) { edgeList = list; }
		void SetEdgeDegree(int degree) { edgeDegree = degree; }
		void SetPreviousEdge(DLLNode *edge) { previousEdge = edge; }
		void SetNextEdge(DLLNode *edge) { nextEdge = edge; }
		void SetColor(int index) { color = index; }
		void Deleted() { deleted = true; }

		int GetCourse() const { return course; }
		int GetEdgeDegree() const { return edgeDegree; }
		AdjacencyNode *GetEdgeList() const { return edgeList; }
		DLLNode *GetPreviouisEdge() const { return previousEdge; }
		DLLNode *GetNextEdge() const { return nextEdge; }
		int GetColor() const { return color; }
		bool GetDeleted() const { return deleted; }

	
	private:
		int course;
		AdjacencyNode *edgeList;
		int edgeDegree;
		DLLNode *previousEdge;
		DLLNode *nextEdge;
		int color;
		bool deleted;
};