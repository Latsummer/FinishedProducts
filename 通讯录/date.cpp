#include<iostream>
using namespace std;


class Date
{
public:
// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0))
			|| (year % 400 == 0)))
			++day;
		return day;
	}
  // 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法：" << year << "-" << month << "-" << day << endl;
			cout << "置为默认值：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
  // 拷贝构造函数

// d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void PrintD()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
  // 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}
  // 析构函数

	//~Date();
  // 日期+=天数

	Date& operator+=(int day)
	{
		if (day >= 0)
		{
			_day += day;
			while (_day <= GetMonthDay(_year, _month))
			{
				_day -= GetMonthDay(_year, _month);
				_month++;
				if (_month > 13)
				{
					_month = 1;
					_year++;
				}
			}
		}
		else
			operator-=(-day);
		return *this;
	}

  // 日期+天数

	Date operator+(int day)
	{
		return *this += (day);
	}

  // 日期-天数

	Date operator-(int day)
	{
		return *this-=(day);
	}

   // 日期-=天数

	Date& operator-=(int day)
	{
		if (day >= 0)
		{
			_day -= day;
			while (_day <= 0)
			{
				_day += GetMonthDay(_year, _month);
				_month--;
				if (_month < 1)
				{
					_month = 12;
					_year--;
				}
			}
		}
		else
			operator+=(-day);
		
		return *this;
	}

  // 前置++

	Date& operator++()
	{
		return *this += 1;
	}

  // 后置++

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

  // 后置--

	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

  // 前置--

	Date& operator--()
	{
		return *this -= 1;
	}

  // >运算符重载

	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}

  // ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

  // >=运算符重载

	inline bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

  // <运算符重载

	bool operator < (const Date& d)
	{

		if (_year < d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}
		return false;
	}

   // <=运算符重载

	bool operator <= (const Date& d)
	{
		return *this < d || *this == d;
	}

  // !=运算符重载

	bool operator != (const Date& d)
	{
		return !(_year == d._year
			&& _month == d._month
			&& _day == d._day);

	}

  // 日期-日期 返回天数

	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++(min);
			++day;
		}
		return day * flag;
	}

private:

	int _year;
	int _month;
	int _day;

};

void test1()
{
	Date d1(2020, 5, 23);
	d1.PrintD(); 
	Date d2(d1);
	Date d3(d2);
	d1 = d1 - 198;
	d1.PrintD();
	d3 += 7;

	if (d2 != d3)
		cout << "ok" << endl;
	cout << d3 - d2 << endl;
}

int main()
{
	test1();
	return 0;
}