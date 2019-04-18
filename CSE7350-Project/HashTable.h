#pragma once

class HashNode
{
	public:
		HashNode(int  key, int value)
		{
			this->key = key;
			this->value = value;
			this->nextHashNode = NULL;
		}

		int  GetKey() const { return this->key; }
		int GetValue() const { return this->value; }
		void SetValue(int value) { value = this->value; }
		HashNode *GetNext() { return this->nextHashNode;  }
		void SetNext(HashNode *node) { nextHashNode = node; }

	private:
		int  key;
		int value;
		HashNode *nextHashNode;
};

class HashMap
{
	public:
		HashMap(int size);

		int GetHashKey(int  k) const { return k % hashSize;  }
		void InsertNode(int  key, int value);
		int GetValue(int  key);

	private:
		int hashSize;
		HashNode **node;

};


