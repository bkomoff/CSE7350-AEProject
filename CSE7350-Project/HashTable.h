#pragma once

class HashNode
{
	public:
		HashNode(int key, int value)
		{
			this->key = key;
			this->value = value;
		}

		int GetKey() const { return this->key; }
		int GetValue() const { return this->value; }

	private:
		int value;
		int key;
};

class HashMap
{
	public:
		HashMap(int size);

		int GetHashKey(int k) const { return k % size;  }
		void InsertNode(int key, int value);
		int GetValue(int key);

	private:
		int size;
		HashNode **node;

};


