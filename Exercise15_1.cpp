/*	Practice 1
* 
*	SevenSeg 클래스 구현
*		int n, char seg[15]
*		SevenSeg(int n)		// 초기화 
*		cout << operator overloading
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/*
class SevenSeg {
private:
	int n;
	char seg[15];
	void Init();
	void setNum();

public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& sevenseg);
};

SevenSeg::SevenSeg(int num) :n(num) { 
	Init();
	setNum();
}

void SevenSeg::Init() {
	for (int i = 0; i < 15; i++) {
		if (i % 2 == 0) {
			seg[i] = ' ';
		}
		else {
			if (i == 1 || i == 7 || i == 13) {
				seg[i] = '-';
			}
			else {
				seg[i] = '|';
			}
		}
	}
}

void SevenSeg::setNum() {
	switch (n) {
	case 0:
		seg[7] = ' ';
		break;
	case 1:
		seg[1] = ' '; seg[3] = ' '; seg[7] = ' '; seg[9] = ' '; seg[13] = ' ';
		break;
	case 2:
		seg[3] = ' '; seg[11] = ' ';
		break;
	case 3:
		seg[3] = ' '; seg[9] = ' ';
		break;
	case 4:
		seg[1] = ' '; seg[9] = ' '; seg[13] = ' ';
		break;
	case 5:
		seg[5] = ' '; seg[9] = ' ';
		break;
	case 6:
		seg[5] = ' ';
		break;
	case 7:
		seg[7] = ' '; seg[9] = ' '; seg[13] = ' ';
		break;
	case 8:
		break;
	case 9:
		seg[9] = ' ';
		break;
	}
}

ostream& operator<<(ostream& os, SevenSeg& sevenseg) {
	for (int i = 1; i <= 15; i++) {
		os << sevenseg.seg[i-1];
		if (i % 3 == 0) {
			os << endl;
		}
	}

	return os;
}

int main(void) {
	SevenSeg ss(3);
	cout << ss;

	return 0;
}
*/

class SevenSeg {
	int n;
	char seg[15];
	void Set();

public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
};

SevenSeg::SevenSeg(int n) {
	this->n = n;
	Set();
}

void SevenSeg::Set() {
	seg[0] = ' ';
	seg[2] = ' ';
	seg[4] = ' ';
	seg[6] = ' ';
	seg[8] = ' ';
	seg[10] = ' ';
	seg[12] = ' ';
	seg[14] = ' ';

	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[1] = '-';
	else seg[1] = ' ';

	if (n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[3] = '|';
	else seg[3] = ' ';

	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 || n == 0) seg[5] = '|';
	else seg[5] = ' ';

	if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 9 || n == 8) seg[7] = '-';
	else seg[7] = ' ';

	if (n == 2 || n == 6  || n == 8 || n == 0) seg[9] = '|';
	else seg[9] = ' ';

	if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[11] = '|';
	else seg[11] = ' ';

	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) seg[13] = '-';
	else seg[13] = ' ';
}

ostream& operator<<(ostream& os, SevenSeg& ss) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			os << ss.seg[k++];
		}
		os << endl;
	}

	return os;
}

int main(void) {
	SevenSeg seg1(1);
	SevenSeg seg2(2);
	SevenSeg seg3(3);
	SevenSeg seg4(4);
	SevenSeg seg5(5);
	SevenSeg seg6(6);
	SevenSeg seg7(7);
	SevenSeg seg8(8);
	SevenSeg seg9(9);
	SevenSeg seg0(0);

	cout << seg1 << seg2 << seg3 << seg4 << seg5 << seg6 << seg7 << seg8 << seg9 << seg0;

	return 0;
}