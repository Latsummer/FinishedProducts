#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
#include"stack.h"
#include "queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int n, int* pi)
{
	if (a[*pi] != '#' && *pi < n)
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	return NULL;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	BTNode* cur = *root;
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		*root = NULL;
	}
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	/*if (root)
	{
		int left = BinaryTreeSize(root->_left);
		int right = BinaryTreeSize(root->_right);
		return left + right + 1;
	}
	return 0;*/
	if (!root)
		return 0;
	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right)
		+ 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	if (!root->_left && !root->_right)
		return 1;
	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (!root)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	return BinaryTreeFind(root->_right, x);

}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreePrevOrderNoR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	BTNode* top = NULL;
	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;

	}
	printf("\n");
}

// 二叉树中序遍历

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreeInOrderNoR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	BTNode* top = NULL;
	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		StackPop(&st);
		printf("%c ", top->_data);
		cur = top->_right;
	}
	printf("\n");
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

void BinaryTreePostOrderNoR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	BTNode* top = NULL;
	BTNode* prev = NULL;
	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		if (!top->_right || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		else
			cur = top->_right;
	}
	printf("\n");
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
}

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
			break;
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return 0;
	}
	return 1;
}