#include "pch.h"

#include "HashTable.h"

template<typename K, typename V>
 HashMap<K,V>::HashMap(int size)
{
	 size = size;

	 node = new HashNode*[size];

	 for (int i = 0; i < size; i++)
	 {
		 node[i] = NULL;
	 }

}

 template<typename K, typename V>
 void HashMap<K, V>::InsertNode(K key, V value)
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

 template<typename K, typename V>
 int HashMap<K, V>::GetValue(K key)
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
