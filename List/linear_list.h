#pragma once
// 线性表的顺序实现 

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










