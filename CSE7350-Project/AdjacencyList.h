#pragma once

class AdjacencyNode
{
	public:
		AdjacencyNode() {};
		~AdjacencyNode() {};

		void SetData(size_t value) { data = value; }
		void SetNext(AdjacencyNode *node) { next = node; }

		size_t GetData() const { return data; }
		AdjacencyNode *GetNext() const { return next; }

	private:
		size_t data;
		AdjacencyNode *next;
};

class AdjacencyList
{
	public:
		AdjacencyList(size_t sizeOfList);
		~AdjacencyList() {};

		void AddEdge(size_t src, size_t dest);
		AdjacencyNode *CreateNode(size_t sectionCourse);

		void PrintNodes();

	private:
		struct NodeList
		{
			AdjacencyNode *head;
		};

		size_t sizeOfList;
		NodeList *list;
};