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

// 栈（链式，长度）
class Stack {
public:
	Stack();
	Stack(int len);    // 创建一个有着len个栈元素的栈
	~Stack();

	// 栈的初始化
	void StackInit();

	// 销毁栈
	void StackDestroy();

	// 将栈清空
	void StackClear();

	// 判断是否为空栈
	bool StackEmpty();

	// 获取栈长度，即栈中元素个数
	int StackLength();

	// 获取栈顶元素保存的数据值
	bool StackGetTop(StackDataType &value);

	// 压栈，插入新的栈顶元素
	bool StackPush(StackDataType value);
	
	// 出栈，删除栈顶元素
	bool StackPop();
	bool StackPop(StackDataType &value);    // 出栈并返回其值

	// 遍历栈，从栈底到栈顶
	void StackTraverse();

private:
	StackNode *top;    // 表尾 栈顶
	StackNode *bottom; // 表头 栈底
};
