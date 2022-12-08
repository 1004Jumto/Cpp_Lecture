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

class Spot
{
public:
	Spot(string dot, int w, int h);
	void point();

private:
	string pattern;
	int width, height;
};

Spot::Spot(string dot, int w, int h) :pattern(dot), width(w), height(h) { ; }

void Spot::point()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << pattern;
		}
		cout << endl;
	}
}