#include "pch.h"

#include "HashTable.h"

 HashMap::HashMap(int size)
{
	 size = size;

	 node = new HashNode*[size];

	 for (int i = 0; i < initialCapacity; i++)
	 {
		 node[i] = NULL;
	 }

}

 void HashMap::InsertNode(int key, int value)
 {
	 int hash = (key % size);

	 while (node[hash] != NULL && node[hash]->GetKey() != key)
	 {
		 hash = (hash + 1) % size;
	 }

	 if (node[hash] != NULL)
	 {
		 delete node[hash];
	 }

	 node[hash] = new HashNode(key, value);
 }

 int HashMap::GetValue(int key)
 {
	 int hash = (key % size);

	 while (node[hash] != NULL && node[hash]->GetKey() != key && node[hash]->GetKey() != -1)
	 {
		 hash = (hash + 1) % size;
	 }

	 int hashValue = -1;

	 if (node[hash] != NULL)
	 {
		 hashValue = node[hash]->GetValue();
	 }

	 return hashValue;
 }
