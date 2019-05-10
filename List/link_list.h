#pragma once
// 线性表的链式实现（C++）

#include "normalHead_CPP.h"
#define ElemType int

class LNode {
public:
	LNode(ElemType ele, LNode *pointer) :data(ele), next(pointer) {

	}

	LNode(ElemType ele) {
		data = ele;
		next = nullptr;
	}

	LNode() {
		data = 0;
		next = nullptr;
	}

	ElemType data;
	LNode *next;
};

class LinkList {
public:
	LinkList() {
		head = nullptr;
	}

	// 初始化时，创建一个长度为len的链表
	LinkList(int len) {
		head = nullptr;
		this->LListAddNodes(len);
	}

	~LinkList() {
		this->LListDestory();
	}

	LNode *LListHead() {
		return head;
	}

	// 设置链表头结点
	void LListSetHead(LNode *node) {
		head = node;
	}
	
	// 获取链表长度
	int LListLength();

	// 判断链表是否为空
	bool LListEmpty() {
		return(head == nullptr) ? true : false;
	}

	// 返回链表中第pos个结点
	bool GetNode(int pos, LNode **node);

	// 返回指定data在链表中第一次出现的位置
	bool LocateNode(ElemType ele, LNode **node);

	// 在指定位置插入后一个结点，但若pos为0是表示在链表头插入一个结点
	bool LListInsert(int pos, LNode *node);

	// 删除指定位置结点
	bool LListDelete(int pos);

	// 删除指定位置结点并返回被删除结点的信息
	bool LListDelete(int pos, LNode *node);

	// 遍历线性表
	void LListTraverse();

	// 在链表尾添加cnt个结点
	bool LListAddNodes(int cnt);

	// 销毁链表，释放所有结点资源
	void LListDestory();

private:
	LNode *head;
};

