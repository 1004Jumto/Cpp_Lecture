#include<iostream>
using namespace std;

int main(void) {
	string str;
	cout << "Please Enter String : ";
	cin >> str;

	if (str == "zero") {	// JAVA������ ==�����ڴ� �ּҸ� ��������, C++������ ���ڿ��� ������ ���Ѵ�.
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


	// switch���� ����Ѵٸ�?
	/*
	switch (str) {		// �����߻�. switch���� ����� ���� ������ ���� �ʴ´�. 
						// primitive value�� �ޱ� ����
		case "zero":
			cout << 0;
		case "one":
			cout << 1;
	}
	
	*/

	return 0;
}