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



int main()
{
	Init(&address_book);
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