#include "pch.h"

#include "DLL.h"

DLLNode::DLLNode():
	data(0),
	next(nullptr),
	prev(nullptr)
{}

DLL::DLL() :
	head(nullptr),
	tail(nullptr)
{}

DLL::~DLL()
{
}

DLLNode *DLL::CreateDLLNode(int newData)
{
	DLLNode *node = new DLLNode;
	if (node != nullptr)
	{
		node->SetData(newData);
		node->SetNext(nullptr);
		node->SetPrev(nullptr);
	}

	return node;
}

void DLL::Push(int newData)
{
	DLLNode *newNode = CreateDLLNode(newData);
	if (head == nullptr) // empty list
	{
		this->head = newNode;
	}
	else if (tail == nullptr) // contains one item
	{
		this->tail = newNode;
		newNode->SetPrev(this->head);
		this->head->SetNext(this->tail);
	}
	else // more than one item in list add to end
	{
		newNode->SetPrev(this->tail);
		this->tail->SetNext(newNode);
		this->tail = newNode;
	}
}

void DLL::Remove()
{
	DLLNode *currentNode = head;
	if (currentNode != nullptr)
	{
		this->head = nullptr;
		this->head = currentNode->GetNext();
		if (this->head != nullptr)
		{
			this->head->SetPrev(nullptr);
		}
		delete currentNode;
	}
}

void DLL::PrintDLL() const
{
	DLLNode *currentNode = head;
	std::cout << "Queue list: ";
	while (currentNode != nullptr)
	{
		std::cout << currentNode->GetData() << " ";
		currentNode = currentNode->GetNext();
	}
	std::cout << std::endl;
}