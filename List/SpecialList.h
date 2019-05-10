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

	// 获取链表长度
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

private:
	LNode *head;    // 循环链表头结点，不储存数据，逻辑上不属于链表的结点，当head->next == head时为空循环链表
};
