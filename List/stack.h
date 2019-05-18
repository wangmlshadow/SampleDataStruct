#pragma once
#include "normalHead_CPP.h"

#define StackDataType int
#define InitStackData 12345

class StackNode {
public:
	StackNode() {
		data = InitStackData;
		next = nullptr;
	}

	StackNode(StackDataType ele) : data(ele), next(nullptr) {

	}

	StackDataType data;
	StackNode *next;
};

// ջ����ʽ�����ȣ�
class Stack {
public:
	Stack();
	Stack(int len);    // ����һ������len��ջԪ�ص�ջ
	~Stack();

	// ջ�ĳ�ʼ��
	void StackInit();

	// ����ջ
	void StackDestroy();

	// ��ջ���
	void StackClear();

	// �ж��Ƿ�Ϊ��ջ
	bool StackEmpty();

	// ��ȡջ���ȣ���ջ��Ԫ�ظ���
	int StackLength();

	// ��ȡջ��Ԫ�ر��������ֵ
	bool StackGetTop(StackDataType &value);

	// ѹջ�������µ�ջ��Ԫ��
	bool StackPush(StackDataType value);
	
	// ��ջ��ɾ��ջ��Ԫ��
	bool StackPop();
	bool StackPop(StackDataType &value);    // ��ջ��������ֵ

	// ����ջ����ջ�׵�ջ��
	void StackTraverse();

private:
	StackNode *top;    // ��β ջ��
	StackNode *bottom; // ��ͷ ջ��
};
