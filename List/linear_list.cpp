#include "linear_list.h"
#include "normalHead.h"

bool InitSqList(SqList *sqlist)
{
	sqlist->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if (!sqlist->elem)
		return false;    // malloc失败

	sqlist->length = 0;
	sqlist->listsize = LIST_INIT_SIZE;    // 线性表初始长度

	return true;
}

void DestorySqList(SqList *sqlist)
{
	free(sqlist->elem);
	sqlist->elem = NULL;
	sqlist->length = 0;
	sqlist->listsize = 0;
	// 此处释放分配给该线性表的存储空间，并将该线性表的length、listsize清零
}

bool SqListEmpty(SqList *sqlist)
{
	if (sqlist->length)
		return false;

	return true;
}

int SqListLength(SqList *sqlist)
{
	return sqlist->length;
}

bool GetElem(SqList *sqlist, int pos, ElemType *elem)
{
	if (pos > sqlist->length || pos < 1)
		return false;
	
	*elem = sqlist->elem[pos - 1];
	
	return true;
}

bool LocateElem(SqList *sqlist, ElemType elem, int *pos)
{
	int i = 0;
	for (; i < sqlist->length; i++) {
		if (sqlist->elem[i] == elem) {
			*pos = i + 1;          // 返回elem第一次出现的位置 i+1
			return true;
		}
	}
	
	// 线性表中不存在元素elem
	*pos = 0;
	return false;
}

bool PriorElem(SqList *sqlist, ElemType cur_elem, ElemType *pr_elem)
{
	int i = 0;

	for (; i < sqlist->length; i++) {
		if (i != 0 && sqlist->elem[i] == cur_elem) {
			*pr_elem = sqlist->elem[i - 1];
			return true;
		}
	}

	return false;
}

bool NextElem(SqList *sqlist, ElemType cur_elem, ElemType *next_elem)
{
	int i = 0;

	for (; i < sqlist->length - 1; i++) {
		if (cur_elem == sqlist->elem[i]) {
			*next_elem = sqlist->elem[i + 1];
			return true;
		}
	}

	return false;
}

bool SqListInsert(SqList *sqlist, int pos, ElemType elem)
{
	// 若在线性表已满的情况下插入元素，需要先对线性表做扩从操作
	if (pos < 1 || pos > sqlist->length + 1)
		return false;    // 插入位置非法

	if (sqlist->length == sqlist->listsize) {
		if (!SqListExtend(sqlist)) {
			return false;    // realloc出错
		}
	}

	int i = sqlist->length;
	for (; i >= pos; i--) {
		sqlist->elem[i] = sqlist->elem[i - 1];
	}

	sqlist->elem[pos - 1] = elem;
	sqlist->length++;

	return true;
}

bool SqListDelete(SqList *sqlist, int pos, ElemType *elem)
{
	if (pos < 1 || pos > sqlist->length) {
		return false;    // 删除位置出错 
	}

	int i = pos - 1;
	*elem = sqlist->elem[i];
	for (; i < sqlist->length - 1; i++) {
		sqlist->elem[i] = sqlist->elem[i + 1];
	}

	sqlist->length--;

	return true;
}

void SqListTraverse(SqList *sqlist)
{
	int i;

	for (i = 0; i < sqlist->length; i++) {
		printf("%d\n", sqlist->elem[i]);
	}
}

bool SqListExtend(SqList *sqlist)
{
	ElemType *newbase = (ElemType *)realloc(sqlist->elem, (sqlist->listsize + LISTINCREMENT) * sizeof(ElemType));

	if (!newbase)
		return false;

	sqlist->elem = newbase;
	sqlist->listsize += LISTINCREMENT;

	return true;
}

bool MergeSqList(SqList *sq1, SqList *sq2, SqList *mersq)
{
	mersq->elem = (ElemType *)malloc((sq1->length + sq2->length) * sizeof(ElemType));

	if (!mersq->elem)
		return false;    // malloc失败

	mersq->length = 0;
	mersq->listsize = sq1->length + sq2->length;

	int pos = 1, j = 0, k = 0;

	while (j < sq1->length - 1 && k < sq2->length) {
		if (sq1->elem[j] <= sq2->elem[k]) {
			if (!SqListInsert(mersq, pos++, sq1->elem[j]))
				return false;    // 插入错误

			++j;
		}
		else {
			if (!SqListInsert(mersq, pos++, sq2->elem[k]))
				return false;    // 插入错误

			++k;
		}
	}

	// 插入剩余元素
	while (j < sq1->length) {
		if (!SqListInsert(mersq, pos++, sq1->elem[j]))
			return false;    // 插入错误

		++j;
	}

	while (k < sq2->length) {
		if (!SqListInsert(mersq, pos++, sq2->elem[k]))
			return false;    // 插入错误

		++k;
	}

	return true;
}











































