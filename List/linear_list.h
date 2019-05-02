#pragma once
/*
���Ա�linear_list����
    n������Ԫ�ص���������
	ÿ������Ԫ�������������item����ɣ���������Ԫ�س�Ϊ��¼��record�������д�����¼
	�����Ա��ֳ�Ϊ�ļ���
    
	���Ա��˳��ʵ�֣�
	    ��һ���ַ�����Ĵ洢��Ԫ���δ洢���Ա������Ԫ�ء�
		����C����ʵ��ʱ����Ҫ�����Ա��ʼ��ʱ����һ����С�ĳ�ʼ�洢�ռ䣬�����ų�ʼ�ռ�
		��ռ�ã���Ҫ����ÿ�����Ա�ռ����������⣬����ʵ�ֽ����Ǽ򵥵�ѡ��һ���ռ�������
		�����Ա���ʱ���·���ռ䡣
		 
		˳������ȱ�㣺
		    �������ȡ������һԪ�أ����Ĵ洢λ�ÿ��ü�ֱ�۵Ĺ�ʽ��ʾ��base + (pos-1) * sizeof(ElemType)
			�ڲ�����ɾ��ʱ���ƶ�����Ԫ��

*/
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

/*
���Գ���
int main(void)
{
	SqList sqlist;
	if (InitSqList(&sqlist))
		printf("Init.. \n");

	int i;
	for (i = 0; i < 10; i++) {
		SqListInsert(&sqlist, i + 1, i + 1);
	}

	printf("Length = %d\n", SqListLength(&sqlist));

	if (!SqListEmpty(&sqlist)) {
		printf("Not Empty!\n");
	}

	int ele;
	if (GetElem(&sqlist, 5, &ele))
		printf("ele = %d\n", ele);

	int pos;
	if (LocateElem(&sqlist, ele, &pos))
		printf("pos = %d\n", pos);

	int pre;
	if (PriorElem(&sqlist, 5, &pre))
		printf("pre = %d\n", pre);

	int next;
	if (NextElem(&sqlist, 5, &next))
		printf("next = %d\n", next);

	int del;
	if (SqListDelete(&sqlist, 5, &del))
		printf("del = %d\n", del);

	SqListTraverse(&sqlist);



	getchar();
	return 0;
}

*/

/*
�����
Init..
Length = 10
Not Empty!
ele = 5
pos = 5
pre = 4
next = 6
del = 5
1
2
3
4
6
7
8
9
10
*/

/*
���Գ���
int main(void)
{
	SqList sq1, sq2, sq3;
	InitSqList(&sq1);
	InitSqList(&sq2);

	int i = 1;

	for (; i <= 5; ++i) {
		SqListInsert(&sq1, i, 2 * i - 1);
		SqListInsert(&sq2, i, 2 * i);
	}

	MergeSqList(&sq1, &sq2, &sq3);

	SqListTraverse(&sq1);
	printf("\n");
	SqListTraverse(&sq2);
	printf("\n");
	SqListTraverse(&sq3);

	getchar();
	return 0;
}
*/

/*
�����
1
3
5
7
9

2
4
6
8
10

1
2
3
4
5
6
7
9
8
10
*/









