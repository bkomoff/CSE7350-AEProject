#include "pch.h"

#include "AdjacencyList.h"

#include "RandomOrdering.h"

RandomOrdering::RandomOrdering(int length, AdjacencyList const * adj):
	list(adj),
	listLength(length)
{
	vertices = new int[listLength];
	for (int i = 0; i < listLength; i++)
	{
		vertices[i] = 0;
	}

	int t = 0;
	for (int i = 0; i < listLength; i++)
	{
		if (list->GetList()[i].head != NULL)
		{
			vertices[t] = i;
			t++;
		}
	}

	Shuffle(vertices, listLength);
	for (int i = 0; i < listLength; i++)
	{
		std::cout << "[" << vertices[i] << "]";
	}
	std::cout << std::endl;
}

RandomOrdering::~RandomOrdering()
{
}

void RandomOrdering::Shuffle(int *arr, size_t n)
{
	if (n > 1)
	{
		size_t i;
		srand(time(NULL));
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}
