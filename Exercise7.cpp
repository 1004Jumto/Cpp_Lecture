/*	7. ���� ����

	���α׷��ӽ� ������� �������� ��ȣ�� ���� �������� ���� �� ������ ��ȭ��ȣ�� �Ϻθ� �����ϴ�.
	��ȭ��ȣ�� ���ڿ� phone_number�� �־����� ��, ��ȭ��ȣ�� �� 4�ڸ��� ������ ������ ���ڸ� ���� *���� 
	���� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class PhoneNumber
{
public:
	PhoneNumber(string s);
	string masking(int n);

private:
	string number;
};

PhoneNumber::PhoneNumber(string s) :number(s) { ; }

string PhoneNumber::masking(int n)
{
	string tmp = "";
	for (int i = 0; i < number.length(); i++) {
		if (i < n) {
			tmp += "*";
		}
		else {
			tmp += number[i];
		}
	}

	return tmp;
}

int main(void) {
	PhoneNumber number("01073489592");
	cout << number.masking(7);
	return 0;
}

