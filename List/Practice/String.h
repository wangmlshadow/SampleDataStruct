#pragma once
#include "normalHead_CPP.h"

/*
尝试实现一个与标准库中string拥有类似功能的字符串结构

下面实现中所用的pos（字符串中某个字符的位置都是从0开始的）
*/

#define InitAvailableLength 50

class String {
public:
	// 基本实现
	String();
	String(std::string& str)
	~String();

	// 字符串的初始化
	void Init();
	// 清空字符串内容
	void Clear();
	// 销毁字符串
	void Destory();
	// 将字符串转置
	void Reserve();

	// 获取字符串长度
	int Length();
	// 判断字符串是否为空
	bool Empty();
	// 判断字符串是否以指定字串开头
	bool StartsWith(String& str);
	bool StartsWith(std::string& str);
	bool StartsWith(char& str);
	// 判断字符串是否以指定字串结尾
	bool EndsWith(String& str);
	bool EndsWith(std::string& str);
	bool EndsWith(char& str);
	
	// 清除指定范围内的字符
	bool Erase(int start, int end);
	// 在字符串结尾处添加一个字符     
	void PushBack(char ch);
	// 将字符串结尾处的字符去除
	bool PopBack();
	// 在字符串结尾添加制定字符串
	void Append(String& str);
	//void Append(std::string& str);

	// 与指定字符串比较，按字母表顺序，该比制定字符串大返回1，小返回-1.相等返回0
	int Compare(String& str);
	int Compare(std::string& str);
	
	// 字串替换
	String* Replace(int start, int end, String& str);  // 被替换子串的起始位置与结束位置
	String* Replace(int pos, int cnt, String& str);    // 被替换子串的起始位置与子串长度

	// 返回一个指定子串
	String* SubString(int start, int cnt);

	// 复制一个子串
	int Copy(String* str, int pos, int cnt);   // 返回被复制的字符数，str是一个空串

	// 改变字符串大小
	void Resize(int size);  // 长则截断，短则补空字符

	// 交换两字符串的内容
	void Swap(String& str);

	// 寻找子串第一次出现的位置
	bool Find(String& substr, int& pos);

	// 寻找子串最后一次出现的位置
	bool Rfind(String& substr, int& pos);


    // 运算符重载
	String* operator+(String& str);
	bool operator==(String& str);
	bool operator!=(String& str);



	// 功能扩展
	// 遍历输出(标准输出，文件)
	void Traverse();

	// 类型转换
	bool Str2int();
	bool Str2double();



private:
	char* base;
	int len;
	int maxlen;    // 当前可用存储空间长度
};


/*
说明：
    此处实现并没有提供在字符串开头处添加或删除字符，因为这样做需要将整个字符串前移，代价太大

*/