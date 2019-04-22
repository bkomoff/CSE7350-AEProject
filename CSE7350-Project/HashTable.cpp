#include "pch.h"

#include "HashTable.h"

 HashMap::HashMap(size_t size)
{
	 hashSize = size;

	 node = new HashNode*[hashSize];

	 for (int i = 0; i < hashSize; i++)
	 {
		 node[i] = NULL;
	 }

}

 void HashMap::InsertNode(size_t  key, size_t value)
 {
	 size_t hash = (key % hashSize);

	 if (node[hash] == NULL)
	 {
		 node[hash] = new HashNode(key, value);
	 }
	 else 
	 {
		 HashNode *entry = node[hash];

		 while (entry->GetNext() != NULL)
		 {
			 entry = entry->GetNext();
		 }

		 if (entry->GetKey() == key)
		 {
			 entry->SetValue(value);
		 }
		 else
		 {
			 entry->SetNext(new HashNode(key, value));
		 }
	 }
 }

 size_t HashMap::GetValue(size_t  key)
 {
	 size_t hash = (key % hashSize);

	 HashNode *entry = node[hash];

	 if (entry == NULL)
	 {
		 return -1;
	 }
	 else 
	 {
		 while (entry != NULL && entry->GetKey() != key)
		 {
			 entry = entry->GetNext();
		 }

		 if (entry == NULL)
		 {
			 return -1;	
		 }
		 else
		 {
			 return entry->GetValue();
		 }
	 }
 }
