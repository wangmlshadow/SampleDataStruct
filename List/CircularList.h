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

	// ��ȡ�����ȣ�������ͷ���
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

	// ��ѯĳ���ڵ��Ƿ��ڴ�������
	bool CListNodeIsInList(LNode *node);

	// ��ѯĳ���ڵ��Ƿ��ڴ������У���������λ������
	bool CListNodeIsInList(LNode *node, int *pos);

	// ��ȡָ������ǰһ�����
	bool CListPrNode(LNode *node, LNode **p);

private:
	LNode *head;    
};
/*
ע�⣺
    ������ʵ���У�
	ѭ������ͷ��㣬���������ݣ��ڲ��������Ƿ�Ϊ�ա�����������ʱ�������ý��
	��Ϊһ����־���ã��ýڵ��������������������������壩
	��ʹ������ʱע���ʱ�����Ľ���Ƿ�Ϊhead
	���ڿ��������н���ǰ���ͺ��ʱ��head�ǵ�һ������ǰ�������һ�����ĺ��
*/





