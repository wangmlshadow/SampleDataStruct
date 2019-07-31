#include "tree.h"
#include <stack>
#include <queue>

// �������ڵ�
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


// ������
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
	
	// ������������
	DestoryChild(&(*root)->lchild);
	(*root)->lchild = nullptr;

	DestoryChild(&(*root)->rchild);
	(*root)->rchild = nullptr;

	// ���ٸ��ڵ�
	delete(*root);
	*root = nullptr;    // ���������ٺ�ԭ��ָ��������ָ����Ϊ��
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

// �������ķǵݹ������Ҫʹ��ջ
// ����ʹ�ñ�׼���е�std::stack��Ҳ����ʹ����������һ���򵥵�ջ
void BTree::BTreeNLRTraverse()
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	s.push(p);

	while (!s.empty()) {    // ջ��Ϊ�� �����нڵ�δ������
		p = s.top();
		s.pop();
		p->Visit();

		if (p->rchild) {    // ���������ڵ���ջ
			s.push(p->rchild);
		}

		if (p->lchild) {    // ���������ڵ���ջ
			s.push(p->lchild);
		}
	}
}

void BTree::BTreeLNRTraverse()
{
	std::stack<TreeNode *> s;   // ����һ���洢���ڵ�ָ���ջ
	TreeNode* p;
	p = root;
	while (!p || !s.empty()) {  // p��ջ��Ϊ��ʱִ��ѭ��
		if (p) {
			s.push(p);          // ��ָ����ջ
			p = p->lchild;      // ����
		}
		else {                  // ��ջ ���ʸ��ڵ�
			p = s.top();
			p->Visit();
			s.pop();
			p = p->rchild;      // ����
		}
	}
}

void BTree::BTreeLRNTraverse()
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	TreeNode* last = nullptr;

	while (p || !s.empty()) {
		if (p) {            // �ߵ������
			s.push(p);
			p = p->lchild;
		}
		else {              // ����
			p = s.top();

			if (p->rchild && p->rchild != last) {   // p��������������������û�����ʹ�
				p = p->rchild;   // ����
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

// ��α�����Ҫʹ�ö�����Ϊ����
void BTree::BTreeLevelTraverse()
{
	if (!root)   // ���� �߶�Ϊ0
		return;

	TreeNode* p = root;
	std::queue<TreeNode*> q;
	q.push(p);    // ���ڵ����

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
	if (!root)   // ���� �߶�Ϊ0
		return;

	TreeNode* p = root;
	std::queue<TreeNode*> q;
	std::stack<TreeNode*> s;
	q.push(p);    // ���ڵ����

	while (!q.empty()) {
		p = q.front();
		// p->Visit(); ֻ�轫visit��Ϊ��ջ
		s.push(p);
		q.pop();

		if (p->lchild)
			q.push(p->lchild);

		if (p->rchild)
			q.push(p->rchild);
	}

	// ������¶��ϴ��ҵ��������
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
	if (tag == 0)   // 0��ʶ�ݹ�ʵ��
	    return ChildHeight_r(root);
	else            // �ǵݹ�
		return ChildHeight(root);
}

int BTree::ChildHeight_r(TreeNode* node)
{
	if (node == nullptr)
		return 0;

	int left = ChildHeight_r(node->lchild);  // �������߶�
	int right = ChildHeight_r(node->rchild); // �������߶�

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

// ��������ĸ߶� �ǵݹ�ʵ�� ͨ����α���
int ChildHeight(TreeNode* node)
{
	if (!node)   // ���� �߶�Ϊ0
		return 0;

	int height = 0;
	TreeNode* p = node;
	TreeNode* last = node;  // ָ��ǰ�����Ҷ˽ڵ�
	std::queue<TreeNode*> q;
	q.push(p);    // ���ڵ����

	while (!q.empty()) {
		p = q.front();        // ����Ԫ�س��ӣ�pΪ���ڷ��ʵĽڵ�
		q.pop();

		// ���Һ������
		if (p->lchild)
			q.push(p->lchild);

		if (p->rchild)
			q.push(p->rchild);

		if (p == last) {
			height++;
			last = q.back();   // ��last����Ϊÿһ�����ҵĽڵ�
		}
	}

	return height;
}

int BTree::BTreeWidth()
{
	return ChildWidth(root);
}

// ͨ����α���ʵ��
int BTree::ChildWidth(TreeNode* node)
{
	if (!node)   // ���� ���Ϊ0
		return 0;

	int pre = 0, now = 0;
	TreeNode* p = node;
	TreeNode* last = node;  // ָ��ǰ�����Ҷ˽ڵ�
	std::queue<TreeNode*> q;
	q.push(p);    // ���ڵ����
	pre++;

	while (!q.empty()) {
		p = q.front();        // ����Ԫ�س��ӣ�pΪ���ڷ��ʵĽڵ�
		q.pop();

		// ���Һ������
		if (p->lchild) {
			q.push(p->lchild);
			now++;
		}
			

		if (p->rchild) {
			q.push(p->rchild);
			now++;
		}
			

		if (p == last) {   // һ�����
			if (pre <= now)
				pre = now;

			now = 0;   // ����now
			last = q.back();   // ��last����Ϊÿһ�����ҵĽڵ�
		}
	}

	return pre;
}




// ����������
void ThreadBTree::InThread(ThreadBTNode* root, ThreadBTNode* pre)
{
	if (root != nullptr) {
		InThread(root->lchild, pre);    // ������������

		if (root->lchild == nullptr) {  // ������Ϊ�գ�����ǰ������
			root->lchild = pre;
			root->ltag = 1;
		}

		if (pre != nullptr && pre->rchild == nullptr) {  // ����ǰ���ڵ�������
			pre->rchild = root;     // �����������Ϊ���ӣ��������ӽڵ����Һ��ӵĽڵ㣬���Ϊ�丸�ڵ�  
			pre->rtag = 1;
		}

		pre = root;
		InThread(root->rchild, pre);   // ������������
	}
}

void ThreadBTree::CreateInThread()
{
	ThreadBTNode* pre = nullptr;
	
	if (root != nullptr) {
		InThread(root, pre);
		pre->rchild = nullptr;   // ���һ���ڵ���Ϊ��(������������ұߵĽڵ�)
		pre->rtag = 1;
	}
}

























