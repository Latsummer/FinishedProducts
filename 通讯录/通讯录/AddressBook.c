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

void Open(AddressBook* addr)
{
	FILE* addbook = fopen("C:book.txt", "r");
	if (addbook == NULL)
	{
		perror("文件打开失败！");
		return;
	}
	int i = 0;
	while (1)
	{
		if (fgets(addr->persons[i].name, sizeof((addr->persons[i].name) - 1), addbook) == NULL)
		{
			return;
		}
		fgets(addr->persons[i].sex, sizeof((addr->persons[i].sex) - 1), addbook);
		fgets(addr->persons[i].age, sizeof((addr->persons[i].age) - 1), addbook);
		fgets(addr->persons[i].phone, sizeof((addr->persons[i].phone) - 1), addbook);
		fgets(addr->persons[i].address, sizeof((addr->persons[i].address) - 1), addbook);
		i++;
     	addr->size++;
	}
	fclose(addbook);
	return;
}

void Close(AddressBook* addr)
{
	FILE* addbook = fopen("C:book.txt", "w");
	if (addbook == NULL)
	{
		perror("文件打开失败！");
		return;
	}
	for (int i = 0; i < addr->size; i++)
	{
		char name[1024] = { 0 };
		char sex[20] = { 0 };
		char age[10] = { 0 };
		char phone[1024] = { 0 };
		char address[1024] = { 0 };
		strcpy(name, addr->persons[i].name);
		strcpy(sex, addr->persons[i].sex);
		strcpy(age, addr->persons[i].age);
		strcpy(phone, addr->persons[i].phone);
		strcpy(address, addr->persons[i].address);
		fputs(name, addbook);
		//fputc(10, addbook);
		fputs(sex, addbook);
		//fputc(10, addbook);
		fputs(age, addbook);
		//fputc(10, addbook);
		fputs(phone, addbook);
		//fputc(10, addbook);
		fputs(address, addbook);
		//fputc(10, addbook);

	}
	fclose(addbook);
	return;
}

int main()
{
	Init(&address_book);
	Open(&address_book);
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
			Close(&address_book);
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