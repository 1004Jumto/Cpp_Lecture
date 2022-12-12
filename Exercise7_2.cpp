/*	7-2. 문제 설명

	2차원 좌표 클래스를 구현해보자.
	length는 벡터의 길이를 리턴한다
	operator*는 내적값을 리턴한다
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
	cout << pos2.getLength() << endl;	// 5가 나와야함
	cout << (pos1 * pos2) << endl;

	return 0;
}