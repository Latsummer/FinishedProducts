#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		_bit.resize(range / 32 + 1);
	}

	//查询: Test
	bool Test(size_t n)
	{
		//整数位置
		int idx = n >> 5;//等价于n/32
		int bitIdx = n % 32;
		//获取对应二进制值
		if ((_bit[idx] >> bitIdx) & 1)
			return true;
		else
			return false;
	}

	//存储: Set
	void Set(size_t n)
	{
		int idx = n / 32;
		int bitIdx = n % 32;

		_bit[idx] |= (1 << bitIdx);
	}

	//删除: Reset
	void Reset(size_t n)
	{
		int idx = n >> 5;
		int bitIdx = n % 32;

		_bit[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _bit;
};

struct strToint1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
			hash = hash * 131 + ch;
		return hash;
	}
};

struct strToint2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
			hash = hash * 65599 + ch;
		return hash;
	}
};

struct strToint3
{
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		for (auto& ch : str)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};

template<class T, class HF1, class HF2, class HF3>
class BloomFilter
{
public:
	//bit位数量 = hash函数个数 * 数据量 / ln2
	BloomFilter(size_t num)
		: _bit(5 * num)
		, _bitCount(5 * num)
	{ }

	void Set(const T& value)
	{
		HF1 hf1;
		HF2 hf2;
		HF3 hf3;

		size_t hashCode1 = hf1(value);
		size_t hashCode2 = hf2(value);
		size_t hashCode3 = hf3(value);

		_bit.Set(hashCode1 % _bitCount);
		_bit.Set(hashCode2 % _bitCount);
		_bit.Set(hashCode3 % _bitCount);
	}

	bool Test(const T& value)
	{
		HF1 hf1;
		size_t hashCode1 = hf1(value);
		if (!_bit.Test(hashCode1 % _bitCount))
			return false;

		HF2 hf2;
		size_t hashCode2 = hf2(value);
		if (!_bit.Test(hashCode2 % _bitCount))
			return false;

		HF3 hf3;
		size_t hashCode3 = hf3(value);
		if (!_bit.Test(hashCode3 % _bitCount))
			return false;

		return true;
	}

private:
	BitMap _bit;
	size_t _bitCount;
};

void Bit()
{
	BitMap bit(100);

	bit.Set(23);
	bit.Set(32);
	bit.Set(66);
	bit.Set(44);

	bool ret = bit.Test(23);
	ret = bit.Test(66);
	ret = bit.Test(10);
	bit.Reset(44);
}

void bloom()
{
	BloomFilter<string, strToint1, strToint2, strToint3> bf(300);

	string s1 = "https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsvpidx=y&tn=baidu&wd=markdown%E5%85%AC%E5%BC%8F&fenlei=256&oq=%25E5%25B8%2583%25E9%259A%2586%25E8%25BF%2587%25E6%25BB%25A4%25E5%2599%25A8&rsv_pq=8be68dd800004d60&rsv_t=9d7bYXgQIRSWqpTiinvo9m%2F0%2FkejOmMHIj6IjeoxWU7idMOhr6um0W97h2s&rqlang=cn&rsv_enter=1&rsv_dl=tb&rsv_btype=t&inputT=8565&rsv_sug3=30&rsv_sug1=10&rsv_sug7=101&rsv_sug2=0&rsv_sug4=8565";
	string s2 = "https://www.baiiu.com/s?ie=utf-8&fu8&rsv_bp=1&rsv_idx=1&tn=baidu&wd=markdown%Eu%85%AC%E5%BC%8F&fenlei=256&oq=%25E5%25B8%2583%25E9%259A%2586%25E8%25BF%2587%25E6%25BB%25A4%25E5%2599%25A8&rsv_pq=8be68dd800004d60&rsv_t=9d7bYXgQIRSWqpTiinvo9m%2F0%2FkejOmMHIj6IjeoxWU7idMOhr6um0W97h2s&rqlang=cn&rsv_enter=1&rsv_dl=tb&rsv_btype=t&inputT=8565&rsv_sug3=30&rsv_sug1=10&rsv_sug7=101&rsv_sug2=0&rsv_sug4=8565";
	string s3 = "https://www.baihu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=baidu&wd=markdown%E8%85%AC%E5%BC%8F&fenlei=256&oq=%25E5%25B8%2583%25E9%259A%2586%25E8%25BF%2587%25E6%25BB%25A4%25E5%2599%25A8&rsv_pq=8be68dd800004d60&rsv_t=9d7bYXgQIRSWqpTiinvo9m%2F0%2FkejOmMHIj6IjeoxWU7idMOhr6um0W97h2s&rqlang=cn&rsv_enter=1&rsv_dl=tb&rsv_btype=t&inputT=8565&rsv_sug3=30&rsv_sug1=10&rsv_sug7=101&rsv_sug2=0&rsv_sug4=8565";

	bf.Set(s1);
	bf.Set(s2);
	bf.Set(s3);
}

int main()
{
	//Bit();
	bloom();
	return 0;
}