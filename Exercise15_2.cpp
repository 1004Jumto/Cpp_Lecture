#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class SevenSegs;
class SevenSeg {
private:
	int n;
	char seg[15];
	void Init();
	void setNum();

public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& sevenseg);
	friend ostream& operator<<(ostream& os, SevenSegs& sevenseg);
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
		os << sevenseg.seg[i - 1];
		if (i % 3 == 0) {
			os << endl;
		}
	}

	return os;
}

class SevenSegs {
private:
	int n;
	vector<SevenSeg> segs;
	void Init();

public:
	SevenSegs(int n);
	friend ostream& operator<<(ostream& os, SevenSegs& sevenseg);
};

SevenSegs::SevenSegs(int n)
{
	this->n = n;
	Init();
}

void SevenSegs::Init() {
	while (n > 0) {
		int tmp = n % 10;
		segs.push_back(SevenSeg(tmp));
		n /= 10;
	}
}
/*
	 - 
	| |
	 -
	| |
	 -
*/

ostream& operator<<(ostream& os, SevenSegs& sevensegs) {
	int l = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = sevensegs.segs.size() - 1; i >= 0; i--) {
			for (int k = 0; k < 3; k++) {
				os << sevensegs.segs[i].seg[l + k];
			}
		}
		l += 3;
		os << endl;
	}
	

	return os;
}

//int main(void) {
//	SevenSegs segs(1234567890);
//	cout << segs;
//
//	return 0;
//
//}


/*
class SevenSegs;

class SevenSeg {
	int n;
	char seg[15];
	void Set();

public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
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

	if (n == 2 || n == 6 || n == 8 || n == 0) seg[9] = '|';
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


class SevenSegs {
private:
	int n;
	vector<SevenSeg> segs;
	void Set();

public:
	SevenSegs(int n);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
};

SevenSegs::SevenSegs(int n)
{
	this->n = n;
	Set();
}

void SevenSegs::Set()
{
	int k = n; 
	for (int k = n; k > 0; k /= 10) {
		SevenSeg temp(k % 10);
		segs.push_back(temp);
	}
}

ostream& operator<<(ostream& os, SevenSegs& ss)
{
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = ss.segs.size() - 1; j >= 0; j--) {
			for (int l = 0; l < 3; l++) {
				os << ss.segs[j].seg[k + l];
			}
		}
		k += 3;
		os << endl;
	}

	return os;
}

int main(void) {
	SevenSegs sss(123);
	cout << sss;

	return 0;
}

*/