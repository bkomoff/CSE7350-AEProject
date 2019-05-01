#pragma once

class DLLNode
{
	public:
		DLLNode();
		~DLLNode() {};

		void SetData(int newData) { data = newData; }
		int GetData() const { return data; }

		DLLNode *GetNext() const { return next; }
		void SetNext(DLLNode *nextNode) { next = nextNode; }

		DLLNode *GetPrev() const { return prev; }
		void SetPrev(DLLNode *prevNode) { prev = prevNode; }

	private:
		int data;
		DLLNode *next;
		DLLNode *prev;
};

class DLL
{
	public:
		DLL();
		~DLL();

		DLLNode *Push(int newData);
		void Remove();

		void PrintDLL() const;

		DLLNode const *GetHead() { return head; }

	private:
		DLLNode *head;
		DLLNode *tail;

		DLLNode *CreateDLLNode(int newData);
};
