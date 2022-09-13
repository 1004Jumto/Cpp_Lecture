#include<iostream>
using namespace std;

int main(void) {
	string str;
	cout << "Please Enter String : ";
	cin >> str;

	if (str == "zero") {	// JAVA에서는 ==연산자는 주소를 비교하지만, C++에서는 문자열이 같은지 비교한다.
		cout << 0;
	}
	else if (str == "one") {
		cout << 1;
	}
	else if (str == "two") {
		cout << 2;
	}
	else if (str == "three") {
		cout << 3;
	}
	else if (str == "four") {
		cout << 4;
	}
	else {
		cout << "Nan";
	}


	// switch문을 사용한다면?
	/*
	switch (str) {		// 에러발생. switch문은 사용자 정의 변수를 받지 않는다. 
						// primitive value만 받기 때문
		case "zero":
			cout << 0;
		case "one":
			cout << 1;
	}
	
	*/

	return 0;
}