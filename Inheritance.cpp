#include<iostream>

using namespace std;

class CPolygon {
protected:
	int width, height;
public:
	void setValues(int a, int b) {
		width = a;
		height = b;
	}
};

class CRectangle :public CPolygon {
public: 
	int area() {				// 상속받은 멤버함수나 변수 외에 필요한 함수를 추가로 정의하여 사용
		return width * height;	// protected가 선언된 변수이므로 자식클래스가 접근할 수 있다
	}
};

class CTriangle :public CPolygon {
public:
	int area() {
		return width * height / 2;
	}
};

int main(void) {
	CRectangle rect;
	CTriangle tri;

	rect.setValues(4, 5);		// 부모클래스로부터 상속받은 public 함수이므로 호출할 수 있다
	tri.setValues(4, 5);		// 부모가 정의해놓은 함수를 재사용한 것이다

	cout << rect.area() << endl;	
	cout << tri.area() << endl;
	
	return 0;
}