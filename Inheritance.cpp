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
	int area() {				// ��ӹ��� ����Լ��� ���� �ܿ� �ʿ��� �Լ��� �߰��� �����Ͽ� ���
		return width * height;	// protected�� ����� �����̹Ƿ� �ڽ�Ŭ������ ������ �� �ִ�
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

	rect.setValues(4, 5);		// �θ�Ŭ�����κ��� ��ӹ��� public �Լ��̹Ƿ� ȣ���� �� �ִ�
	tri.setValues(4, 5);		// �θ� �����س��� �Լ��� ������ ���̴�

	cout << rect.area() << endl;	
	cout << tri.area() << endl;
	
	return 0;
}