#include "pch.h"

#include "HashTable.h"

 HashMap::HashMap(int size)
{
	 hashSize = size;

	 node = new HashNode*[hashSize];

	 for (int i = 0; i < hashSize; i++)
	 {
		 node[i] = NULL;
	 }

}

 void HashMap::InsertNode(int key, int value)
 {
	 HashNode *temp = new HashNode(key, value);

	 int hash = (key % hashSize);

	 while (node[hash] != NULL && node[hash]->GetKey() != key)
	 {
		 hash = (hash + 1) % hashSize;
	 }

	 if (node[hash] != NULL)
	 {
		 delete node[hash];
	 }

	 node[hash] = temp;
 }

 int HashMap::GetValue(int key)
 {
	 int hash = (key % hashSize);

	 while (node[hash] != NULL && node[hash]->GetKey() != key && node[hash]->GetKey() != -1)
	 {
		 hash = (hash + 1) % hashSize;
	 }

	 int hashValue = -1;

	 if (node[hash] != NULL)
	 {
		 hashValue = node[hash]->GetValue();
	 }

	 return hashValue;
 }
