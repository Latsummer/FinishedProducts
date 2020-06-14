#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template <class T>
struct ListNode
{
	T _value;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		: _value(val)
		, _next(nullptr)
		, _prev(nullptr)
	{ }
};


template <class T>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
	//Node* _node;

	ListIterator(Node* node)
		: _node(node)
	{ }

	T& operator*()
	{
		return _node->_value;
	}

	T* operator->()
	{
		return &_node->_value;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	
	Node* _node;
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef ListIterator<T> iterator;

	iterator begin()
	{
		return iterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	List()
		: _header(new Node)
	{
		_header->_next = _header->_prev = _header;
	}

	void push_back(const T& val)
	{
		Node* cur = new Node(val);

		Node* prev = _header->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = _header;
		_header->_prev = cur;
	}
private:
	Node* _header;
};

void tt()
{
	List<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(3);
	t1.push_back(4);
	t1.push_back(5);

	List<int>::iterator it = t1.begin();
	while (it != t1.end())
	{
		cout << *it << " ";
		++it;
	}
}

int main()
{
	tt();
	return 0;
}