#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
	head = new DuLNode;
	head->prior = head;
	head->next = head;
}

DoubleLinkedList::DoubleLinkedList(int len)
{
	head = new DuLNode;
	head->prior = head;
	head->next = head;

	DListAddNodes(len);
}

DoubleLinkedList::~DoubleLinkedList()
{
	DListDestory();
	delete head;
}

bool DoubleLinkedList::DListEmpty()
{
	return (head == head->next) ? true : false;
}


int DoubleLinkedList::DListLength()  
{
	DuLNode *temp = head;
	int cnt = 0;

	while (head != temp->next) {
		cnt++;
		temp = temp->next;
	}

	return cnt;
}


bool DoubleLinkedList::GetNode(int pos, DuLNode **node)
{
	if (pos > DListLength() || pos < 1)
		return false;

	DuLNode *cur = head;

	for (int i = 1; i <= pos; i++) {
		cur = cur->next;
	}

	*node = cur;

	return true;
}


bool DoubleLinkedList::LocateNode(ElemType ele, DuLNode **node)
{
	DuLNode *curNode = head;

	while (head != curNode->next) {
		if (curNode->data == ele) {
			*node = curNode;
			return true;
		}

		curNode = curNode->next;
	}
	*node = nullptr;

	return false;
}


bool DoubleLinkedList::DListInsert(int pos, DuLNode *node)
{
	// 插入位置错误
	if (pos < 0 || pos > DListLength())
		return false;

	if (pos == 0) {
		node->next = head->next;
		node->prior = head;
		head->next = node;
	}
	else {
		DuLNode *temp = nullptr;
		this->GetNode(pos, &temp);
		node->next = temp->next;
		node->prior = temp;
		temp->next = node;
	}

	return true;
}

bool DoubleLinkedList::DListDelete(int pos)
{
	if (pos <1 || pos > DListLength())
		return false;

	// 由于每个结点可以获取其前驱结点信息，相对于单向循环链表的实现，下面实现更为简单
	DuLNode *del;
	GetNode(pos, &del);
	del->prior->next = del->next;
	del->next->prior = del->prior;
	delete(del);

	return true;
}


bool DoubleLinkedList::DListDelete(int pos, DuLNode *node)
{
	if (pos <1 || pos > DListLength())
		return false;

	// 由于每个结点可以获取其前驱结点信息，相对于单向循环链表的实现，下面实现更为简单
	DuLNode *del;
	GetNode(pos, &del);

	del->prior->next = del->next;
	del->next->prior = del->prior;
	// 返回所需数据
	node->data = del->data;
	node->prior = del->prior;
	node->next = del->next;
	delete(del);

	return true;
}


void DoubleLinkedList::DListTraverse()
{
	DuLNode *curNode = head->next;

	while (curNode != head) {
		std::cout << curNode->data << std::endl;
		curNode = curNode->next;
	}
}


bool DoubleLinkedList::DListAddNodes(int cnt)
{
	if (cnt < 0)
		return false;
	else if (cnt == 0)
		return true;

	DuLNode *lastNode = head->prior;  // 获取最后一个结点

	for (int i = 0; i < cnt; i++) {
		ElemType temp;
		std::cin >> temp;
		DuLNode *node = new DuLNode(temp, nullptr, nullptr);

		if (!node) {
			return false;
		}

		lastNode->next = node;
		node->prior = lastNode;
		node->next = head;
		lastNode = node;
	}

	return true;
}


void DoubleLinkedList::DListDestory()
{
	DuLNode *cur = head->next;
	DuLNode *next = cur->next;

	while (head != cur) {
		delete cur;
		cur = next;
		next = next->next;
	}
}

bool DoubleLinkedList::DListNodeIsInList(DuLNode *node)
{
	DuLNode *cur = head->next;

	while (cur != head) {
		if (cur == node) {
			return true;
		}

		cur = cur->next;
	}

	return false;
}

bool DoubleLinkedList::DListNodeIsInList(DuLNode *node, int *pos)
{
	DuLNode *cur = head->next;
	int cnt = 0;

	while (cur != head) {
		cnt++;

		if (cur == node) {
			*pos = cnt;
			return true;
		}

		cur = cur->next;
	}

	return false;
}
