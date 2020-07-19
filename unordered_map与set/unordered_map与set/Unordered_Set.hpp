#include "OpenHash.hpp"

template <class K, class HF = HashFunc<K>>
class Unordered_Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& value)
		{
			return value;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HF>::iterator iterator;

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

	pair<iterator, bool> insert(const K& value)
	{
		return _ht.insert(value);
	}

	bool erase(const K& key)
	{
		return _ht.erase(key);
	}

	HashNode<K>* find(const K& key)
	{
		return _ht.find(key);
	}

	size_t count(const K& key)
	{
		return _ht.count(key);
	}

private:
	HashTable<K, K, SetKeyOfValue, HF> _ht;
};