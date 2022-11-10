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
	bool solve();
};


////////////////////////// <summary> //////////////////////////////////////
////////////          string�� ��ӹ��� Ŭ����						/////////// 
////////////////////////// </summary> /////////////////////////////////////
class StringfromString : public string {
public:
	StringfromString(const char* s);
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

	StringfromString sfs("12ab56");
	cout << sfs.length() << " : " << sfs << " : " << sfs.solve() << endl;
	
	// �ڽ�Ŭ������ �θ�Ŭ������ ô �� �� �ִ�
	// MyString tmp = new FiveString();  (X)
	// FiveString tmp = new MyString();	 (O)
	
	return 0;
}


///////////////////////////// MyString ����Լ� ////////////////////////////////////////
MyString::MyString()
{
	pstr = NULL;
	initPstr();
}

MyString::~MyString()
{
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

///////////////////////////// StringfromString ����Լ� ////////////////////////////////////////
StringfromString::StringfromString(const char* s) : string(s){}	// �̴ϼȶ����� 
											// �θ�Ŭ������ ��������� ȣ��, �θ�Ŭ������ stringŬ������ �����ڰ� ȣ��ȴ�
											// �ڽ�Ŭ������ �ν��Ͻ��� ������ ��, �θ�Ŭ������ �ν��Ͻ��� ���� �����ȴ�
bool StringfromString::solve()
{
	int len = this->length();

	if (len == 4 || len == 6) {
		for (int i = 0; i < 10 && (*this)[i] != '\0'; i++) {
			if ((*this)[i] < '0' || (*this)[i]>'9') {
				return false;
			}
		}
	}
	else {
		return false;
	}

	return true;
}


