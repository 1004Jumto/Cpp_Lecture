#include <iostream>
using namespace std;

class CRectangle {
private:
	int width, height;

public:
	void setvalues(int, int);
	int area(void) {
		return (width * height);
	}
};

void CRectangle::setvalues(int a, int b) {
	width = a;
	height = b;
}

int main() {
	CRectangle a,* b,*c;				// a객체 생성 -> 스택
	CRectangle* d = new CRectangle[2];	// d객체 생성 (2개) -> 힙, 배열이므로 연속된 메모리 공간으로 할당됨
	b = new CRectangle;					// b객체 생성 -> 힙
	c = &a;								// c는 스택의 주소(a의 주소)를 가리키는 포인터
										// 총 4개의 CRectangle의 객체가 생성되어 할당됨
	
	a.setvalues(1, 2);
	b->setvalues(3, 4);
	d->setvalues(5, 6);
	d[1].setvalues(7, 8);		// 배열의 방식으로 접근할 때는 . 사용, 각각의 element를 CRectangle로 취급
	d[0].setvalues(9, 10);		// 이것과 d->setValues(9,10);은 완벽히 같은 메모리를 가리킨다. d는 맨 첫번째 메모리를 가리킴
	
	c->area();	// c는 포인터이므로 -> 사용

	cout << "a area: " << a.area() << endl;
	cout << "*b area: "	<< b->area() << endl;
	cout << "*c area: " << 1 << c->area() << endl;
	cout << "d[0] area: " << d[0].area() << endl;
	cout << "d[l] area: " << d[1].area() << endl;

	delete[] d;		// delete는 힙에 잡힌 메모리만 해제한다. 스택은 delete을 이용하지 않는다
	delete b;
	
	return 0;

}