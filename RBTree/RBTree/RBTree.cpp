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

	// 在红黑树中插入值为data的节点，插入成功返回true，否则返回false
	// 注意：为了简单起见，本次实现红黑树不存储重复性元素
	bool Insert(const T& data)
	{
		if (_pHead->_parent == nullptr)
		{
			//空树
			Node* root = new Node(data);
			root->_color = BLACK;//根为黑色

			_pHead->_parent = root;
			root->_parent = _pHead;

			_pHead->_left = root;
			_pHead->_right = root;

			return true;
		}
		//非空树
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

		//调整:修改颜色，旋转
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
					//ub不存在或u存在且为黑色
					if (cur == p->_right)
					{
						RotateL(p);
						swap(cur, p);
					}

					//cur在p左边,右旋+修改颜色
					RotateR(g);
					p->_color = BLACK;
					g->_color = RED;

					break;
				}

			}
			else//p在g右边
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
		//将根置为黑
		_pHead->_parent->_color = BLACK;
		//更新头的左右指针
		_pHead->_left = leftMost();
		_pHead->_right = rightMost();

		return true;
	}

	// 检测红黑树中是否存在值为data的节点，存在返回该节点的地址，否则返回nullptr
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

	// 获取红黑树最左侧节点
	Node* leftMost()
	{
		Node* cur = _pHead->_parent;
		while (cur && cur->_left)
			cur = cur->_left;
		return cur;
	}

	// 获取红黑树最右侧节点
	Node* rightMost()
	{
		Node* cur = _pHead->_parent;
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}

	// 检测红黑树是否为有效的红黑树，注意：其内部主要依靠_IsValidRBTRee函数检测
	bool IsValidRBTRee()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "违反性质一：根节点是黑色" << endl;
			return false;
		}

		// 获取一条路径中黑色节点的个数
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
			cout << "违反性质3：不能存在连在一起的红色节点" << endl;
			return false;
		}

		// 叶子节点
		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			if (pathBlack != blackCount)
			{
				cout << "违反性质4：每条路径中黑色节点个数均相同" << endl;
				return false;
			}
		}

		return _IsValidRBTRee(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTRee(pRoot->_pRight, blackCount, pathBlack);
	}
	// 左单旋
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
	// 右单旋
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
	// 为了操作树简单起见：获取根节点
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