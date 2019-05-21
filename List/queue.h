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
	Queue(int len);    // ����һ����len�����Ķ���
	~Queue();

	// ���еĳ�ʼ��
	void QueueInit();

	// ���ٶ���
	void QueueDestroy();

	// ���������
	void QueueClear();

	// �ж��Ƿ�Ϊ�ն���
	bool QueueEmpty();

	// ��ȡ���г��ȣ���������Ԫ�ظ���
	int QueueLength();

	// ��ȡ����ͷ��㱣�������ֵ
	bool QueueGetHead(QueueDataType &value);

	// ��ӣ������µĶ��н��
	bool QueueEn(QueueDataType value);

	// ���ӣ�ɾ����β���
	bool QueueDe();
	bool QueueDe(QueueDataType &value);    // ���Ӳ�������ֵ

	// �������У��Ӷ�ͷ����β
	void QueueTraverse();

private:
	QueueNode *front;    // ��ͷ
	QueueNode *rear;     // ��β
};