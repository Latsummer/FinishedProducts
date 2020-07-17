#include "RBTree.hpp"

template <class K, class V>
class Map
{
public:
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& value)
		{
			return value.first;
		}
	};
	/*bool insert(const pair<K, V>& value)
	{
		return _rbt.insert(value);
	}*/

	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _rbt.begin();
	}

	iterator end()
	{
		return _rbt.end();
	}

	bool empty()
	{
		return _rbt->empty();
	}

	size_t size()
	{
		return _rbt.size();
	}

	pair<iterator, bool> insert(const pair<K, V>& value)
	{
		return _rbt.insert(value);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _rbt.insert(make_pair(key, V()));
		return ret.first->second;
	}

	iterator find(const K& key)
	{
		return _rbt.Find(pair<K, V>(key, V()));
	}

private:
	RBTree<K, pair<K, V>, MapKeyOfValue> _rbt;
};

template <class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	iterator begin()
	{
		return _rbt.begin();
	}

	iterator end()
	{
		return _rbt.end();
	}

	bool empty()
	{
		return _rbt.empty();
	}

	iterator find(const K& key)
	{
		return _rbt.Find(key);
	}

	size_t size()
	{
		return _rbt.size();
	}

	pair<iterator, bool> insert(const K& key)
	{
		return _rbt.insert(key);
	}
private:

	RBTree<K, K, SetKeyOfValue> _rbt;
};

void testMap()
{
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 1));
	m.insert(make_pair(6, 1));
	m.insert(make_pair(9, 9));
	m.insert(make_pair(7, 7));
	m[1]++;
	m[20]++;
	Map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "->" << it->second << endl;
		++it;
	}
}

void testSet()
{
	Set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(9);
	s.insert(7);
}

int main()
{
	testMap();
	testSet();
	return 0;
}