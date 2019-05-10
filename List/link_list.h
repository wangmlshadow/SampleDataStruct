#pragma once
// ���Ա����ʽʵ�֣�C++��

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

	// ��ʼ��ʱ������һ������Ϊlen������
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

	// ��������ͷ���
	void LListSetHead(LNode *node) {
		head = node;
	}
	
	// ��ȡ������
	int LListLength();

	// �ж������Ƿ�Ϊ��
	bool LListEmpty() {
		return(head == nullptr) ? true : false;
	}

	// ���������е�pos�����
	bool GetNode(int pos, LNode **node);

	// ����ָ��data�������е�һ�γ��ֵ�λ��
	bool LocateNode(ElemType ele, LNode **node);

	// ��ָ��λ�ò����һ����㣬����posΪ0�Ǳ�ʾ������ͷ����һ�����
	bool LListInsert(int pos, LNode *node);

	// ɾ��ָ��λ�ý��
	bool LListDelete(int pos);

	// ɾ��ָ��λ�ý�㲢���ر�ɾ��������Ϣ
	bool LListDelete(int pos, LNode *node);

	// �������Ա�
	void LListTraverse();

	// ������β���cnt�����
	bool LListAddNodes(int cnt);

	// ���������ͷ����н����Դ
	void LListDestory();

private:
	LNode *head;
};

