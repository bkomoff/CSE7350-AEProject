#pragma once

class HashNode
{
	public:
		HashNode(size_t  key, size_t value)
		{
			this->key = key;
			this->value = value;
			this->nextHashNode = NULL;
		}

		size_t  GetKey() const { return this->key; }
		size_t GetValue() const { return this->value; }
		void SetValue(size_t value) { value = this->value; }
		HashNode *GetNext() { return this->nextHashNode;  }
		void SetNext(HashNode *node) { nextHashNode = node; }

	private:
		size_t  key;
		size_t value;
		HashNode *nextHashNode;
};

class HashMap
{
	public:
		HashMap(size_t size);

		size_t GetHashKey(size_t  k) const { return k % hashSize;  }
		void InsertNode(size_t  key, size_t value);
		size_t GetValue(size_t  key);

	private:
		size_t hashSize;
		HashNode **node;

};


