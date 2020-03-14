#define _CRT_SECURE_NO_WARNINGS 1

#include"AddressBook.h"

static void cmp(AddressBook* addr) //����
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

void Init(AddressBook* addr)//��ʼ��ͨѶ¼
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

int menu()//���˵�
{
	printf("============================\n");
	printf("  1.�½���ϵ��\n");
	printf("  2.ɾ����ϵ��\n");
	printf("  3.��ѯ��ϵ��\n");
	printf("  4.�޸���ϵ��\n");
	printf("  5.��ʾ������ϵ��\n");
	printf("  6.���ͨѶ¼\n");
	printf("  0.�˳�\n");
	printf("============================\n\n");

	int ret = 0;
	scanf("%d", &ret);
	return ret;
}

void Add_Person_Info(AddressBook* addr)//������ϵ��
{
	if (addr->size >= MAX_SZIE)
	{
		printf("��ϵ���������޷��½���ϵ�ˣ�\n");
		return;
	}

	PersonalInfo* info = &addr->persons[addr->size];
	printf("������ϵ�ˣ�\n");

	printf("��������ϵ��������");
	scanf("%s", info->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", info->phone);
	printf("��������ϵ���Ա�");
	scanf("%s", info->sex);
	printf("��������ϵ�����䣺");
	scanf("%s", info->age);
	printf("��������ϵ��סַ��");
	scanf("%s", info->address);

	addr->size++;

	printf("������ϵ�˳ɹ���\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Del_Person_Info(AddressBook* addr)//ɾ����ϵ��
{
	if (addr->size <= 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ִ��ɾ����\n");
		return;
	}
	printf("ɾ����ϵ�ˣ�\n");
	printf("������Ҫɾ������ϵ����ţ�");
	int input = 0;
	scanf("%d", &input);
	if (input < 0 || input >= addr->size)
	{
		printf("�Ƿ����룡\n");
		return;
	}
	PersonalInfo* last_info = &addr->persons[addr->size - 1];
	PersonalInfo* to_delt = &addr->persons[input];
	*to_delt = *last_info;
	addr->size--;

	printf("��ϵ�˳ɹ�ɾ����\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Find_Person_Info(AddressBook* addr)//������ϵ��
{
	char find[1024] = { 0 };
	printf("������ϵ�ˣ�\n");
	printf("��������Ҫ���ҵ���������ϵ��ʽ��");
	scanf("%s", &find);
	
	for (int i = 0; i < addr->size; i++)
	{
		PersonalInfo* findinfo = &addr->persons[i];
		if (strcmp(find, findinfo->name) == 0)
		{
			printf("�ҵ��ˣ�����ϵ�˱��Ϊ��%d\n", i);
			return;
		}
		if (strcmp(find, findinfo->phone) == 0)
		{
			printf("\n�ҵ��ˣ�����ϵ��Ϊ��[%d]  ������%s   ��ϵ��ʽ��%s\n", i,findinfo->name,findinfo->phone);
			return;
		}
	}
	printf("���޴��ˣ�\n");

}

void Modify_Person_Info(AddressBook* addr)//�޸���ϵ����Ϣ
{
	if (addr->size <= 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ִ�У�\n");
		return;
	}

	int i = 0;
	char name[1024];
	char sex[20];
	char age[10];
	char phone[1024];
	char address[1024];
	printf("�޸���ϵ����Ϣ��\n");
	printf("������Ҫ�޸ĵ���ϵ�˱�ţ�");
	scanf("%d", &i);
	if (i<0 || i>addr->size)
	{
		printf("����Ƿ���\n");
		return;
	}
	PersonalInfo* info = &addr->persons[i];

	printf("[%d]  ������%s   ��ϵ��ʽ��%s \n     �Ա� %s  ���䣺 %s\n     סַ��%s\n\n", i, info->name, info->phone, info->sex, info->age, info->address);

	printf("������Ҫ�޸ĵ����������� * ��ʾ�������޸ģ���");
	scanf("%s", name);
	if (strcmp(name , "*") != 0)
	{
		strcpy(addr->persons[i].name, name);
	}

	printf("������Ҫ�޸ĵ��Ա����� * ��ʾ�������޸ģ���");
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(addr->persons[i].sex, sex);
	}

	printf("������Ҫ�޸ĵ����䣨���� * ��ʾ�������޸ģ���");
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(addr->persons[i].age, age);
	}

	printf("������Ҫ�޸ĵ���ϵ��ʽ������ * ��ʾ�������޸ģ���");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(addr->persons[i].phone, phone);
	}

	printf("������Ҫ�޸ĵĵ�ַ������ * ��ʾ�������޸ģ���");
	scanf("%s", address);
	if (strcmp(address, "*") != 0)
	{
		strcpy(addr->persons[i].address, address);
	}

	printf("�޸ĳɹ���\n");

	if (addr->size >= 2)
	{
		cmp(addr);
	}
}

void Print_Person_Info(AddressBook* addr)//�����ϵ�ˣ�ȫ����
{
	printf("��ʾ������ϵ�ˣ�\n\n");
	for (int i = 0; i < addr->size; i++)
	{
		PersonalInfo* info = &addr->persons[i];
		printf("[%d]  ������%s   ��ϵ��ʽ��%s \n     �Ա� %s  ���䣺 %s\n     סַ��%s\n\n", i,info->name ,info->phone,info->sex,info->age,info->address );
	}
	printf("\n������...\n");
}

void Clear_Person_Info(AddressBook* addr)//һ�����
{
	char clear[20] = { 0 };
	printf("\n���ͨѶ¼��\n");
	printf("��ȷ���Ƿ����  (Y/N)\n");
	scanf("%s", clear);

	if (strcmp(clear, "Y") == 0 || strcmp(clear, "y") == 0)
	{
		//addr->size = 0;
		Init(addr);
		printf("�ɹ����ͨѶ¼��\n");
		return;
	}
	else
	{
		printf("�������\n");
	}

}