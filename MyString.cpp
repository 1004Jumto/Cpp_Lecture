#include <string>
#include <vector>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////
/////////////     �⺻���� ���ڿ��� ���� Ŭ���� �����غ���			///////////	
///////////////////////////////////////////////////////////////////////////
class MyString
{
protected:	// private���� �����Ѵٸ� �ڽ�Ŭ������ pstr�� ������ �� ���� ������ protected�� �ٲ�
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
////////////          MyString�� ��ӹ��� ������ Ǯ������ Ŭ����		///////////
////////////		  solve��� �Լ��� �߰���						/////////// 
////////////////////////// </summary> /////////////////////////////////////
class FiveString : public MyString {
public:
	FiveString();
	bool solve();
};


////////////////////////// <summary> //////////////////////////////////////
////////////					Main �Լ�						/////////// 
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


///////////////////////////// MyString ����Լ� ////////////////////////////////////////
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

///////////////////////////// FiveString ����Լ� ////////////////////////////////////////
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