#pragma once
#include "link_list.h"

// 循环链表
class CircularList {
public:
	CircularList();
	CircularList(int len);
	~CircularList();

	LNode *CircularListHead() {
		return head;
	}

	LNode *CListHead() {
		return head;
	}

	// 获取链表长度，不包括头结点
	int CListLength();

	// 判断链表是否为空
	bool CListEmpty();

	// 返回链表中第pos个结点
	bool GetNode(int pos, LNode **node);

	// 返回指定data在链表中第一次出现的位置
	bool LocateNode(ElemType ele, LNode **node);

	// 在指定位置插入后一个结点，但若pos为0是表示在链表头插入一个结点
	bool CListInsert(int pos, LNode *node);

	// 删除指定位置结点
	bool CListDelete(int pos);

	// 删除指定位置结点并返回被删除结点的信息
	bool CListDelete(int pos, LNode *node);

	// 遍历线性表
	void CListTraverse();

	// 在链表尾添加cnt个结点
	bool CListAddNodes(int cnt);

	// 销毁链表，释放所有结点资源
	void CListDestory();

	// 查询某个节点是否在此链表中
	bool CListNodeIsInList(LNode *node);

	// 查询某个节点是否在此链表中，并返回其位置所在
	bool CListNodeIsInList(LNode *node, int *pos);

	// 获取指定结点的前一个结点
	bool CListPrNode(LNode *node, LNode **p);

private:
	LNode *head;    
};
/*
注意：
    在上述实现中：
	循环链表头结点，不储存数据，在测试链表是否为空、计算链表长度时不包括该结点
	作为一个标志作用，该节点无数据域（其数据域数据无意义）
	在使用链表时注意此时操作的结点是否为head
	但在考虑链表中结点的前驱和后继时，head是第一个结点的前驱，最后一个结点的后继
*/





