#include<iostream>
#include<vector>
#include<functional>
using namespace std;

namespace zzl
{
	template <class T>
	struct Greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template <class T>
	struct Less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue()
			:_c()
		{ }
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			: _c(first, last)
		{
			for (int parent = ((size() - 2) / 2); parent >= 0; parent--)
				shitfDown(parent);
		}
		bool empty() const
		{
			return _c.empty();
		}
		size_t size() const
		{
			return _c.size();
		}
		const T& top()
		{
			return _c.front();
		}
		void push(const T& x)
		{
			_c.push_back(x);
			shiftUp(size() - 1);
		}
		void pop()
		{
			if (empty())
				return;
			swap(_c[0], _c[size() - 1]);
			_c.pop_back();
			shitfDown(0);
		}
	private:
		void shitfDown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < size())
			{
				if (child + 1 < size() && comp(_c[child], _c[child + 1]))
					child++;
				if (comp(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;

			}
		}
		void shiftUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (comp(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		Container _c;
		Compare comp;
	};
};

int main()
{
	zzl::priority_queue<int, vector<int>, zzl::Less<int> > pq;
	pq.push(15);
	pq.push(25);
	pq.push(10);
	pq.push(95);
	pq.push(35);
	
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}