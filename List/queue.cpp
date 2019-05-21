#include "queue.h"

Queue::Queue()
{
	QueueInit();
}

Queue::Queue(int len)
{
	QueueInit();

	for (int i = 0; i < len; i++) {
		QueueDataType temp;
		std::cin >> temp;
		QueueEn(temp);
	}
}

Queue::~Queue()
{
	QueueClear();
	QueueDestroy();
}

void Queue::QueueInit()
{
	QueueNode *node = new(std::nothrow) QueueNode;

	if (!node)
		std::exit(1);

	front = node;
	rear = node;
}

void Queue::QueueDestroy()
{
	delete(front);
}

void Queue::QueueClear()
{
	if (QueueEmpty())    // 已经是空队列
		return;

	QueueNode *cur = front->next;
	QueueNode *next = cur->next;

	while (cur != rear) {    // 依次释放每一个队列元素
		delete(cur);
		cur = next;
		next = next->next;
	}

	delete(rear);
	rear = front;
}

bool Queue::QueueEmpty()
{
	return (front == rear) ? true : false;
}

int Queue::QueueLength()
{
	int cnt = 0;

	QueueNode *cur = front;

	while (cur != rear) {
		cnt++;
		cur = cur->next;
	}

	return cnt;
}

bool Queue::QueueGetHead(QueueDataType &value)
{
	if (QueueEmpty())    // 空队列
		return false;

	value = front->next->data;
}

bool Queue::QueueEn(QueueDataType value)
{
	QueueNode* node = new(std::nothrow) QueueNode(value);

	if (!node)
		std::exit(1);

	rear->next = node;
	rear = node;

	return true;
}

bool Queue::QueueDe()
{
	if (QueueEmpty())
		return false;

	if (QueueLength() == 1) {
		delete(front->next);
		front->next = nullptr;
		rear = front;
	}
	else {
		QueueNode* node = front->next;
		front->next = node->next;
		delete(node);
	}

	return true;
}

bool Queue::QueueDe(QueueDataType &value)
{
	if (QueueEmpty())
		return false;

	if (QueueLength() == 1) {
		value = front->next->data;
		delete(front->next);
		front->next = nullptr;
		rear = front;
	}
	else {
		value = front->next->data;
		QueueNode* node = front->next;
		front->next = node->next;
		delete(node);
	}

	return true;
}

void Queue::QueueTraverse()
{
	QueueNode* cur = front->next;

	while (cur != nullptr) {
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}

