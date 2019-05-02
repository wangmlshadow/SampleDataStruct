#pragma once
/*
线性表（linear_list）：
    n个数据元素的有限序列
	每个数据元素由若干数据项（item）组成，常将数据元素称为记录（record），含有大量记录
	的线性表又称为文件。
    
	线性表的顺序实现：
	    用一组地址连续的存储单元依次存储线性表的数据元素。
		再用C语言实现时，需要在线性表初始化时分配一定大小的初始存储空间，但随着初始空间
		被占用，需要考虑每次线性表空间增量的问题，下面实现仅仅是简单的选择一个空间增量，
		在线性表满时重新分配空间。
		 
		顺序表的优缺点：
		    可以随机取表中任一元素，它的存储位置可用简单直观的公式表示：base + (pos-1) * sizeof(ElemType)
			在插入与删除时需移动大量元素

*/
#define ElemType int          // ElemType作为线性表以及之后其他容器内存储的元素的数据类型，本实现中使用int

// 线性表的顺序实现
#define LIST_INIT_SIZE 100    // 线性表存储空间的初始分配量
#define LISTINCREMENT 10      // 线性表存储空间的分配增量
typedef struct {
	ElemType *elem;           // 存储空间基址
	int length;               // 线性表当前所用长度
	int listsize;             // 当前分配的存储容量为 listsize * sizeof(ElemType)
}SqList;

// 相关操作

// 构造一个空的线性表
bool InitSqList(SqList *sqlist);

// 在指定线性表存在的前提下：

// 销毁指点线性表
void DestorySqList(SqList *sqlist);

// 判断线性表是否为空
bool SqListEmpty(SqList *sqlist);

// 获取指定线性表中元素个数
int SqListLength(SqList *sqlist);

// 在线性表中指定位置元素存在的情况下返回该元素值
bool GetElem(SqList *sqlist, int i, ElemType *elem);

// 返回指定元素在线性表中第一次出现的位置
bool LocateElem(SqList *sqlist, ElemType elem, int *pos);

// 若指定元素在线性表中存在，且不是线性表中的第一个元素，返回该指定元素第一次出现位置的前一个元素
bool PriorElem(SqList *sqlist, ElemType cur_elem, ElemType *pr_elem);

// 若指定元素在线性表中存在，且不是线性表中的最后一个元素，返回该指定元素第一次出现位置的后一个元素
bool NextElem(SqList *sqlist, ElemType cur_elem, ElemType *next_elem);

// 在线性表指定位置插入新元素
bool SqListInsert(SqList *sqlist, int pos, ElemType elem);

// 删除线性表指定位置元素，并返回该元素
bool SqListDelete(SqList *sqlist, int pos, ElemType *elem);

// 遍历线性表，此处实现仅仅是将其输出到标准输出，若需要，可选择输出到文件等
void SqListTraverse(SqList *sqlist);

// 增加线性表容量
bool SqListExtend(SqList *sqlist);

// 将两个排好序的顺序表合并(默认从大到小排序)
bool MergeSqList(SqList *sq1, SqList *sq2, SqList *mersq);

/*
测试程序：
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
输出：
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
测试程序：
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
输出：
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









