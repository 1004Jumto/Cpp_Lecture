#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Point
{
public:
	Point();
	Point(float xpos, float ypos);
	~Point();
	float getLength();
	float operator*(Point& pos);		// friend이면 파라미터가 두개이고 멤버함수 아니다
										// 멤버함수로 만들면 파라미터 하나만 받아도 됨
	bool operator>(Point& pos);			// Point끼리의 대소 비교
	friend ostream& operator<<(ostream& os, Point& pos);

protected:			// 상속해주어야 하므로 protected로 선언함
					// private은 상속받는 애들이 아예 접근하지 못하므로 protected로 바꿔주어야 유도클래스가 접근할 수 있다
	float x;
	float y;
};

Point::Point(): x(0), y(0)
{
}

Point::Point(float xpos, float ypos): x(xpos), y(ypos)
{
}

Point::~Point()
{
}

float Point::operator*(Point& pos)
{
	float ans = (x * pos.x) + (y * pos.y);
	return ans;
}

float Point::getLength()
{
	return sqrt(x * x + y * y);
}

ostream& operator<<(ostream& os, Point& pos)
{
	os << "(" << pos.x << ", " << pos.y << ")";

	return os;
}

bool Point::operator>(Point& pos) 
{
	if (this->getLength() > pos.getLength()) {
		return true;
	}
	return false;
}



//class ThreeDiPoint : public Point
//{
//public:
//	ThreeDiPoint();
//	ThreeDiPoint(float x, float y, float z);
//	~ThreeDiPoint();
//	float getLength();
//	float operator*(ThreeDiPoint& pos);
//	friend ostream& operator<<(ostream& os, const ThreeDiPoint& pos);
//private:
//	float z;
//};
//
//ThreeDiPoint::ThreeDiPoint() 
//{
//	z = 0;
//}
//
//ThreeDiPoint::ThreeDiPoint(float x, float y, float z) : Point(x, y), z(z) 
//{
//}
//
//ThreeDiPoint::~ThreeDiPoint()
//{
//}
//
//float ThreeDiPoint::getLength() {
//	return sqrt(Point::getLength() * Point::getLength() + z * z);
//}
//
//float ThreeDiPoint::operator*(ThreeDiPoint& pos) {
//	return (x * pos.x + y * pos.y + z * pos.z);
//}
//
//ostream& operator<<(ostream& os, const ThreeDiPoint& pos) {
//	os << "(" << pos.x << ", " << pos.y << ", " << pos.z << ")";
//
//	return os;
//}

