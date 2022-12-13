#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Bits {
private:
	long long n;
	int limit();
	int diff(int n1, int n2);

public:
	Bits(long long num);
	int solution();

};

Bits::Bits(long long num) :n(num) { ; }

int Bits::limit() {
	return 2;
}

int Bits::diff(int n1, int n2) {
	int count = 0;
	int len = sizeof(n1) * 8;
	long long mask = 1;

	for (int i = 0; i < len; i++) {
		if ((n1 & mask) != (n2 & mask)) {
			count++;
		}
		mask = mask << 1;	
	}

	return count;
}

int Bits::solution() {
	int i;
	for (i = n+1; diff(n, i) > limit(); i++) {

	}
	return i;
}

//int main(void) {
//	Bits bit(7);
//	cout << bit.solution();
//
//	return 0;
//}

