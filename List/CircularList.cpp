#include "CircularList.h"

// 循环链表
CircularList::CircularList()
{
	head = new LNode;
	head->next = head;   // 初始化为空链表
}

CircularList::CircularList(int len)
{
	head = new LNode;
	head->next = head; 
	CListAddNodes(len);
}

CircularList::~CircularList()
{
	CListDestory();
	delete head;
}

int CircularList::CListLength()
{
	LNode *temp = head;
	int cnt = 0;

	while (head != temp->next) {
		cnt++;
		temp = temp->next;
	}

	return cnt;
}

bool CircularList::CListEmpty()
{
	return (head == head->next) ? true : false;
}

bool CircularList::GetNode(int pos, LNode **node)
{
	if (pos > CListLength() || pos < 1)
		return false;

	LNode *cur = head;

	for (int i = 1; i <= pos; i++) {
		cur = cur->next;
	}

	*node = cur;

	return true;
}

bool CircularList::LocateNode(ElemType ele, LNode **node)
{
	LNode *curNode = head;

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

bool CircularList::CListInsert(int pos, LNode *node)
{
	// 插入位置错误
	if (pos < 0 || pos > CListLength())
		return false;

	if (pos == 0) {
		node->next = head->next;
		head->next = node;
	}
	else {
		LNode *temp = nullptr;
		this->GetNode(pos, &temp);
		node->next = temp->next;
		temp->next = node;
	}

	return true;
}

bool CircularList::CListDelete(int pos)
{
	if (pos <1 || pos > CListLength())
		return false;

	if (pos == 1) {     // 删除头结点
		LNode *temp = head->next;
		head->next = temp->next;
		delete(temp);
	}
	else {
		LNode *temp_1 = nullptr;
		LNode *temp_2 = nullptr;
		this->GetNode(pos - 1, &temp_1);  // 获取被删除结点的前一个结点
		temp_2 = temp_1->next;
		temp_1->next = temp_2->next;
		delete(temp_2);
	}

	return true;
}

bool CircularList::CListDelete(int pos, LNode *node)
{
	if (pos <1 || pos > this->CListLength())
		return false;

	if (pos == 1) {     // 删除头结点
		LNode *temp = head->next;
		head->next = temp->next;
		node->data = temp->data;
		node->next = temp->next;
		delete(temp);
	}
	else {
		LNode *temp_1 = nullptr;
		LNode *temp_2 = nullptr;
		this->GetNode(pos - 1, &temp_1);  // 获取被删除结点的前一个结点
		temp_2 = temp_1->next;
		temp_1->next = temp_2->next;
		node->data = temp_2->data;
		node->next = temp_2->next;
		delete(temp_2);
	}

	return true;
}

void CircularList::CListTraverse()
{
	LNode *curNode = head->next;

	while (curNode != head) {
		std::cout << curNode->data << std::endl;
		curNode = curNode->next;
	}
}

bool CircularList::CListAddNodes(int cnt)
{
	if (cnt < 0)
		return false;
	else if (cnt == 0)
		return true;

	LNode *curNode = head->next;

	while (curNode->next != head) {
		curNode = curNode->next;
	}

	for (int i = 0; i < cnt; i++) {
		ElemType temp;
		std::cin >> temp;
		LNode *node = new LNode(temp);

		if (!node) {
			return false;
		}

		curNode->next = node;
		curNode = node;
	}

	curNode->next = head;  // 循环链表尾结点指向head

	return true;
}

void CircularList::CListDestory()
{
	LNode *cur = head->next;
	LNode *next = cur->next;

	while (head != cur) {
		delete cur;
		cur = next;
		next = next->next;
	}
}

bool CircularList::CListNodeIsInList(LNode *node)
{
	LNode *cur = head->next;

	while (cur != head) {
		if (cur == node) {
			return true;
		}
		cur = cur->next;
	}

	return false;
}

bool CircularList::CListNodeIsInList(LNode *node, int *pos)
{
	LNode *cur = head->next;
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

bool CircularList::CListPrNode(LNode *node, LNode **p)
{
	// head的前驱结点是最后一个结点
	if (node == head) {
		if (CListEmpty()) {   // 指定结点为头结点，且链表为空
			*p = head;
			return false;
		}

		int len = CListLength();  // 头结点前驱结点为链表最后一个结点
		LNode *last = nullptr;
		GetNode(len, &last);
		*p = last;
		return true;
	}

	// 指定结点不为头结点
	LNode *pr = head;
	LNode *cur = pr->next;

	while (cur != head) {  
		if (cur == node) {
			*p = pr;
			return true;
		}

		pr = cur;
		cur = cur->next;
	}

	return false;
}