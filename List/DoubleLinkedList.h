#pragma once
#include "normalHead_CPP.h"
#define ElemType int
#define INITDLNODE 0

// 双向循环链表
// 双向链表的结点
class DuLNode {
public:
	DuLNode() {
		data = INITDLNODE;
		prior = nullptr;
		next = nullptr;
	}

	DuLNode(ElemType ele, DuLNode *p, DuLNode *n) : data(ele), prior(p), next(n) {

	}

	ElemType data;
	DuLNode *prior;    // 指向前驱结点
	DuLNode *next;     // 指向后继结点
};

class DoubleLinkedList {
public:
	DoubleLinkedList();
	DoubleLinkedList(int len);
	~DoubleLinkedList();

	DuLNode *DoubleLinkedListHead() {
		return head;
	}

	DuLNode *CListHead() {
		return head;
	}

	// 获取链表长度
	int DListLength();

	// 判断链表是否为空
	bool DListEmpty();

	// 返回链表中第pos个结点
	bool GetNode(int pos, DuLNode **node);

	// 返回指定data在链表中第一次出现的位置
	bool LocateNode(ElemType ele, DuLNode **node);

	// 在指定位置插入后一个结点，但若pos为0是表示在链表头插入一个结点
	bool DListInsert(int pos, DuLNode *node);

	// 删除指定位置结点
	bool DListDelete(int pos);

	// 删除指定位置结点并返回被删除结点的信息
	bool DListDelete(int pos, DuLNode *node);

	// 遍历线性表
	void DListTraverse();

	// 在链表尾添加cnt个结点
	bool DListAddNodes(int cnt);

	// 销毁链表，释放所有结点资源
	void DListDestory();

	// 查询某个节点是否在此链表中
	bool DListNodeIsInList(DuLNode *node);

	// 查询某个节点是否在此链表中，并返回其位置所在
	bool DListNodeIsInList(DuLNode *node, int *pos);

private:
	DuLNode *head;  
	// head作为双向循环链表的头结点，但其仅仅作为一个标志作用，该节点无数据域（其数据域数据无意义），且仅用于链表操作，并不作为逻辑上的链表节点
	// 逻辑上链表第一个结点为head指向的下一个结点
};

/*
注意：
	在上述实现中：
	链表头结点，不储存数据，在测试链表是否为空、计算链表长度时不包括该结点
	作为一个标志作用，该节点无数据域（其数据域数据无意义）
	在使用链表时注意此时操作的结点是否为head
	但在考虑链表中结点的前驱和后继时，head是第一个结点的前驱，最后一个结点的后继
*/


