/* 6.문제 설명
* 
* 이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다.
* 별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Polygon
{
public:
	Polygon(int w, int h);
	virtual void draw() = 0;

protected:
	int width, height;
};

Polygon::Polygon(int w, int h) : width(w), height(h) { ; }


class Rect : public Polygon
{
public:
	Rect(int w, int h);
	void draw();

private:

};

Rect::Rect(int w, int h) : Polygon(w, h) { ; }

void Rect::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main(void) {
	int a, b;
	cin >> a >> b;
	Rect rect(a, b);
	rect.draw();

	return 0;
}