#include "Unordered_map.hpp"
//#include "Unordered_Set.hpp"

int main()
{
	//Unordered_Map<int, int> um;
	//um[2] = 3;
	//um[7] = 3;
	//um[6] = 3;
	//um[9] = 3;
	//um[5] = 3;

	//auto it = um.begin();
	//while (it != um.end())
	//{
	//	cout << it->first << "-->" << it->second << endl;
	//	it++;
	//}

	//Unordered_Set<int> us;
	//us.insert(3);
	//us.insert(2);
	//us.insert(9);
	//us.insert(6);
	//us.insert(5);

	Unordered_Map<string, int> um;
	string s1("aad");
	um["ss"] = 1;
	cout << um["ss"];
	auto it = um.begin();
	cout << it->first;
}