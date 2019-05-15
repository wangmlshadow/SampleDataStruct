#pragma once
#include "normalHead_CPP.h"
#define ElemType int
#define INITDLNODE 0

// ˫��ѭ������
// ˫������Ľ��
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
	DuLNode *prior;    // ָ��ǰ�����
	DuLNode *next;     // ָ���̽��
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

	// ��ȡ������
	int DListLength();

	// �ж������Ƿ�Ϊ��
	bool DListEmpty();

	// ���������е�pos�����
	bool GetNode(int pos, DuLNode **node);

	// ����ָ��data�������е�һ�γ��ֵ�λ��
	bool LocateNode(ElemType ele, DuLNode **node);

	// ��ָ��λ�ò����һ����㣬����posΪ0�Ǳ�ʾ������ͷ����һ�����
	bool DListInsert(int pos, DuLNode *node);

	// ɾ��ָ��λ�ý��
	bool DListDelete(int pos);

	// ɾ��ָ��λ�ý�㲢���ر�ɾ��������Ϣ
	bool DListDelete(int pos, DuLNode *node);

	// �������Ա�
	void DListTraverse();

	// ������β���cnt�����
	bool DListAddNodes(int cnt);

	// ���������ͷ����н����Դ
	void DListDestory();

	// ��ѯĳ���ڵ��Ƿ��ڴ�������
	bool DListNodeIsInList(DuLNode *node);

	// ��ѯĳ���ڵ��Ƿ��ڴ������У���������λ������
	bool DListNodeIsInList(DuLNode *node, int *pos);

private:
	DuLNode *head;  
	// head��Ϊ˫��ѭ�������ͷ��㣬���������Ϊһ����־���ã��ýڵ��������������������������壩���ҽ��������������������Ϊ�߼��ϵ�����ڵ�
	// �߼��������һ�����Ϊheadָ�����һ�����
};

/*
ע�⣺
	������ʵ���У�
	����ͷ��㣬���������ݣ��ڲ��������Ƿ�Ϊ�ա�����������ʱ�������ý��
	��Ϊһ����־���ã��ýڵ��������������������������壩
	��ʹ������ʱע���ʱ�����Ľ���Ƿ�Ϊhead
	���ڿ��������н���ǰ���ͺ��ʱ��head�ǵ�һ������ǰ�������һ�����ĺ��
*/


