#define _CRT_SECURE_NO_WARNINGS 1

#include"AddressBook.h"

static void cmp(AddressBook* addr) //排序
{
	int i = 0;
	int j = 0;
	PersonalInfo tmp;
	for (i = 0; i < addr->size - 1; i++)
	{
		for (j = 0; j < addr->size - 1 - i; j++)
		{
			if (strcmp(addr->persons[j].name , addr->persons[j+1].name) > 0)
			{
				tmp = addr->persons[j];
				addr->persons[j] = addr->persons[j + 1];
				addr->persons[j + 1] = tmp;
			}
		}
	}
}

void Init(AddressBook* addr)//初始化通讯录
{
	addr->size = 0;
	for (int i = 0; i < MAX_SZIE; i++)
	{
		strcpy(addr->persons[i].name , "");
		strcpy(addr->persons[i].phone , "");
		strcpy(addr->persons[i].address  , "");
		strcpy(addr->persons[i].sex , "");
		strcpy(addr->persons[i].age, "");
	}
}

int menu()//主菜单
{
	printf("============================\n");
	printf("  1.新建联系人\n");
	printf("  2.删除联系人\n");
	printf("  3.查询联系人\n");
	printf("  4.修改联系人\n");
	printf("  5.显示所有联系人\n");
	printf("  6.清空通讯录\n");
	printf("  0.退出\n");
	printf("============================\n\n");

	int ret = 0;
	scanf("%d", &ret);
	return ret;
}

void Add_Person_Info(AddressBook* addr)//新增联系人
{
	if (addr->size >= MAX_SZIE)
	{
		printf("联系人已满，无法新建联系人！\n");
		return;
	}

	PersonalInfo* info = &addr->persons[addr->size];
	printf("新增联系人！\n");

	printf("请输入联系人姓名：");
	scanf("%s", info->name);
	printf("请输入联系人电话：");
	scanf("%s", info->phone);
	printf("请输入联系人性别：");
	scanf("%s", info->sex);
	printf("请输入联系人年龄：");
	scanf("%s", info->age);
	printf("请输入联系人住址：");
	scanf("%s", info->address);

	addr->size++;

	printf("新增联系人成功！\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Del_Person_Info(AddressBook* addr)//删除联系人
{
	if (addr->size <= 0)
	{
		printf("通讯录为空！无法执行删除！\n");
		return;
	}
	printf("删除联系人！\n");
	printf("请输入要删除的联系人序号：");
	int input = 0;
	scanf("%d", &input);
	if (input < 0 || input >= addr->size)
	{
		printf("非法输入！\n");
		return;
	}
	PersonalInfo* last_info = &addr->persons[addr->size - 1];
	PersonalInfo* to_delt = &addr->persons[input];
	*to_delt = *last_info;
	addr->size--;

	printf("联系人成功删除！\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Find_Person_Info(AddressBook* addr)//查找联系人
{
	char find[1024] = { 0 };
	printf("查找联系人！\n");
	printf("请输入想要查找的姓名或联系方式：");
	scanf("%s", &find);
	
	for (int i = 0; i < addr->size; i++)
	{
		PersonalInfo* findinfo = &addr->persons[i];
		if (strcmp(find, findinfo->name) == 0)
		{
			printf("找到了！该联系人编号为：%d\n", i);
			return;
		}
		if (strcmp(find, findinfo->phone) == 0)
		{
			printf("\n找到了！该联系人为：[%d]  姓名：%s   联系方式：%s\n", i,findinfo->name,findinfo->phone);
			return;
		}
	}
	printf("查无此人！\n");

}

void Modify_Person_Info(AddressBook* addr)//修改联系人信息
{
	if (addr->size <= 0)
	{
		printf("通讯录为空！无法执行！\n");
		return;
	}

	int i = 0;
	char name[1024];
	char sex[20];
	char age[10];
	char phone[1024];
	char address[1024];
	printf("修改联系人信息！\n");
	printf("请输入要修改的联系人编号：");
	scanf("%d", &i);
	if (i<0 || i>addr->size)
	{
		printf("输入非法！\n");
		return;
	}
	PersonalInfo* info = &addr->persons[i];

	printf("[%d]  姓名：%s   联系方式：%s \n     性别： %s  年龄： %s\n     住址：%s\n\n", i, info->name, info->phone, info->sex, info->age, info->address);

	printf("请输入要修改的姓名（输入 * 表示不进行修改）：");
	scanf("%s", name);
	if (strcmp(name , "*") != 0)
	{
		strcpy(addr->persons[i].name, name);
	}

	printf("请输入要修改的性别（输入 * 表示不进行修改）：");
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(addr->persons[i].sex, sex);
	}

	printf("请输入要修改的年龄（输入 * 表示不进行修改）：");
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(addr->persons[i].age, age);
	}

	printf("请输入要修改的联系方式（输入 * 表示不进行修改）：");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(addr->persons[i].phone, phone);
	}

	printf("请输入要修改的地址（输入 * 表示不进行修改）：");
	scanf("%s", address);
	if (strcmp(address, "*") != 0)
	{
		strcpy(addr->persons[i].address, address);
	}

	printf("修改成功！\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Print_Person_Info(AddressBook* addr)//输出联系人（全部）
{
	printf("显示所有联系人：\n\n");
	for (int i = 0; i < addr->size; i++)
	{
		PersonalInfo* info = &addr->persons[i];
		printf("[%d]  姓名：%s   联系方式：%s \n     性别： %s  年龄： %s\n     住址：%s\n\n", i,info->name ,info->phone,info->sex,info->age,info->address );
	}
	printf("\n到底了...\n");
}

void Clear_Person_Info(AddressBook* addr)//一键清空
{
	char clear[20] = { 0 };
	printf("\n清空通讯录！\n");
	printf("请确认是否清空  (Y/N)\n");
	scanf("%s", clear);

	if (strcmp(clear, "Y") == 0 || strcmp(clear, "y") == 0)
	{
		//addr->size = 0;
		Init(addr);
		printf("成功清空通讯录！\n");
		return;
	}
	else
	{
		printf("放弃清空\n");
	}

}