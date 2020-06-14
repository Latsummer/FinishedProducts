#include<assert.h>
#include<iostream>
using namespace std;

namespace zzl
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _val(val)
			, _pNext(nullptr)
			, _pPre(nullptr)
		{ }
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};


	template<class T, class Ref, class Ptr>//µü´úÆ÷
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{ }
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{ }
		T& operator*()
		{
			return _pNode->_val;
		}
		
		T* operator->()
		{
			return *this;
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pNext;
			return tmp;
		}

		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pPre;
			return tmp;
		}

		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)
		{
			return _pNode == l._pNode;
		}

		PNode _pNode;
	};

	//listÀà
	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;
		list()
		{
			CreateHead();
		}

		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; i++)
				push_back(value);
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		list(const list<T>& l)
		{
			CreateHead();
			list<T> tmp(l.cbeegin(), l.cend());
			this->swap(tmp);
		}

		list<T>& operator=(const list<T> l)
		{
			this->swap(l);
			return *this;
		}

		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		const_iterator cbegin()
		{
			return const_iterator(_pHead->_pNext);
		}

		const_iterator cend()
		{
			return const_iterator(_pHead);
		}

		size_t size()const
		{
			PNode cur = _pHead->_pNext;
			size_t size;
			while (cur != _pHead)
			{
				size++;
				cur = cur->_pNext;
			}
			return size;
		}

		bool empty()const
		{
			return size() == 0;
		}
		T& front()
		{
			assert(!empty());
			return _pHead->_pNext->_val;
		}

		const T& front()const
		{
			assert(!empty());
			return _pHead->_pNext->_val;
		}

		T& back()
		{
			assert(!empty());
			return _pHead->_pPre->_val;
		}

		const T& back()const
		{
			assert(!empty());
			return _pHead->_pPre->_val;
		}

		void push_back(const T& val) 
		{
			insert(end(), val); 
		}

		void pop_back() 
		{ 
			erase(--end()); 
		}

		void push_front(const T& val) 
		{ 
			insert(begin(), val); 
		}

		void pop_front() 
		{ 
			erase(begin()); 
		}

		iterator insert(iterator pos, const T& val)
		{
			PNode node = new Node(val);
			PNode cur = pos._pNode;

			node->_pNext = cur;
			node->_pPre = cur->_pPre;

			cur->_pPre->_pNext = node;
			cur->_pPre = node;

			return iterator(node);
		}

		iterator erase(iterator pos)
		{
			if (pos != end())
			{
				PNode del = pos._pNode;
				PNode next = pos._pNode->_pNext;

				del->_pPre->_pNext = next;
				next->_pPre = del->_pPre;

				delete del;

				return iterator(next);
			}
			return pos;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
				it = erase(it);
		}

		void swap(list<T>& l)
		{
			PNode tmp = _pHead;
			_pHead = l._pHead;
			l._pHead = tmp;
		}


	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		PNode _pHead;
	};

};

void test()
{
	zzl::list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.pop_back();
	ls.pop_back();
	ls.pop_back();
	ls.pop_back();
	ls.push_front(1);
	ls.push_front(2);
	ls.push_front(3);
	ls.push_front(4);
	ls.push_front(5);

	zzl::list<int>::iterator it = ls.begin();
	while (it != ls.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}