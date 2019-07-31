#pragma once
#include "normalHead_CPP.h"

// 下面实现链式存储结构的二叉树
#define DataType int

// 树节点
class TreeNode {
public:
	TreeNode(DataType value);
	TreeNode(DataType value, TreeNode* left, TreeNode* right);
	void Visit();

	DataType data;      // 节点存储的数据
	TreeNode* lchild;   // 左孩子
	TreeNode* rchild;   // 右孩子
};

// 二叉树
class BTree {
public:
	BTree();
	~BTree();

	// 初始化二叉树
	void BTreeInit();
	// 销毁整个二叉树
	void BTreeDestory(); 
	// 销毁指定子树，此处实现采用递归方式，类似于后序遍历
	void DestoryChild(TreeNode** node);

	// 创建特殊形式的二叉树
    // 创建指定高度的满二叉树
	// void CreateFBT(int n); 
	// 满二叉树、完全二叉树更适合使用连续存储结构

	// 各种形式的遍历
	// 遍历的递归实现(先序、中序、后序)
	void BTreeNLRTraverse_r(TreeNode* root);
	void BTreeLNRTraverse_r(TreeNode* root);
	void BTreeLRNTraverse_r(TreeNode* root);

	// 遍历的非递归实现(先序、中序、后序)
	void BTreeNLRTraverse();
	void BTreeLNRTraverse();
	void BTreeLRNTraverse();

	// 树的层次遍历
	void BTreeLevelTraverse();

	// 二叉树自下而上，从右到左(与层次遍历相反)
	// 实现，将层次遍历时出队的节点入栈
	void BTreeInvertLevel();

	// 判断是否为空树
	bool BTreeEmpty();
	// 求树的高度
	int BTreeHeight(int tag);
	// 求指定子树的高度
	// 递归实现与非递归实现
	int ChildHeight_r(TreeNode* node);
	int ChildHeight(TreeNode* node);

    // 求树的宽度
	int BTreeWidth();
	// 求指定子树的宽度
	int ChildWidth(TreeNode* node); 
	
	// 转换为线索二叉树
	//void toIndexBTree();



private:
	TreeNode* root;   // 根节点
};


// 线索二叉树
// 在有n个节点的二叉树，有n+1个空指针，在二叉树线索化时，通常若无左子树，令
// lchild指向其前驱节点，若无右子树，令其rchild指向其后继节点，为了区分左右
// 孩子节点指向的是真正的孩子节点还是前驱或后继，通常需要一个标志标识
class ThreadBTNode {
public:
	DataType data;
	ThreadBTNode* lchild, * rchild;
	int ltag, rtag;     // 标志为0时标识实际孩子节点，标志为1时标识前驱或后继
};

class ThreadBTree {
public:
	// 通过中序遍历建立中序线索二叉树
	void InThread(ThreadBTNode* root, ThreadBTNode* pre);
	void CreateInThread();

private:
	ThreadBTNode* root;
};



