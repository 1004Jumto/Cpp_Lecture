#include<iostream>
using namespace std;

class CDummy {
public:
	static int n;	// n은 정적변수이므로 a,b,c가 모두 공유한다
	CDummy() {		// 만약 생성자에서 n = 0으로 초기화시키면 객체가 생성될때마다 초기화되어 n은 0이 된다
		n++;
	}
	~CDummy() {
		n--;
	}
};

int CDummy::n = 0;		// 자바에서는 클래스 내에서 메모리 할당을 허용하지만, C++에서는 허용하지 않는다.
						// 따라서 외부에서 초기화한다

int main(void) {
	CDummy a;					// 스택
	CDummy b[5];				// 스택
	CDummy* c = new CDummy();	// 힙, 여기까지 객체가 총 7개가 생성된다

	cout << a.n << endl;		// 처음엔 0이었으나, 위에서 객체가 7개가 생성되면서 정적변수인 n이 ++되면서 결과적으로 7이 됨
								// 정적변수 n이 하나의 클래스의 서로 다른 객체 사이에서 공유됨을 알 수 있음
	delete c;
	cout << CDummy::n << endl;	// static이므로 이렇게 명시할 수 있다. 일반적 멤버변수는 이렇게 쓸 수 없음
								// 조금 더 명확한 표현이라 할 수 있음

	cout << sizeof(a) << endl;	// 1이라고 출력됨
								// 만약 n이 정적변수가 아닌 일반적인 멤버변수였다면 4가 출력됨
								// 즉, 정적변수는 일반적 멤버변수와 달리 sizeof에 포함시키지 않음. 그러나 일반 멤버변수가 없을 땐 1로 출력.
	return 0;
}