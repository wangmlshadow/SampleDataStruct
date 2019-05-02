#pragma once
// ���Ա��˳��ʵ�� 

#define ElemType int          // ElemType��Ϊ���Ա��Լ�֮�����������ڴ洢��Ԫ�ص��������ͣ���ʵ����ʹ��int

// ���Ա��˳��ʵ��
#define LIST_INIT_SIZE 100    // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10      // ���Ա�洢�ռ�ķ�������
typedef struct {
	ElemType *elem;           // �洢�ռ��ַ
	int length;               // ���Ա�ǰ���ó���
	int listsize;             // ��ǰ����Ĵ洢����Ϊ listsize * sizeof(ElemType)
}SqList;

// ��ز���

// ����һ���յ����Ա�
bool InitSqList(SqList *sqlist);

// ��ָ�����Ա���ڵ�ǰ���£�

// ����ָ�����Ա�
void DestorySqList(SqList *sqlist);

// �ж����Ա��Ƿ�Ϊ��
bool SqListEmpty(SqList *sqlist);

// ��ȡָ�����Ա���Ԫ�ظ���
int SqListLength(SqList *sqlist);

// �����Ա���ָ��λ��Ԫ�ش��ڵ�����·��ظ�Ԫ��ֵ
bool GetElem(SqList *sqlist, int i, ElemType *elem);

// ����ָ��Ԫ�������Ա��е�һ�γ��ֵ�λ��
bool LocateElem(SqList *sqlist, ElemType elem, int *pos);

// ��ָ��Ԫ�������Ա��д��ڣ��Ҳ������Ա��еĵ�һ��Ԫ�أ����ظ�ָ��Ԫ�ص�һ�γ���λ�õ�ǰһ��Ԫ��
bool PriorElem(SqList *sqlist, ElemType cur_elem, ElemType *pr_elem);

// ��ָ��Ԫ�������Ա��д��ڣ��Ҳ������Ա��е����һ��Ԫ�أ����ظ�ָ��Ԫ�ص�һ�γ���λ�õĺ�һ��Ԫ��
bool NextElem(SqList *sqlist, ElemType cur_elem, ElemType *next_elem);

// �����Ա�ָ��λ�ò�����Ԫ��
bool SqListInsert(SqList *sqlist, int pos, ElemType elem);

// ɾ�����Ա�ָ��λ��Ԫ�أ������ظ�Ԫ��
bool SqListDelete(SqList *sqlist, int pos, ElemType *elem);

// �������Ա��˴�ʵ�ֽ����ǽ����������׼���������Ҫ����ѡ��������ļ���
void SqListTraverse(SqList *sqlist);

// �������Ա�����
bool SqListExtend(SqList *sqlist);

// �������ź����˳���ϲ�(Ĭ�ϴӴ�С����)
bool MergeSqList(SqList *sq1, SqList *sq2, SqList *mersq);










