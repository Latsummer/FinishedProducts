#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace zzl

{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{ } 
		vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
				push_back(value);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
				*it++ = *vit++;
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		// capacity
		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < oldSize; i++)
						tmp[i] = _start[i];
				}

				delete[] _start;

				_start = tmp;
				_finish = _start + oldSize;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n > capacity())
				reserve(n);
			if (n > size())
			{
				while (_finish != _start + n)
					_finish++ = value;
			}
			_finish = _start + n;
		}

		T& operator[](size_t pos)
		{
			if (pos < size())
				return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			if (pos < size())
				return _start[pos];
		}

		void push_back(const T& value)
		{
			if (_finish == _end_of_storage)
			{
				size_t NewC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(NewC);
			}
			*_finish = value;
			_finish++;
		}

		void pop_back()
		{
			erase(--end());
		}

		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage)
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t NewC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(NewC);
				pos = _start + len;
			}

			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = value;
			_finish++;
		}

		iterator erase(iterator pos)
		{
			if (pos >= _start && pos < _finish)
			{
				iterator begin = pos + 1;
				while (begin != _finish)
				{
					*(begin - 1) = *begin;
					begin++;
				}
				_finish--;
			}
			return pos;
		}

	private:
		iterator _start;
		iterator _finish; 
		iterator _end_of_storage;
	};
}

void test1()
{
	zzl::vector<int> v1(10, 5);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	for (auto& i : v1)
		cout << i << " ";
	cout << endl;
	zzl::vector<string> v2;
	v2.push_back("a");
	v2.push_back("b");
	v2.push_back("c");
	v2.push_back("d");
	v2.push_back("e");
	for (auto& i : v2)
		cout << i << " ";
	cout << endl;
}

int main()
{
	test1();
	return 0;
}
