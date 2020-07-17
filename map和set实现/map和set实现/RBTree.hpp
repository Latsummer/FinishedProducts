#include <iostream>
using namespace std;

enum Color
{
	BLACK,
	RED
};

template <class V>
struct RBNode
{
	V _value;
	Color _color;
	RBNode<V>* _parent;
	RBNode<V>* _left;
	RBNode<V>* _right;

	RBNode(const V& value = V())
		: _value(value)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{ }
};

template <class V>
struct RBTIterator
{
	typedef RBNode<V> Node;
	typedef RBTIterator<V> Self;
	//Node* _node;
	RBTIterator(Node* node)
		: _node(node)
	{ }

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
	}

	Self& operator++()
	{
		add();
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		add();
		return tmp;
	}

	Self& operator--()
	{
		sub();
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		sub();
		return tmp;
	}
private:
	void add()
	{
		if (_node->_right)
		{
			//若右子树存在，下一个位置为右子树的最左节点
			_node = _node->_right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			//右子树不存在，向上回溯
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_right != parent)
				_node = parent;
		}

	}

	void sub()
	{
		if (_node->_parent->_parent == _node && _node->_color == RED)
			_node = _node->_right;
		else if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
				_node = _node->_right;
		}
		else
		{
			Node* pParent = _node->_parent;
			while (pParent->_left == _node)
			{
				_node = pParent;
				pParent = _node->_parent;
			}

			_node = pParent;
		}
	}

	Node* _node;
};


template <class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef RBTIterator<V> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}

	iterator end()
	{
		return iterator(_header);
	}


	RBTree()
		: _header(new Node)
	{
		_header->_left = _header->_right = _header;
	}

	bool empty()
	{
		if (_header->_parent == nullptr)
			return true;
		return false;
	}

	pair<iterator, bool> insert(const V& val)
	{
		if (_header->_parent == nullptr)
		{
			//空树
			Node* root = new Node(val);
			root->_color = BLACK;//根为黑色

			_header->_parent = root;
			root->_parent = _header;

			_header->_left = root;
			_header->_right = root;

			return make_pair(iterator(root), true);
		}
		//非空树
		Node* cur = _header->_parent;
		Node* parent = nullptr;
		KeyOfValue kov;
		while (cur)
		{
			parent = cur;
			if (kov(cur->_value) == kov(val))
				return make_pair(iterator(cur), false);
			if (kov(cur->_value) < kov(val))
				cur = cur->_right;
			else
				cur = cur->_left;
		}

		cur = new Node(val);
		Node* node = cur;
		if (kov(parent->_value) < kov(val))
			parent->_right = cur;
		else
			parent->_left = cur;

		cur->_parent = parent;

		//调整:修改颜色，旋转
		while (cur != _header->_parent && cur->_parent->_color == RED)
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
		_header->_parent->_color = BLACK;
		//更新头的左右指针
		_header->_left = leftMost();
		_header->_right = rightMost();

		return make_pair(iterator(node), true);
	}

	iterator Find(const K& data)
	{
		Node* cur = _header->_parent;
		while (cur->_value != data && cur != nullptr)
		{
			if (data < cur->_value)
				cur = cur->_left;
			else if (data > cur->_value)
				cur = cur->_right;
		}
		if (cur == nullptr)
			return end();
		else
			return iterator(cur);
	}

	size_t _size(RBNode<V>* root)
	{
		if (root == nullptr)
			return 0;
		size_t letf = _size(root->_left);
		size_t right = _size(root->_right);
		size_t ret = left + right + 1;
		return ret;
	}

	size_t size()
	{
		return (_size(_header->_parent));
	}

	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_left)
			cur = cur->_left;
		return cur;
	}

	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}

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

		if (g == _header)
			_header->_parent = subR;
		else
		{
			if (parent == g->_left)
				g->_left = subR;
			else
				g->_right = subR;
		}*/

		if (parent == _header->_parent)
		{
			_header->_parent = subR;
			subR->_parent = _header;
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

		if (g == _header)
			_header->_parent = subL;
		else
		{
			if (parent == g->_left)
				g->_left = subL;
			else
				g->_right = subL;
		}*/

		if (parent == _header->_parent)
		{
			_header->_parent = subL;
			subL->_parent = _header;
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

	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << kov(root->_value) << " ";
			_inorder(root->_right);
		}

	}
	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}

	bool isRBTree()
	{
		Node* root = _header->_parent;
		if (root == nullptr)
			return true;
		if (root->_color != BLACK)
			return false;

		int blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->_color == BLACK)
				blackCount++;
			cur = cur->_left;
		}
		int curCount = 0;

		return _isRBTree(root, blackCount, curCount++);
	}

	bool _isRBTree(Node* root, int blackCount, int curCount)
	{
		//当前路径上黑色个数是否相同
		if (root == nullptr)
		{
			if (blackCount != curCount)
				return false;
			return true;
		}
		//如果节点为黑色，累加
		if (root->_color == BLACK)
			curCount++;

		Node* parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
			return false;

		return _isRBTree(root->_left, blackCount, curCount)
			&& _isRBTree(root->_right, blackCount, curCount);
	}
private:
	Node* _header;
};
