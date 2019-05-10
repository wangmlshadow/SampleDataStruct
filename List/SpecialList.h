#pragma once
#include "link_list.h"

// ѭ������
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

	// ��ȡ������
	int CListLength();

	// �ж������Ƿ�Ϊ��
	bool CListEmpty();

	// ���������е�pos�����
	bool GetNode(int pos, LNode **node);

	// ����ָ��data�������е�һ�γ��ֵ�λ��
	bool LocateNode(ElemType ele, LNode **node);

	// ��ָ��λ�ò����һ����㣬����posΪ0�Ǳ�ʾ������ͷ����һ�����
	bool CListInsert(int pos, LNode *node);

	// ɾ��ָ��λ�ý��
	bool CListDelete(int pos);

	// ɾ��ָ��λ�ý�㲢���ر�ɾ��������Ϣ
	bool CListDelete(int pos, LNode *node);

	// �������Ա�
	void CListTraverse();

	// ������β���cnt�����
	bool CListAddNodes(int cnt);

	// ���������ͷ����н����Դ
	void CListDestory();

private:
	LNode *head;    // ѭ������ͷ��㣬���������ݣ��߼��ϲ���������Ľ�㣬��head->next == headʱΪ��ѭ������
};
