#include <iostream>
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class T>
struct RBTreeNode
{
	T _value;
	Color _color;
	RBTreeNode<T>* _parent;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;

	RBTreeNode(const T& value = T())
		: _value(value)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{ }
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_left = _pHead;
		_pHead->_right = _pHead;
	}

	// �ں�����в���ֵΪdata�Ľڵ㣬����ɹ�����true�����򷵻�false
	// ע�⣺Ϊ�˼����������ʵ�ֺ�������洢�ظ���Ԫ��
	bool Insert(const T& data)
	{
		if (_pHead->_parent == nullptr)
		{
			//����
			Node* root = new Node(data);
			root->_color = BLACK;//��Ϊ��ɫ

			_pHead->_parent = root;
			root->_parent = _pHead;

			_pHead->_left = root;
			_pHead->_right = root;

			return true;
		}
		//�ǿ���
		Node* cur = _pHead->_parent;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == data)
				return false;
			if (cur->_value < data)
				cur = cur->_right;
			else
				cur = cur->_left;
		}

		cur = new Node(data);
		if (parent->_value < data)
			parent->_right = cur;
		else
			parent->_left = cur;

		cur->_parent = parent;

		//����:�޸���ɫ����ת
		while (cur != _pHead->_parent && cur->_parent->_color == RED)
		{
			Node* p = cur->_parent;
			Node* g = p->_parent;
			if (g->_left == p)
			{
				Node* u = g->_right;
				if (u && u->_color == RED)
				{
					u->_color = p->_color = BLACK;
					g->_color = RED;

					cur = g;
				}
				else
				{
					//ub�����ڻ�u������Ϊ��ɫ
					if (cur == p->_right)
					{
						RotateL(p);
						swap(cur, p);
					}

					//cur��p���,����+�޸���ɫ
					RotateR(g);
					p->_color = BLACK;
					g->_color = RED;

					break;
				}

			}
			else//p��g�ұ�
			{
				Node* u = g->_left;
				if (u && u->_color == RED)
				{
					u->_color = p->_color = BLACK;
					g->_color = RED;
					cur = g;
				}
				else
				{
					if (cur == p->_left)
					{
						RotateR(p);
						swap(cur, p);
					}

					RotateL(g);
					g->_color = RED;
					p->_color = BLACK;

					break;
				}
			}

		}
		//������Ϊ��
		_pHead->_parent->_color = BLACK;
		//����ͷ������ָ��
		_pHead->_left = leftMost();
		_pHead->_right = rightMost();

		return true;
	}

	// ����������Ƿ����ֵΪdata�Ľڵ㣬���ڷ��ظýڵ�ĵ�ַ�����򷵻�nullptr
	Node* Find(const T& data)
	{
		Node* cur = GetRoot();
		while (cur->_value != data && cur != nullptr)
		{
			if (data < cur->_value)
				cur = cur->_left;
			else if (data > cur->_value)
				cur = cur->_right;
		}
		if (cur == nullptr)
			return nullptr;
		else
			return cur;
	}

	// ��ȡ����������ڵ�
	Node* leftMost()
	{
		Node* cur = _pHead->_parent;
		while (cur && cur->_left)
			cur = cur->_left;
		return cur;
	}

	// ��ȡ��������Ҳ�ڵ�
	Node* rightMost()
	{
		Node* cur = _pHead->_parent;
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}

	// ��������Ƿ�Ϊ��Ч�ĺ������ע�⣺���ڲ���Ҫ����_IsValidRBTRee�������
	bool IsValidRBTRee()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "Υ������һ�����ڵ��Ǻ�ɫ" << endl;
			return false;
		}

		// ��ȡһ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				blackCount++;

			pCur = pCur->_pLeft;
		}

		size_t pathBalck = 0;
		return _IsValidRBTRee(pRoot, blackCount, pathBalck);
	}
private:
	bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color == BLACK)
			pathBlack++;

		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead &&
			RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "Υ������3�����ܴ�������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		// Ҷ�ӽڵ�
		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			if (pathBlack != blackCount)
			{
				cout << "Υ������4��ÿ��·���к�ɫ�ڵ��������ͬ" << endl;
				return false;
			}
		}

		return _IsValidRBTRee(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTRee(pRoot->_pRight, blackCount, pathBlack);
	}
	// ����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;

		if (subRL)
			subRL->_parent = parent;

		/*subR->_left = parent;
		Node* g = parent->_parent;
		subR->_parent = g;
		parent->_parent = subR;

		if (g == _pHead)
			_pHead->_parent = subR;
		else
		{
			if (parent == g->_left)
				g->_left = subR;
			else
				g->_right = subR;
		}*/

		if (parent == _pHead->_parent)
		{
			_pHead->_parent = subR;
			subR->_parent = _pHead;
		}
		else
		{
			Node* g = parent->_parent;
			subR->_parent = g;
			if (g->_left == parent)
				g->_left = subR;
			else
				g->_right = subR;
		}

		parent->_parent = subR;
	}
	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		/*if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* g = parent->_parent;
		parent->_parent = subL;
		subL->_parent = g;

		if (g == _pHead)
			_pHead->_parent = subL;
		else
		{
			if (parent == g->_left)
				g->_left = subL;
			else
				g->_right = subL;
		}*/

		if (parent == _pHead->_parent)
		{
			_pHead->_parent = subL;
			subL->_parent = _pHead;
		}
		else
		{
			Node* g = parent->_parent;
			subL->_parent = g;
			if (g->_left == parent)
				g->_left = subL;
			else
				g->_right = subL;
		}

		parent->_parent = subL;
	}
	// Ϊ�˲��������������ȡ���ڵ�
	Node*& GetRoot()
	{
		return _pHead->_parent;
	}
private:
	Node* _pHead;
};

int main()
{
	RBTree<int> rbt;
	rbt.Insert(1);
	rbt.Insert(3);
	rbt.Insert(2);
	rbt.Insert(4);

	RBTreeNode<int>* p = rbt.Find(3);
	cout << p->_value;
	return 0;
}