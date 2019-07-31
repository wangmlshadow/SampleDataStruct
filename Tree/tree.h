#pragma once
#include "normalHead_CPP.h"

// ����ʵ����ʽ�洢�ṹ�Ķ�����
#define DataType int

// ���ڵ�
class TreeNode {
public:
	TreeNode(DataType value);
	TreeNode(DataType value, TreeNode* left, TreeNode* right);
	void Visit();

	DataType data;      // �ڵ�洢������
	TreeNode* lchild;   // ����
	TreeNode* rchild;   // �Һ���
};

// ������
class BTree {
public:
	BTree();
	~BTree();

	// ��ʼ��������
	void BTreeInit();
	// ��������������
	void BTreeDestory(); 
	// ����ָ���������˴�ʵ�ֲ��õݹ鷽ʽ�������ں������
	void DestoryChild(TreeNode** node);

	// ����������ʽ�Ķ�����
    // ����ָ���߶ȵ���������
	// void CreateFBT(int n); 
	// ������������ȫ���������ʺ�ʹ�������洢�ṹ

	// ������ʽ�ı���
	// �����ĵݹ�ʵ��(�������򡢺���)
	void BTreeNLRTraverse_r(TreeNode* root);
	void BTreeLNRTraverse_r(TreeNode* root);
	void BTreeLRNTraverse_r(TreeNode* root);

	// �����ķǵݹ�ʵ��(�������򡢺���)
	void BTreeNLRTraverse();
	void BTreeLNRTraverse();
	void BTreeLRNTraverse();

	// ���Ĳ�α���
	void BTreeLevelTraverse();

	// ���������¶��ϣ����ҵ���(���α����෴)
	// ʵ�֣�����α���ʱ���ӵĽڵ���ջ
	void BTreeInvertLevel();

	// �ж��Ƿ�Ϊ����
	bool BTreeEmpty();
	// �����ĸ߶�
	int BTreeHeight(int tag);
	// ��ָ�������ĸ߶�
	// �ݹ�ʵ����ǵݹ�ʵ��
	int ChildHeight_r(TreeNode* node);
	int ChildHeight(TreeNode* node);

    // �����Ŀ��
	int BTreeWidth();
	// ��ָ�������Ŀ��
	int ChildWidth(TreeNode* node); 
	
	// ת��Ϊ����������
	//void toIndexBTree();



private:
	TreeNode* root;   // ���ڵ�
};


// ����������
// ����n���ڵ�Ķ���������n+1����ָ�룬�ڶ�����������ʱ��ͨ����������������
// lchildָ����ǰ���ڵ㣬����������������rchildָ�����̽ڵ㣬Ϊ����������
// ���ӽڵ�ָ����������ĺ��ӽڵ㻹��ǰ�����̣�ͨ����Ҫһ����־��ʶ
class ThreadBTNode {
public:
	DataType data;
	ThreadBTNode* lchild, * rchild;
	int ltag, rtag;     // ��־Ϊ0ʱ��ʶʵ�ʺ��ӽڵ㣬��־Ϊ1ʱ��ʶǰ������
};

class ThreadBTree {
public:
	// ͨ���������������������������
	void InThread(ThreadBTNode* root, ThreadBTNode* pre);
	void CreateInThread();

private:
	ThreadBTNode* root;
};



