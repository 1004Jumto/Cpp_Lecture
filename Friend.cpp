#include<iostream>
using namespace std;

class CSquare;	// ���� �Ʒ� Ŭ�������� �ش� Ŭ������ ����ϹǷ� ��������
				// ������ �����Ƿ� �����Ϸ��� ���������

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