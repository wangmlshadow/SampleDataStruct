#pragma once
#include "normalHead_CPP.h"

/*
����ʵ��һ�����׼����stringӵ�����ƹ��ܵ��ַ����ṹ

����ʵ�������õ�pos���ַ�����ĳ���ַ���λ�ö��Ǵ�0��ʼ�ģ�
*/

#define InitAvailableLength 50

class String {
public:
	// ����ʵ��
	String();
	String(std::string& str)
	~String();

	// �ַ����ĳ�ʼ��
	void Init();
	// ����ַ�������
	void Clear();
	// �����ַ���
	void Destory();
	// ���ַ���ת��
	void Reserve();

	// ��ȡ�ַ�������
	int Length();
	// �ж��ַ����Ƿ�Ϊ��
	bool Empty();
	// �ж��ַ����Ƿ���ָ���ִ���ͷ
	bool StartsWith(String& str);
	bool StartsWith(std::string& str);
	bool StartsWith(char& str);
	// �ж��ַ����Ƿ���ָ���ִ���β
	bool EndsWith(String& str);
	bool EndsWith(std::string& str);
	bool EndsWith(char& str);
	
	// ���ָ����Χ�ڵ��ַ�
	bool Erase(int start, int end);
	// ���ַ�����β�����һ���ַ�     
	void PushBack(char ch);
	// ���ַ�����β�����ַ�ȥ��
	bool PopBack();
	// ���ַ�����β����ƶ��ַ���
	void Append(String& str);
	//void Append(std::string& str);

	// ��ָ���ַ����Ƚϣ�����ĸ��˳�򣬸ñ��ƶ��ַ����󷵻�1��С����-1.��ȷ���0
	int Compare(String& str);
	int Compare(std::string& str);
	
	// �ִ��滻
	String* Replace(int start, int end, String& str);  // ���滻�Ӵ�����ʼλ�������λ��
	String* Replace(int pos, int cnt, String& str);    // ���滻�Ӵ�����ʼλ�����Ӵ�����

	// ����һ��ָ���Ӵ�
	String* SubString(int start, int cnt);

	// ����һ���Ӵ�
	int Copy(String* str, int pos, int cnt);   // ���ر����Ƶ��ַ�����str��һ���մ�

	// �ı��ַ�����С
	void Resize(int size);  // ����ضϣ����򲹿��ַ�

	// �������ַ���������
	void Swap(String& str);

	// Ѱ���Ӵ���һ�γ��ֵ�λ��
	bool Find(String& substr, int& pos);

	// Ѱ���Ӵ����һ�γ��ֵ�λ��
	bool Rfind(String& substr, int& pos);


    // ���������
	String* operator+(String& str);
	bool operator==(String& str);
	bool operator!=(String& str);



	// ������չ
	// �������(��׼������ļ�)
	void Traverse();

	// ����ת��
	bool Str2int();
	bool Str2double();



private:
	char* base;
	int len;
	int maxlen;    // ��ǰ���ô洢�ռ䳤��
};


/*
˵����
    �˴�ʵ�ֲ�û���ṩ���ַ�����ͷ����ӻ�ɾ���ַ�����Ϊ��������Ҫ�������ַ���ǰ�ƣ�����̫��

*/