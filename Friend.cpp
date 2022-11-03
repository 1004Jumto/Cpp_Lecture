#include<iostream>
using namespace std;

class CSquare;	// 당장 아래 클래스에서 해당 클래스를 사용하므로 선언해줌
				// 선언이 있으므로 컴파일러가 통과시켜줌

class CRectangle {
private:
	int width, height;
public:
	int area() {
		return (width * height);
	}
	void convert(CSquare a);
};

class CSquare {
private:
	int side;
public:
	void setSide(int a) {
		side = a;
	}
	friend class CRectangle;
};

void CRectangle::convert(CSquare a) {
	width = a.side;
	height = a.side;

}

int main(void) {
	CSquare sqr;
	CRectangle rect;

	sqr.setSide(4);
	rect.convert(sqr);

	cout << rect.area();
	return 0;
}