#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

void test1()
{
	BTDataType str[] = { "ABD##E#H##CF##G##" };
	int pi = 0;
	BTNode* root = BinaryTreeCreate(str, sizeof(str) / sizeof(str[0]) - 1, &pi);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	int num = BinaryTreeSize(root);
	printf("%d\n", num);
	num = BinaryTreeLeafSize(root);
	printf("%d\n", num);
	num = BinaryTreeLevelKSize(root, 3);
	printf("%d\n", num);
	BTNode* ret = BinaryTreeFind(root, 'G');
	if (!ret)
		printf("Î´ÕÒµ½\n");
	else
		printf("%c\n", ret->_data);
}

void test2()
{
	BTDataType str[] = { "ABD##E#H##CF##G##" };
	int pi = 0;
	BTNode* root = BinaryTreeCreate(str, sizeof(str) / sizeof(str[0]) - 1, &pi);
	BinaryTreePrevOrderNoR(root);
	BinaryTreeInOrderNoR(root);
	BinaryTreePostOrderNoR(root);
	BinaryTreeLevelOrder(root);
	int ret = BinaryTreeComplete(root);
	printf("%d \n", ret);
}

int main()
{
	test1();
	test2();
	return 0;
}