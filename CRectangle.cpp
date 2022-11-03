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
	CRectangle a,* b,*c;				// a��ü ���� -> ����
	CRectangle* d = new CRectangle[2];	// d��ü ���� (2��) -> ��, �迭�̹Ƿ� ���ӵ� �޸� �������� �Ҵ��
	b = new CRectangle;					// b��ü ���� -> ��
	c = &a;								// c�� ������ �ּ�(a�� �ּ�)�� ����Ű�� ������
										// �� 4���� CRectangle�� ��ü�� �����Ǿ� �Ҵ��
	
	a.setvalues(1, 2);
	b->setvalues(3, 4);
	d->setvalues(5, 6);
	d[1].setvalues(7, 8);		// �迭�� ������� ������ ���� . ���, ������ element�� CRectangle�� ���
	d[0].setvalues(9, 10);		// �̰Ͱ� d->setValues(9,10);�� �Ϻ��� ���� �޸𸮸� ����Ų��. d�� �� ù��° �޸𸮸� ����Ŵ
	
	c->area();	// c�� �������̹Ƿ� -> ���

	cout << "a area: " << a.area() << endl;
	cout << "*b area: "	<< b->area() << endl;
	cout << "*c area: " << 1 << c->area() << endl;
	cout << "d[0] area: " << d[0].area() << endl;
	cout << "d[l] area: " << d[1].area() << endl;

	delete[] d;		// delete�� ���� ���� �޸𸮸� �����Ѵ�. ������ delete�� �̿����� �ʴ´�
	delete b;
	
	return 0;

}