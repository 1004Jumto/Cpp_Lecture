#include<iostream>

using namespace std;

class PhoneNumber
{
public:
	PhoneNumber(string num);
	~PhoneNumber();
	string masking(int k) const;
	friend ostream& operator<<(ostream& os, const PhoneNumber& p);	
private:
	string number;
};

PhoneNumber::PhoneNumber(string num)
{
	number = num;
}

PhoneNumber::~PhoneNumber()
{
}

string PhoneNumber::masking(int k) const{
	string masked = "";
	for (int i = 0; i < number.length(); i++) {
		if (i < k) {
			masked += "*";
		}
		else {
			masked += number[i];
		}
	}
	return masked;
}

ostream& operator<<(ostream& os, const PhoneNumber& p) {
	string masked = p.masking(7); // const�� ������ ������ p�� ���� ������ ������� �ʴ´�
								  // ���� p�� ���� ���� �ִ� ����Լ��� ȣ���Ϸ��� ����Լ��� const����� �Լ����� ��
	os << masked;
	return os;
}

int main(void) {
	PhoneNumber number("01073489592");
	cout << number.masking(7);
	return 0;
}