#pragma once

#include "normalHead_CPP.h"

#define SqQueueDataType int
#define InitSqQueueData 12345
#define SqQueueAvailableSpace 10

class SqQueue {
public:
	SqQueue();
	~SqQueue();

	// 队列的初始化
	void SqQueueInit();

	// 销毁队列
	void SqQueueDestroy();

	// 将队列清空
	void SqQueueClear();

	// 判断是否为空队列
	bool SqQueueEmpty();

	// 获取队列长度，即队列中元素个数
	int SqQueueLength();

	// 获取队列头结点保存的数据值
	bool SqQueueGetHead(SqQueueDataType& value);

	// 入队，插入新的队列结点
	bool SqQueueEn(SqQueueDataType value);

	// 出队，删除队尾结点
	bool SqQueueDe();
	bool SqQueueDe(SqQueueDataType& value);    // 出队并返回其值

	// 遍历队列，从队头到队尾
	void SqQueueTraverse();

private:
	// 标识对头 队尾，由于采用一组
	int front;    // front指向的下一个元素位对头元素
	int rear;     // rear指向队尾元素
	bool isEmpty;
	SqQueueDataType* base;    // 指向所分配的连续存储空间
};