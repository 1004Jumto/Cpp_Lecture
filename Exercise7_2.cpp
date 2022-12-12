/*	7-2. ���� ����

	2���� ��ǥ Ŭ������ �����غ���.
	length�� ������ ���̸� �����Ѵ�
	operator*�� �������� �����Ѵ�
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Point {
protected:
	int x;
	int y;

public:
	Point(int xpos, int ypos);
	int getLength();
	friend int operator*(Point& p1, Point& p2);
	friend ostream& operator<<(ostream& os, Point& p);
};

Point::Point(int xpos, int ypos) :x(xpos), y(ypos) { ; }

int Point::getLength() {
	return sqrt(x * x + y * y);
}

int operator*(Point& p1, Point& p2) {
	int res = (p1.x * p2.x) + (p1.y * p2.y);
	return res;
}

ostream& operator<<(ostream& os, Point& p) {
	os << "(";
	os << p.x << "," << p.y << ")" << endl;

	return os;
}

int main(void) {
	Point pos1(2, 5);
	Point pos2(3, -4);

	cout << pos2 << endl;
	cout << pos2.getLength() << endl;	// 5�� ���;���
	cout << (pos1 * pos2) << endl;

	return 0;
}