#pragma once
#include "link_list.h"

int LinkList::LListLength()
{
	int cnt = 0;
	LNode *node = this->LListHead();

	while (node != nullptr) {
		cnt++;
		node = node->next;
	}
	return cnt;
}

bool LinkList::GetNode(int pos, LNode **node)
{
	if (pos > this->LListLength() || pos < 1)
		return false;

	LNode *cur = this->LListHead();

	for (int i = 2; i <= pos; i++) {
		cur = cur->next;
	}

	*node = cur;

	return true;
}

bool LinkList::LocateNode(ElemType ele, LNode *node)
{
	LNode *curNode = this->LListHead();
	while (curNode->next != nullptr) {
		curNode = curNode->next;

		if (curNode->data == ele) {
			node = curNode;
			return true;
		}
	}

	return false;
}

bool LinkList::LListInsert(int pos, LNode *node)
{
	// ����λ�ô���
	if (pos < 0 || pos > this->LListLength())
		return false;
    
	if (pos == 0) {
		node->next = this->LListHead();
		this->LListSetHead(node);
	}
	else {
		LNode *temp = nullptr;
		this->GetNode(pos, &temp);
		node->next = temp->next;
		temp->next = node;
	}

	return true;
}

bool LinkList::LListDelete(int pos)
{
	if (pos <1 || pos > this->LListLength())
		return false;

	if (pos == 1) {     // ɾ��ͷ���
		LNode *temp = this->LListHead();
		this->LListSetHead(temp->next);
		delete(temp);
	}
	else {
		LNode *temp_1 = nullptr; 
		LNode *temp_2 = nullptr;
		this->GetNode(pos - 1, &temp_1);  // ��ȡ��ɾ������ǰһ�����
		temp_2 = temp_1->next;
		temp_1->next = temp_2->next;
		delete(temp_2);
	}

	return true;
}

// ɾ����������ͷŽ����ռ�õĿռ䣬�����صĽ����Ǳ�ɾ��������Ϣ
bool LinkList::LListDelete(int pos, LNode *node)
{
	if (pos <1 || pos > this->LListLength())
		return false;

	if (pos == 1) {     
		LNode *temp = this->LListHead();
		this->LListSetHead(temp->next);
		node->data = temp->data;
		node->next = temp->next;
		delete(temp);
	}
	else {
		LNode *temp_1 = nullptr;
		LNode *temp_2 = nullptr;
		this->GetNode(pos - 1, &temp_1);
		temp_2 = temp_1->next;
		temp_1->next = temp_2->next;
		node->data = temp_2->data;
		node->next = temp_2->next;
		delete(temp_2);
	}

	return true;
}

void LinkList::LListTraverse()
{
	LNode *curNode = this->LListHead();

	while (curNode != nullptr) {
		std::cout << curNode->data << std::endl;
		curNode = curNode->next;		
	}
}

bool LinkList::LListAddNodes(int cnt)
{
	//std::cout << cnt << std::endl;

	if (cnt < 0)
		return false;
	else if (cnt == 0)
		return true;

	LNode *curNode = this->LListHead();

	if (curNode != nullptr) {
		// �ҵ�����β���
		while (curNode->next != nullptr) {
			curNode = curNode->next;
		}

		for (int i = 0; i < cnt; i++) {
			int temp;
			std::cin >> temp;
			LNode *node = new LNode(temp);

			if (!node) {
				return false;
			}

			//node->next = nullptr;
			//node->data = i;

			curNode->next = node;
			curNode = node;
		}
	}
	else {
		int temp;
		std::cin >> temp;
		LNode *node = new LNode(temp);
		LListSetHead(node);
		curNode = node;

		for (int i = 0; i < cnt - 1; i++) {
			std::cin >> temp;
			node = new LNode(temp);

			if (!node) {
				//std::cout << "new Error!" << std::endl;
				return false;
			}

			curNode->next = node;
			curNode = node;
		}
	}

	return true;
}

void LinkList::LListDestory()
{
	//std::cout << "Destory!" << endl;
	LNode *cur = this->LListHead();

	if (!cur)
		return;

	LNode *next = cur->next;

	while (cur) {
		delete cur;
		
		if (next) {
			cur = next;
			next = next->next;
		}
		else
			break;
	}
}
