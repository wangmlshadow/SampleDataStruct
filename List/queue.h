#pragma once

#include "normalHead_CPP.h"

#define QueueDataType int
#define InitQueueData 12345

class QueueNode {
public:
	QueueNode() {
		data = InitQueueData;
		next = nullptr;
	}

	QueueNode(QueueDataType ele) : data(ele), next(nullptr) {

	}

	QueueDataType data;
	QueueNode *next;
};

class Queue {
public:
	Queue();
	Queue(int len);    // 创建一个有len个结点的队列
	~Queue();

	// 队列的初始化
	void QueueInit();

	// 销毁队列
	void QueueDestroy();

	// 将队列清空
	void QueueClear();

	// 判断是否为空队列
	bool QueueEmpty();

	// 获取队列长度，即队列中元素个数
	int QueueLength();

	// 获取队列头结点保存的数据值
	bool QueueGetHead(QueueDataType &value);

	// 入队，插入新的队列结点
	bool QueueEn(QueueDataType value);

	// 出队，删除队尾结点
	bool QueueDe();
	bool QueueDe(QueueDataType &value);    // 出队并返回其值

	// 遍历队列，从队头到队尾
	void QueueTraverse();

private:
	QueueNode *front;    // 队头
	QueueNode *rear;     // 队尾
};