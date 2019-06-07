#include "SqQueue.h"

SqQueue::SqQueue()
{
	SqQueueInit();
}

SqQueue::~SqQueue()
{
	SqQueueDestroy();
}

void SqQueue::SqQueueInit()
{
	base = new(std::nothrow) SqQueueDataType[SqQueueAvailableSpace];
	
	if (!base)
		std::exit(1);

	front = 0;
	rear = 0;
	isEmpty = true;
}

void SqQueue::SqQueueDestroy()
{
	delete []base;
}

void SqQueue::SqQueueClear()
{
	// ��Ϊ�ն���
	front = 1;
	rear = 1;
}
bool SqQueue::SqQueueEmpty()
{
	return isEmpty;
}

int SqQueue::SqQueueLength()
{
	return (rear - front + SqQueueAvailableSpace) % SqQueueAvailableSpace;
}

bool SqQueue::SqQueueGetHead(SqQueueDataType& value)
{
	if (isEmpty)
		return false;
	else {
		value = base[front + 1];
		return true;
	}
}

bool SqQueue::SqQueueEn(SqQueueDataType value)
{
	if (!isEmpty && rear == front)
		return false;    // ���п��ÿռ�����

	rear = (rear + 1) % SqQueueAvailableSpace;
	base[rear] = value;
	isEmpty = false;
}

bool SqQueue::SqQueueDe()
{
	if (isEmpty)
		return false;

	front = (front + 1) % SqQueueAvailableSpace;

	if (front == rear)
		isEmpty = true;  // ���н���һ��Ԫ�س��Ӻ��Ϊ�ն���

	return true;
}

bool SqQueue::SqQueueDe(SqQueueDataType& value)
{
	if (isEmpty)
		return false;

	front = (front + 1) % SqQueueAvailableSpace;
	value = base[front];

	if (front == rear)
		isEmpty = true;  // ���н���һ��Ԫ�س��Ӻ��Ϊ�ն���

	return true;
}

void SqQueue::SqQueueTraverse()
{
	if (isEmpty)
		return;

	int f = (front + 1) % SqQueueAvailableSpace;

	while (f != rear) {
		std::cout << base[f] << std::endl;
		f = (f + 1) % SqQueueAvailableSpace;
	}
	std::cout << base[f] << std::endl;
}