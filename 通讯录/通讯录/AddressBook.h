#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX_SZIE 1000

typedef struct PersonalInfo
{
	char name[1024];
	char sex[20];
	char age[10];
	char phone[1024];
	char address[1024];
}PersonalInfo;

typedef struct AddressBook
{
	PersonalInfo* persons;
	int size;
	int nums;
}AddressBook;

AddressBook address_book;

void Init(AddressBook* addr);

int menu();

void Add_Person_Info(AddressBook* addr);
void Del_Person_Info(AddressBook* addr);
void Find_Person_Info(AddressBook* addr);
void Modify_Person_Info(AddressBook* addr);
void Print_Person_Info(AddressBook* addr);
void Clear_Person_Info(AddressBook* addr);