#pragma once
#include "List.h"

template <typename K, typename V>
struct Pair
{
	K _key;
	V _value;

	Pair() = default;
	Pair(const Pair& p) = default;
	Pair& operator=(const Pair& p) = default;
	Pair(Pair&& p) = default;
	Pair& operator=(Pair&& p) = default;

	Pair(int key) :_key(key), _value() {}
	Pair(int key, V value) :_key(key), _value(value) {}

	friend bool operator==(const Pair& p1, const Pair& p2);

};

template <typename K, typename V>
bool operator==(const Pair<K, V>& p1, const Pair<K, V>& p2) {
	return p1._key == p2._key;
}


template <typename K, typename V>
struct Hash_Chain {

	List<Pair<K, V> >* _hash_table; //äèíàìè÷åñêèé ìàññèâ
	std::size_t _table_size;

	std::size_t(*_hash)(K key);

	/*
	std::size_t hash(int i) {
		return (i % _table_size);
	}*/

public:
	//Hash_Chain():_hash_table() {}

	Hash_Chain(std::size_t size, std::size_t(*hash)(K key)) :
		_table_size(size),
		_hash_table(new List<Pair<K, V> >[size]), 
		_hash(hash) 
	{}

	~Hash_Chain() = default;

	bool ins(K key, const V& value) {
		bool b = true;
		for (Node<Pair<K, V>>* n = _hash_table[_hash(key) % _table_size].getHead();
			n; 
			n = n->getNext()) 
		{
			if (n->getItem()._key == key) {
				n->setItem({key, value});
				b = false;
				break;
			}
		}
		if (b) {
			_hash_table[_hash(key) % _table_size].enqueue({ key, value });
		}
		return b;
	}

	bool del(K key) {
		bool b = false;

		for (Node<Pair<K, V>>* n = _hash_table[_hash(key) % _table_size].getHead();
			n; 
			n = n->getNext()) 
		{
			if (n->getItem()._key == key) {
				b = true;
				_hash_table[_hash(key) % _table_size].remove_node(n);
				break;
			}
		}
		return b;
	}

	V search(K key) {
		Pair<K, V> temp;

		for (Node<Pair<K, V>>* n = _hash_table[_hash(key) % _table_size].getHead();
			n;
			n = n->getNext())
		{
			if (n->getItem()._key == key) {
				temp = n->getItem();
				break;
			}
		}
		return temp._value;
	}
};
