#include "tree.h"
#include <stack>
#include <queue>

// 二叉树节点
TreeNode::TreeNode(DataType value)
{
	data = value;
	lchild = nullptr;
	rchild = nullptr;
}

TreeNode::TreeNode(DataType value, TreeNode* left, TreeNode* right)
{
	data = value;
	lchild = left;
	rchild = right;
}

void TreeNode::Visit()
{
	std::cout << data << std::endl;
}


// 二叉树
BTree::BTree() 
{
	BTreeInit();
}


BTree::~BTree() 
{
	BTreeDestory();
}

void BTree::BTreeInit()
{
	root = nullptr;
}

void BTree::BTreeDestory()
{
	DestoryChild(&root);
}

void BTree::DestoryChild(TreeNode** root)
{
	if (*root == nullptr)
		return;
	
	// 销毁左右子树
	DestoryChild(&(*root)->lchild);
	(*root)->lchild = nullptr;

	DestoryChild(&(*root)->rchild);
	(*root)->rchild = nullptr;

	// 销毁根节点
	delete(*root);
	*root = nullptr;    // 子树被销毁后，原来指向子树的指针设为空
}

void BTree::BTreeNLRTraverse_r(TreeNode* root)
{
	if (root == nullptr)
		return;

	// N
	root->Visit();

	// L
	BTreeNLRTraverse_r(root->lchild);

	// R
	BTreeNLRTraverse_r(root->rchild);
}

void BTree::BTreeLNRTraverse_r(TreeNode* root)
{
	if (root == nullptr)
		return;

	// L
	BTreeNLRTraverse_r(root->lchild);

	// N
	root->Visit();

	// R
	BTreeNLRTraverse_r(root->rchild);
}

void BTree::BTreeLRNTraverse_r(TreeNode* root)
{
	if (root == nullptr)
		return;

	// L
	BTreeNLRTraverse_r(root->lchild);

	// R
	BTreeNLRTraverse_r(root->rchild);

	// N
	root->Visit();
}

// 二叉树的非递归遍历需要使用栈
// 下面使用标准库中的std::stack，也可以使用数组制作一个简单的栈
void BTree::BTreeNLRTraverse()
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	s.push(p);

	while (!s.empty()) {    // 栈不为空 即仍有节点未被访问
		p = s.top();
		s.pop();
		p->Visit();

		if (p->rchild) {    // 右子树根节点入栈
			s.push(p->rchild);
		}

		if (p->lchild) {    // 左子树根节点入栈
			s.push(p->lchild);
		}
	}
}

void BTree::BTreeLNRTraverse()
{
	std::stack<TreeNode *> s;   // 创建一个存储树节点指针的栈
	TreeNode* p;
	p = root;
	while (!p || !s.empty()) {  // p或栈不为空时执行循环
		if (p) {
			s.push(p);          // 根指针入栈
			p = p->lchild;      // 向左
		}
		else {                  // 退栈 访问根节点
			p = s.top();
			p->Visit();
			s.pop();
			p = p->rchild;      // 向右
		}
	}
}

void BTree::BTreeLRNTraverse()
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	TreeNode* last = nullptr;

	while (p || !s.empty()) {
		if (p) {            // 走到最左边
			s.push(p);
			p = p->lchild;
		}
		else {              // 向右
			p = s.top();

			if (p->rchild && p->rchild != last) {   // p存在右子树，且右子树没被访问过
				p = p->rchild;   // 向右
				s.push(p);
				p = p->lchild;
			}
			else {      // visit
				p = s.top();
				s.pop();
				p->Visit();
				last = p;
				p = nullptr;
			}
		}
	}
}

// 层次遍历需要使用队列作为辅助
void BTree::BTreeLevelTraverse()
{
	if (!root)   // 空树 高度为0
		return;

	TreeNode* p = root;
	std::queue<TreeNode*> q;
	q.push(p);    // 根节点入队

	while (!q.empty()) {
		p = q.front();
		p->Visit();
		q.pop();

		if (p->lchild)
			q.push(p->lchild);

		if (p->rchild)
			q.push(p->rchild);
	}
}

