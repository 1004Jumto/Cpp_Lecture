#include<iostream>
#include<vector>

using namespace std;

class FX
{
public:
	FX(long long n);
	long long solution();

protected:
	long long n;
	int diff(long long num, long long com);		// 다른 비트의 수를 리턴하는 함수
												// protected혹은 private영역으로 선언해줌
	virtual int limit();						// 이 때 solution은 FX에만 있기 때문에 limit이 FX의 limit만 호출된다. 
												// 이를 방지하기 위해 virtual을 선언해주어야 한다
};

FX::FX(long long n)
{
	this->n = n;		// 원래 변수 이름 중복은 피하는게 맞음, 교수님이 this 쓰는거 보여주려고 일부로
}

long long FX::solution() {
	long long i;

	for (i = n + 1; diff(n, i) > limit(); i++) {
		return i;
	}
	//diff(n, i) > 2 를 고치면 내가 원하는 자리수 검사를 할 수 있는데,, 상속을 이용하는 것이 좋음
}

int FX::diff(long long num, long long com) {
	int count = 0;				// 다른 개수 카운트 하는 변수
	int len = sizeof(num) * 8;	// n이 몇 비트로 이루어져 있는지 구한 뒤 8을 곱해 맞춰줌
	long long mask = 1;

	for (int j = 0; j < len; j++) {
		// 모든 자리의 비트를 검사
		// n&mask, i&mask => 맨 마지막 비트가 뽑힌다고..? 비트 와이즈..?
		if ((num & mask) != (com & mask)) {
			count++;
		}
		mask = (mask << 1);		// 왼쪽으로 한번 옮김
	}

	return count;
}

int FX::limit() {
	return 2;
}

class FX2 : public FX {
protected:
	int limit();

public:
	FX2(long long n);
	//long long solution();	// override
	// 이때 solution함수는 숫자 하나 빼고 거의 겹친다. 중복을 최소화 시키는 것이 c++의 철학이므로 수정할 필요가 있다.
	// 허용하는 비트수를 만들어주는 함수를 하나 만든다.
};


FX2::FX2(long long n) : FX(n) { ; }

int FX2::limit() {
	return 3;
}	

//long long FX2::solution() {
//	long long i;
//
//	for (i = n + 1; diff(n, i) > 3; i++) {
//		return i;
//	}
//}

int main(void) {
	long long n = 7;
	FX fx(n);
	cout << n << " : " << fx.solution() << endl;

	FX2 fx2(n);
	cout << n << " : " << fx2.solution() << endl;
}