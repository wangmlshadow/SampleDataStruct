#pragma once

#include "normalHead_CPP.h"

#define SqQueueDataType int
#define InitSqQueueData 12345
#define SqQueueAvailableSpace 10

class SqQueue {
public:
	SqQueue();
	~SqQueue();

	// ���еĳ�ʼ��
	void SqQueueInit();

	// ���ٶ���
	void SqQueueDestroy();

	// ���������
	void SqQueueClear();

	// �ж��Ƿ�Ϊ�ն���
	bool SqQueueEmpty();

	// ��ȡ���г��ȣ���������Ԫ�ظ���
	int SqQueueLength();

	// ��ȡ����ͷ��㱣�������ֵ
	bool SqQueueGetHead(SqQueueDataType& value);

	// ��ӣ������µĶ��н��
	bool SqQueueEn(SqQueueDataType value);

	// ���ӣ�ɾ����β���
	bool SqQueueDe();
	bool SqQueueDe(SqQueueDataType& value);    // ���Ӳ�������ֵ

	// �������У��Ӷ�ͷ����β
	void SqQueueTraverse();

private:
	// ��ʶ��ͷ ��β�����ڲ���һ��
	int front;    // frontָ�����һ��Ԫ��λ��ͷԪ��
	int rear;     // rearָ���βԪ��
	bool isEmpty;
	SqQueueDataType* base;    // ָ��������������洢�ռ�
};