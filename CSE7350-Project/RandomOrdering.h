#pragma once

class AdjacencyList;

class RandomOrdering
{
	public:
		RandomOrdering(int length, AdjacencyList const *adj);
		~RandomOrdering();

	private:
		void Shuffle(int *arr, size_t n);

	private:
		AdjacencyList const *list;
		int *vertices;
		int listLength;
};