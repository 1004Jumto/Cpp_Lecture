/*	5. 문제 설명

	문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 
	예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.
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

	cout << "문자열 : " << s.getString() << endl;
	cout << "길이   : " << s.getLength() << endl;

	MyString ms;
	ms.setString("2345");
	
	cout << "문자열 : " << ms.getString() << endl;
	cout << "길이   : " << s.getLength() << endl;

	if (ms.isLengthOk() && ms.isSpellOk()) {
		cout << true;
	}
	else {
		cout << false;
	}

	return 0;
}