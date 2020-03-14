//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//
//
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人

#include"AddressBook.h"



int main()
{
	Init(&address_book);
	typedef void(*Func)(AddressBook*);
	Func function[] = 
	{
		NULL,//此处为了和menu的返回值匹配，将function[0]的内容写成NULL
		Add_Person_Info,
		Del_Person_Info,
		Find_Person_Info,
		Modify_Person_Info,
		Print_Person_Info,
		Clear_Person_Info
	};
	while (1)
	{
		int choice = menu();
		if (choice == 0)
		{
			printf("bye!\n\n");
			break;
		}
		if (choice < 0 || choice >= sizeof(function) / sizeof(function[0]))
		{
			printf("输入错误！\n\n");
			continue;
		}
		function[choice](&address_book);

	}
	return 0;
}