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

		struct NodeList
		{
			AdjacencyNode *head;
		};

		NodeList *GetList() const { return list; }

		AdjacencyNode *CreateNode(size_t sectionCourse);
		void AddEdge(size_t src, size_t dest);
		int GetDegree(size_t index) const;
		void PrintNodes() const;
		size_t GetSizeOfList() const { return sizeOfList; }
		bool CheckForDuplicates(size_t src, size_t dest);

	private:
		size_t sizeOfList;
		NodeList *list;
};