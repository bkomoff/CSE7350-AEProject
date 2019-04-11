#pragma once

template<typename K, typename V>
class HashNode
{
	public:
		HashNode(K key, V value)
		{
			this->key = key;
			this->value = value;
		}

		K GetKey() const { return this->key; }
		V GetValue() const { return this->value; }

	private:
		K key;
		V value;
};

template<typename K, typename V>
class HashMap
{
	public:
		HashMap(int size);

		int GetHashKey(K k) const { return k % size;  }
		void InsertNode(K key, V value);
		int GetValue(K key);

	private:
		int size;
		HashNode<K,V> **node;

};


