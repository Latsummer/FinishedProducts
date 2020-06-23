#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//class String_my
//
//{
//
//public:
//	String_my(const char* str = "")
//	{
//		if (strlen(str) > SIZE)
//		{
//			cout << "error" << endl;
//			_str = "";
//		}
//		else
//		{
//			_str = new char[SIZE + 1];
//			strcpy(_str, str);
//		}
//	}
//
//	String_my(const String_my &s)
//	{
//		_str = new char[SIZE + 1];
//		strcpy(_str, s._str);
//	}
//
//	String_my& operator=(const String_my &s)
//	{
//		if (this != &s)
//		{
//			char* tmp = new char[SIZE + 1];
//			strcpy(tmp, s._str);
//			delete[] _str;
//
//			_str = tmp;
//		}
//		return *this;
//	}
//
//	~String_my()
//	{
//		delete[] _str;
//	}
//	void DisPlay()
//	{
//		cout << _str << endl;
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	String_my s1("123");
//	s1.DisPlay();
//	String_my s2(s1);
//	String_my s3 = s1;
//	s2.DisPlay();
//	s3.DisPlay();
//	return 0;
//}

namespace zzl
{
	class string
	{
	friend ostream& operator<<(ostream& _cout, const zzl::string& s);
	friend istream& operator>>(istream& _cin, zzl::string& s);
	public:
	typedef char* iterator;
	public:

		string(const char* str = "")
		{
			_size = _capacity = strlen(str);
			_str = new char[_capacity + 1];
			//_capacity = _size;
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			Swap(tmp);
		}

		string& operator=(const string &s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;

				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

	//////////////////////////////////////////////////////////////
	// iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
	/////////////////////////////////////////////////////////////
	// modify
		void PushBack(char c)
		{
			insert(_size, c);
		}

		string& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}

		void Append(const char* str)
		{
			insert(_size, str);
		}
		string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}
		void clear()
		{
			if (_str)
				memset(_str, '\0', _size);
		}

	void Swap(string& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	const char* c_str()const
	{
		return _str;
	}

	/////////////////////////////////////////////////////////////
	// capacity
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	bool empty()const
	{
		return _size == 0;
	}

	void resize(size_t newSize, char c = '\0')
	{
		if (newSize > _capacity)
			reserve(newSize);
		if (newSize > _size)
			memset(_str + _size, c, newSize - _size);
		_size = newSize;
		_str[_size] = c;
	}

	void reserve(size_t newCapacity)
	{
		if (newCapacity > _capacity)
		{
			char* tmp = new char[newCapacity + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = newCapacity;
		}
	}

	/////////////////////////////////////////////////////////////
	// access
	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	/////////////////////////////////////////////////////////////
	//relational operators
	bool operator<(const string& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret < 0)
			return true;
		else
			return false;
	}

	bool operator<=(const string& s)
	{
		return (*this < s) || (*this == s);
	}

	bool operator>(const string& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret > 0)
			return true;
		else
			return false;
	}

	bool operator>=(const string& s)
	{
		return (*this > s) || (*this == s);
	}

	bool operator==(const string& s)
	{
		int ret = strcmp(_str, s._str);
		if (ret == 0)
			return true;
		else
			return false;
	}

	bool operator!=(const string& s)
	{
		return !(*this == s);
	}

	// 返回c在string中第一次出现的位置
	size_t find(char c, size_t pos = 0) const
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return -1;
	}

	// 返回子串s在string中第一次出现的位置
	size_t find(const char* s, size_t pos = 0) const
	{
		assert(s);
		assert(pos < _size);
		const char* src = _str + pos;
		while (*src)
		{
			const char* begin = s;
			const char* cur = src;

			while (*begin && *begin == *cur)
			{
				begin++;
				cur++;
			}
			if (*begin == '\0')
				return src - _str;
			else
				src++;
		}
		return -1;
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& insert(size_t pos, char c)
	{
		if (pos > _size)
		{
			cout << "插入失败，位置不存在" << endl;
			return *this;
		}	
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		_size++;

		return *this;
	}

	string& insert(size_t pos, const char* str)
	{
		if (pos > _size)
		{
			cout << "插入失败，位置不存在" << endl;
			return *this;
		}
		size_t len = strlen(str);
		if (_size + len > _capacity)
			reserve(_size + len);
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			end--;
		}

		for (size_t i = 0; i < len; i++)
			_str[i + pos] = str[i];
		_size += len;

		return *this;
	}

	// 删除pos位置上的元素，并返回该元素的下一个位置
	string& erase(size_t pos, size_t len)
	{
		if (pos > _size)
			return *this;
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			for (size_t i = pos + len; i <= _size; i++)
				_str[pos++] = _str[i];
			_size -= len;
		}
		return *this;
	}

	private:
	char* _str;
	size_t _capacity;
	size_t _size;
	};

};
ostream& zzl::operator<<(ostream& _cout, const zzl::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
		_cout << s[i];
	return _cout;
}

istream& zzl::operator>>(istream& _cin, zzl::string& s)
{
	char* str = (char*)malloc(sizeof(char) * 100);
	char* buf = str;
	int i = 1;
	while ((*buf = getchar()) == ' ' || (*buf == '\n'));
	for ( ; ; ++i)
	{
		if (*buf == '\n'){
			*buf = '\0';
			break;
		}else if (*buf == ' '){
			*buf = '\0';
			break;
		}else if (i % 100 == 0){
			i += 100;
			str = (char*)realloc(str, i);
		}else{
			buf = (str+i);
			*buf = getchar();
		}
	}
	s._str = str;
	s._capacity = s._size = i;

	return _cin;
}


int main()
{
	zzl::string s1("0123456789");
	cout << s1 << endl;
	zzl::string s2;
	cin >> s2;
	cout << s2 << endl;
	return 0;
}