#include<iostream>
#include<queue>
using namespace std;

namespace zzl
{
#include<deque>
	template<class T, class Con = deque<T>>
	class stack
	{
	public:
		stack()
		{ }
		void push(const T& x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_back();
		}
		T& top()
		{
			return _c.back();
		}
		const T& top()const
		{
			return _c.back();
		}
		size_t size()const
		{
			return _c.back();
		}
		bool empty()const
		{
			return _c.empty();
		}
	private:
		Con _c;
	};

	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue()
		{ }
		void push(const T& x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_front();
		}
		T& back()
		{
			return _c.back();
		}
		const T& back()const
		{
			return _c.back();
		}
		T& front()
		{
			return _c.front();
		}
		const T& front()const
		{
			return _c.front();
		}
		size_t size()const
		{
			return _c.size();
		}
		bool empty()const
		{
			return _c.empty();
		}
	private:
		Con _c;
	};
};

//int main()
//{
//	zzl::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//
//	zzl::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//	return 0;
//}