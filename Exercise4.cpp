/*	4. ���� ����

	�ڿ��� n�� �Ű������� �־����ϴ�. 
	n�� 3���� �󿡼� �յڷ� ������ ��, �̸� �ٽ� 10�������� ǥ���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Converter
{
public:
	Converter();
	static string reverse(string num);
};

Converter::Converter() { ; }

string Converter::reverse(string num)
{
	// ���� ������ 1200->0021
	string tmp = "";

	for (int i = num.length() - 1; i >= 0; i--) {
		tmp += num[i];
	}
	
	 return tmp;
}


class Number
{
public:
	Number(int num);
	int getN();		// ����
	string getSN();
	string changeNum(int digit);
	void setNum(string n);
	int getNum();

private:
	int number;
	int digit;	// ���� ����
	string snumber;
};

Number::Number(int num) :number(num), digit(10) { ; }

int Number::getN()
{
	return number;
}

string Number::getSN() {
	return snumber;
}
// 10������ _digit�������� ��ȯ�ϴ� �Լ�
string Number::changeNum(int _digit)
{
	string res = "";
	int n;

	// number�� _digit�������� ��ȯ�Ͽ� ����
	for (n = number; n >= _digit; n /= _digit) {
		res = to_string(n % _digit) + res;
	}

	res = to_string(n) + res;
	digit = _digit;
	snumber = res;

	return res;
}

// 10�������� �ٲٴ� �Լ�
int Number::getNum() {
	int res = 0;

	for (int i = snumber.length() - 1, exp = 1; i >= 0; i--, exp *= digit) {
		res += (snumber[i] - '0') * exp;
	}
	number = res;

	return res;
}

void Number::setNum(string n)
{
	snumber = n;
}


int main(int n) {
	int answer = 0;

	Number mynum(45);
	cout << mynum.getN() << endl;
	mynum.changeNum(3);			
	cout << mynum.getSN() << endl;
	
	mynum.setNum(Converter::reverse(mynum.getSN()));
	cout << mynum.getSN() << endl;

	answer = mynum.getNum();
	cout << answer;

	return answer;
}