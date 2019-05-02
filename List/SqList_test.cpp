#include "linear_list.h"
#include "normalHead.h"

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

	printf("\n");

	SqList sq1, sq2, sq3;
	InitSqList(&sq1);
	InitSqList(&sq2);

	i = 1;

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

/*
Êä³ö£º
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