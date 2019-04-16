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
		int key;
		int value;
};

class HashMap
{
	public:
		HashMap(int size);

		int GetHashKey(int k) const { return k % hashSize;  }
		void InsertNode(int key, int value);
		int GetValue(int key);

	private:
		int hashSize;
		HashNode **node;

};


