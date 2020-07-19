#include "OpenHash.hpp"

template <class K, class V, class HF = HashFunc<K>>
class Unordered_Map
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& value)
		{
			return value.first;
		}
	};

public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HF>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	size_t size() const
	{
		return _ht.size();
	}

	bool empty() const
	{
		return _ht.empty();
	}

	pair<iterator, bool> insert(const pair<K, V>& value)
	{
		return _ht.insert(value);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}

	bool erase(const K& key)
	{
		return _ht.erase(key);
	}

	HashNode<V>* find(const K& key)
	{
		return _ht.find(key);
	}

	size_t count(const K& key)
	{
		return _ht.count(key);
	}

private:
	
	HashTable<K, pair<K, V>, MapKeyOfValue, HF> _ht;
};

