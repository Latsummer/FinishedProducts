//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//
//
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��

#include"AddressBook.h"

void Open(AddressBook* addr)
{
	FILE* addbook = fopen("C:book.txt", "r");
	if (addbook == NULL)
	{
		perror("�ļ���ʧ�ܣ�");
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
		perror("�ļ���ʧ�ܣ�");
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
		NULL,//�˴�Ϊ�˺�menu�ķ���ֵƥ�䣬��function[0]������д��NULL
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
			printf("�������\n\n");
			continue;
		}
		function[choice](&address_book);

	}
	return 0;
}