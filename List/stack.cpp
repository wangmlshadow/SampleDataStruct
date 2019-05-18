#include "stack.h"

Stack::Stack()
{
	StackInit();
}

Stack::Stack(int len)
{
	StackInit();
	StackDataType tempdata = InitStackData;

	for (int i = 0; i < len; i++) {
		std::cin >> tempdata;
		StackPush(tempdata);
	}
}

Stack::~Stack()
{
	StackClear();
	StackDestroy();
}

void Stack::StackInit()
{
	StackNode *temp = new(std::nothrow) StackNode;

	if (temp == 0) {
		std::exit(1);
	}

	top = temp;
	bottom = temp;
}

void Stack::StackDestroy()
{
	delete(bottom);
}

void Stack::StackClear()
{
	if (bottom == top) {    // 已经是空栈
		return;
	}

	StackNode *cur = bottom->next;
	StackNode *next = cur->next;

	while (cur != nullptr) {    // 释放栈元素结点空间
		delete(cur);

		if (next == nullptr) {
			break;
		}

		cur = next;
		next = next->next;
	}

	top = bottom;
}

bool Stack::StackEmpty()
{
	return (bottom == top) ? true : false;
}

int Stack::StackLength()
{
	int cnt = 0;
	StackNode *cur = bottom;

	while (cur != top) {
		cnt++;
		cur = cur->next;
	}

	return cnt;
}

bool Stack::StackGetTop(StackDataType &value)
{
	if (bottom == top)
		return false;    // 空栈无栈顶元素

	value = top->data;

	return true;
}

bool Stack::StackPush(StackDataType value)
{
	StackNode *temp = new(std::nothrow) StackNode(value);

	if (temp == 0) {
		return false;
	}

	top->next = temp;
	top = temp;

	return true;
}

bool Stack::StackPop()
{
	if (top == bottom)    // 空栈无栈顶元素，无法pop
		return false;

	StackNode *prior = bottom;

	while (prior->next != top) {    //  找到栈顶第二个元素
		prior = prior->next;
	}

	delete(top);
	top = prior;
	top->next = nullptr;  // 注意此处

	return true;
}

bool Stack::StackPop(StackDataType &value)
{
	if (top == bottom)    // 空栈无栈顶元素，无法pop
		return false;

	StackNode *prior = bottom;

	while (prior->next != top) {    //  找到栈顶第二个元素
		prior = prior->next;
	}

	value = top->data;
	delete(top);
	top = prior;
	top->next = nullptr;  // 注意此处

	return true;
}

void Stack::StackTraverse()
{
	StackNode *cur = bottom->next;

	while (cur != top) {    
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}

	std::cout << top->data << std::endl;
}