void BTree::BTreeInvertLevel()
{
	if (!root)   // 空树 高度为0
		return;

	TreeNode* p = root;
	std::queue<TreeNode*> q;
	std::stack<TreeNode*> s;
	q.push(p);    // 根节点入队

	while (!q.empty()) {
		p = q.front();
		// p->Visit(); 只需将visit变为入栈
		s.push(p);
		q.pop();

		if (p->lchild)
			q.push(p->lchild);

		if (p->rchild)
			q.push(p->rchild);
	}

	// 输出自下而上从右到左的序列
	while (!s.empty) {
		p = s.top();
		p->Visit();
		s.pop();
	}
}

bool BTree::BTreeEmpty()
{
	if (root == nullptr)
		return true;
	else
		return false;
}

int BTree::BTreeHeight(int tag)
{
	if (tag == 0)   // 0标识递归实现
	    return ChildHeight_r(root);
	else            // 非递归
		return ChildHeight(root);
}

int BTree::ChildHeight_r(TreeNode* node)
{
	if (node == nullptr)
		return 0;

	int left = ChildHeight_r(node->lchild);  // 左子树高度
	int right = ChildHeight_r(node->rchild); // 右子树高度

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

// 求二叉树的高度 非递归实现 通过层次遍历
int ChildHeight(TreeNode* node)
{
	if (!node)   // 空树 高度为0
		return 0;

	int height = 0;
	TreeNode* p = node;
	TreeNode* last = node;  // 指向当前层最右端节点
	std::queue<TreeNode*> q;
	q.push(p);    // 根节点入队

	while (!q.empty()) {
		p = q.front();        // 队列元素出队，p为正在访问的节点
		q.pop();

		// 左右孩子入队
		if (p->lchild)
			q.push(p->lchild);

		if (p->rchild)
			q.push(p->rchild);

		if (p == last) {
			height++;
			last = q.back();   // 将last设置为每一层最右的节点
		}
	}

	return height;
}

int BTree::BTreeWidth()
{
	return ChildWidth(root);
}

// 通过层次遍历实现
int BTree::ChildWidth(TreeNode* node)
{
	if (!node)   // 空树 宽度为0
		return 0;

	int pre = 0, now = 0;
	TreeNode* p = node;
	TreeNode* last = node;  // 指向当前层最右端节点
	std::queue<TreeNode*> q;
	q.push(p);    // 根节点入队
	pre++;

	while (!q.empty()) {
		p = q.front();        // 队列元素出队，p为正在访问的节点
		q.pop();

		// 左右孩子入队
		if (p->lchild) {
			q.push(p->lchild);
			now++;
		}
			

		if (p->rchild) {
			q.push(p->rchild);
			now++;
		}
			

		if (p == last) {   // 一层结束
			if (pre <= now)
				pre = now;

			now = 0;   // 重置now
			last = q.back();   // 将last设置为每一层最右的节点
		}
	}

	return pre;
}




// 线索二叉树
void ThreadBTree::InThread(ThreadBTNode* root, ThreadBTNode* pre)
{
	if (root != nullptr) {
		InThread(root->lchild, pre);    // 线索化左子树

		if (root->lchild == nullptr) {  // 左子树为空，建立前驱线索
			root->lchild = pre;
			root->ltag = 1;
		}

		if (pre != nullptr && pre->rchild == nullptr) {  // 建立前驱节点后继线索
			pre->rchild = root;     // 中序遍历，作为左孩子，但该左孩子节点无右孩子的节点，后继为其父节点  
			pre->rtag = 1;
		}

		pre = root;
		InThread(root->rchild, pre);   // 线索化右子树
	}
}

void ThreadBTree::CreateInThread()
{
	ThreadBTNode* pre = nullptr;
	
	if (root != nullptr) {
		InThread(root, pre);
		pre->rchild = nullptr;   // 最后一个节点后继为空(中序遍历，最右边的节点)
		pre->rtag = 1;
	}
}

























