/*	5. ���� ����

	���ڿ� s�� ���̰� 4 Ȥ�� 6�̰�, ���ڷθ� �������ִ��� Ȯ�����ִ� �Լ�, solution�� �ϼ��ϼ���. 
	���� ��� s�� "a234"�̸� False�� �����ϰ� "1234"��� True�� �����ϸ� �˴ϴ�.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class String
{
public:
	String();
	~String();
	void setString(const char* str);
	int getLength();
	char* getString() const;
	friend ostream& operator<<(ostream& os, const String& s);

protected:
	char* pstr;
	void Init();
	
};

void String::Init()
{
	pstr = new char[10];
}

String::String()
{
	pstr = NULL;
	Init();
}

String::~String()
{
	if (pstr != NULL) {
		delete[] pstr;
	}
}

void String::setString(const char* str) 
{
	for (int i = 0; i < 10; i++) {
		pstr[i] = str[i];
		if (str[i] == NULL) {
			break;
		}
	}
}

int String::getLength()
{
	for (int i = 0; i < 10; i++) {
		if (pstr[i] == NULL) {
			return i;
		}
	}
}

char* String::getString() const
{
	return pstr;
}

ostream& operator<<(ostream& os, const String& str)
{
	os << str.getString();
	return os;
}

class MyString : public String
{
public:
	MyString();
	~MyString();
	bool isLengthOk();
	bool isSpellOk();
};

MyString::MyString()
{
}

MyString::~MyString()
{
}

bool MyString::isLengthOk()
{
	if (getLength() == 4 || getLength() == 6) {
		return true;
	}
	return false;
}

bool MyString::isSpellOk()
{
	for (int i = 0; i < getLength(); i++) {
		if (pstr[i] < 48 || pstr[i] > 57) {
			return false;
		}
	}
	return true;
}

int main(void) {
	String s;
	s.setString("Hello");

	cout << "���ڿ� : " << s.getString() << endl;
	cout << "����   : " << s.getLength() << endl;

	MyString ms;
	ms.setString("2345");
	
	cout << "���ڿ� : " << ms.getString() << endl;
	cout << "����   : " << s.getLength() << endl;

	if (ms.isLengthOk() && ms.isSpellOk()) {
		cout << true;
	}
	else {
		cout << false;
	}

	return 0;
}