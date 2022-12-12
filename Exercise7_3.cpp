/*	7-3. 위의 Point클래스를 상속받는 3차원 Point클래스를 구현해보자

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

class ThreeDiPoint : public Point {
private:
	int z;

public:
	ThreeDiPoint(int xpos, int ypos, int zpos);
	int getLength();
	friend ostream& operator<<(ostream& os, ThreeDiPoint& p);
	friend int operator*(ThreeDiPoint& p1, ThreeDiPoint& p2);
};

ThreeDiPoint::ThreeDiPoint(int xpos, int ypos, int zpos) :Point(xpos, ypos), z(zpos) { ; }

int ThreeDiPoint::getLength() {
	int res = (x * x) + (y * y) + (z * z);
	return sqrt(res);
}

ostream& operator<<(ostream& os, ThreeDiPoint& p) {
	os << "(";
	os << p.x << "," << p.y << "," << p.z << ")";

	return os;
}

int operator*(ThreeDiPoint& p1, ThreeDiPoint& p2) {
	int res = (p1.x * p2.x) + (p1.y * p2.y) + (p1.z * p2.z);
	return res;
}

int main(void) {
    ThreeDiPoint pos1(2, 5, 1);
    ThreeDiPoint pos2(3, -4, 5);

    cout << pos2 << endl;
    cout << pos2.getLength() << endl;
    cout << (pos1 * pos2) << endl;

    return 0;
}