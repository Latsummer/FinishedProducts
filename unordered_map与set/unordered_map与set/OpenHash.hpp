#include <iostream>
#include <vector>
#include <string>
using namespace std;

//template <class K>
//struct KeyOfValue
//{
//	const K& operator()(const K& key = K())
//	{
//		return key;
//	}
//};

template <class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
class HashFunc<string>
{
public:
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return hash;
	}
};

template <class V>
struct HashNode
{
	V _value;
	HashNode<V>* _next;

	HashNode(const V& val = V())
		: _value(val)
		, _next(nullptr)
	{ }
};

//前置声明
template <class K, class V, class KeyOfValue, class HF>
class HashTable;

template <class K, class V, class KeyOfValue, class HF>
struct HashIterator
{
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue, HF> Self;
	typedef HashTable<K, V, KeyOfValue, HF> HT;

	HashIterator(Node* node, HT* ht)
		: _node(node)
		, _ht(ht)
	{ }

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
	}

	Self& operator++()
	{
		add();
		return *this;
	}

	Self& operator++(int)
	{
		Self tmp(*this);
		add();
		return *tmp;
	}

private:

	void add()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			KeyOfValue kov;
			HF hf;

			size_t idx = hf(kov(_node->_value)) % _ht->_table.size();
			idx++;
			if (idx == _ht->_table.size())
			{
				_node = nullptr;
				return;
			}

			Node* cur = _ht->_table[idx];
			for (; idx < _ht->_table.size(); idx++)
			{
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
			}

			if (idx == _ht->_table.size())
				_node = nullptr;
			return;
		}
	}

	Node* _node;
	HT* _ht;
};

template <class K, class V, class KeyOfValue, class HF>
class HashTable
{
public:
	//迭代器声明为友元类
	template <class K, class V, class KeyOfValue, class HF>
	friend struct HashIterator;

	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue, HF> iterator;


	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			Node* cur = _table[i];
			if (cur)
				return iterator(cur, this);
		}
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> insert(const V& value)
	{
		CheckCapacity();

		HF hf;
		KeyOfValue kov;
		size_t idx = hf(kov(value)) % _table.size();

		Node* cur = _table[idx];
		while (cur)
		{
			if (kov(cur->_value) == kov(value))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}

		cur = new Node(value);
		cur->_next = _table[idx];
		_table[idx] = cur;
		_size++;

		return make_pair(iterator(cur, this), true);
	}

	Node* find(const K& key)
	{
		if (_size == 0)
			return nullptr;

		HF hf;
		size_t idx = hf(key) % _table.size();

		Node* cur = _table[idx];
		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_value) == key)
				return cur;
			cur = cur->_next;
		}

		return nullptr;
	}

	size_t count(const K& key)
	{
		Node* p = find(key);
		if (p)
			return 1;
		else
			return 0;
	}

	bool erase(const K& key)
	{
		HF hf;
		int idx = hf(key) % _table.size();

		Node* cur = _table[idx];
		KeyOfValue kov;
		Node* prev = nullptr;

		while (cur && kov(cur->_value) != key)
		{
			prev = cur;
			cur = cur->_next;
		}

		if (cur == nullptr)
			return false;
		else
		{
			if (prev == nullptr)
			{
				_table[idx] = cur->_next;
				delete cur;
			}
			else
			{
				prev->_next = cur->_next;
				delete cur;
			}
		}
		_size--;
		return true;
	}

	bool empty() const
	{
		return 0 == _size;
	}

	size_t size() const
	{
		return _size;
	}

private:

	size_t getNextSize(size_t n)
	{
		const int PRIMECOUNT = 28;
		const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};

		for (int i = 0; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > n)
				return primeList[i];
		}

		return primeList[PRIMECOUNT];
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newSize = getNextSize(_size);
			vector<Node*> newTable;
			newTable.resize(newSize);

			//遍历旧表中的非空单链表
			KeyOfValue kov;
			HF hf;
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{

					Node* next = cur->_next;

					int idx = hf(kov(cur->_value)) % newTable.size();
					//头插
					cur->_next = newTable[idx];
					newTable[idx] = cur;

					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newTable);
		}
		return;
	}

	vector<Node*> _table;
	size_t _size = 0;
};
