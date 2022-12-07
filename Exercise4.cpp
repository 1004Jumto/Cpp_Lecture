/*	4. 문제 설명

	자연수 n이 매개변수로 주어집니다. 
	n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.
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
	// 숫자 뒤집기
	string tmp = "";

	for (int i = num.length() - 1; i >= 0; i--) {
		tmp = num[i] + tmp;
	}
	
	 return tmp;
}


class Number
{
public:
	Number(int num);
	int getN();		// 숫자
	string getSN();
	string changeNum(int digit);
	void setNum(string n);
	int getNum();

private:
	int number;
	int digit;	// 현재 진법
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
// 10진법을 _digit진법으로 변환하는 함수
string Number::changeNum(int _digit)
{
	string res = "";
	int n;

	// number을 _digit진법으로 변환하여 저장
	for (n = number; n >= _digit; n /= _digit) {
		res = to_string(n % _digit) + res;
	}

	res += to_string(n);
	digit = _digit;
	snumber = res;

	return res;
}

// 10진법으로 바꾸는 함수
int Number::getNum() {
	int res = 0;

	for (int i = snumber.length() - 1, exp = 1; i >= 0; i--, exp *= digit) {
		res += (snumber[i] * exp + '0');
	}
	number = res;
	return res;
}

void Number::setNum(string n)
{
	snumber = n;
}


int solution(int n) {
	int answer = 0;

	Number mynum(45);
	cout << mynum.getN() << endl;
	mynum.changeNum(3);			
	cout << mynum.getN() << endl;
	
	mynum.setNum(Converter::reverse(mynum.getSN()));

	answer = mynum.getNum();
	return answer;
}