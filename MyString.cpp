#include <string>
#include <vector>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////
/////////////     기본적인 문자열에 대한 클래스 구현해보기			///////////	
///////////////////////////////////////////////////////////////////////////
class MyString
{
protected:	// private으로 선언한다면 자식클래스가 pstr에 접근할 수 없기 때문에 protected로 바꿈
	char* pstr;
	void initPstr();

public:
	MyString();
	~MyString();
	int getLength();
	void setString(const char* t);
	char* getPstr();
	ostream& operator<<(ostream& os);
	friend ostream& operator<<(ostream& os, const MyString& s);
};

////////////////////////// <summary> //////////////////////////////////////
////////////          MyString을 상속받은 문제를 풀기위한 클래스		///////////
////////////		  solve라는 함수를 추가함						/////////// 
////////////////////////// </summary> /////////////////////////////////////
class FiveString : public MyString {
public:
	FiveString();
	bool solve();
};


////////////////////////// <summary> //////////////////////////////////////
////////////					Main 함수						/////////// 
////////////////////////// </summary> /////////////////////////////////////
int main(void) {
	MyString mystr;
	mystr.setString("test");
	cout << mystr.getLength() << " : " << mystr.getPstr() << endl;
	cout << mystr.getLength() << " : " << mystr << endl;

	FiveString str;
	str.setString("1234");
	cout << str.getLength() << " : " << str << " : " << str.solve() << endl;

	return 0;
}


///////////////////////////// MyString 멤버함수 ////////////////////////////////////////
MyString::MyString()
{
	cout << "I'm MyString()" << endl;
	pstr = NULL;
	initPstr();
}

MyString::~MyString()
{
	cout << "I'm ~MyString()" << endl;
	if (pstr != NULL) {
		delete[] pstr;
	}
}

void MyString::initPstr()

{
	pstr = new char[10];
}

int MyString::getLength()
{
	int i;

	for (i = 0; i < 10; i++) {
		if (pstr[i] == '\0')
			break;
	}

	return i;
}

void MyString::setString(const char* t)
{
	for (int i = 0; i < 10; i++) {
		pstr[i] = t[i];
		if (t[i] == NULL) {
			break;
		}
	}
}

ostream& MyString::operator<<(ostream& os)
{
	os << pstr;
	return os;
}

ostream& operator<<(ostream& os, const MyString& s)
{
	os << s.pstr;
	return os;
}

char* MyString::getPstr()
{
	return this->pstr;
}

///////////////////////////// FiveString 멤버함수 ////////////////////////////////////////
FiveString::FiveString() {
cout << "I'm FiveString()" << endl;
}

bool FiveString::solve()
{
	int len = getLength();

	if (len == 4 || len == 6) {
		for (int i = 0; i < 10 && pstr[i] != '\0'; i++) {
			if (pstr[i] < '0' || pstr[i]>'9') {
				return false;
			}
		}
	}
	else {
		return false;
	}

	return true;
}