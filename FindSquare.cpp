#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class P11 {
private:
	int width;
	int height;
	vector<vector<int>> table;
	int getArea(int top, int left);		// i,j가 왼쪽상단 점일때 가장 큰 정사각형 면적을 구하는 함수
	bool isSquare(int top, int left, int bottom, int right);

public:
	P11(vector<vector<int>> table);
	int solution();		// 가장 큰 정사각형 면적 구하는 함수
};


P11::P11(vector<vector<int>> table)
{
	this->table = table;
	width = table[0].size();	// 행 사이즈
	height = table.size();		// 열 사이즈
}

// 내부적으로 쓰고 싶은 함수이지 외부적으로 쓰려고 만든 함수가 아님.
// 굳이 내 클래스 밖에서 이 함수를 알 필요는 없다
// 따라서 Sub로 만들어진 함수들은 private으로 놓는 것이 정석
int P11::getArea(int top, int left)
{
	int maxarea = 0;
	for (int j = left; j < width; j++) {
		for (int i = top; i < height; i++) {
			if (isSquare(top, left, i, j)) {
				int area = (i - top + 1) * (j - left + 1);
				if (area > maxarea) {
					maxarea = area;
				}
			}
		}
	}

	return maxarea;
}

bool P11::isSquare(int top, int left, int bottom, int right)
{
	// 가로와 세로가 똑같은지
	if ((bottom - top) != (right - left)) {
		return false;
	}
	
	// 가로와 세로가 같을 때 그 안이 모두 1로 채워져 있는지 검사
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if (table[i][j] != 1) {
				return false;
			}
		}
	}

	return true;
}

int P11::solution()
{
	int maxArea = 0;

	// 먼저 1로 이어진 선분을 찾고, 그 선분이 아래로 자라날 수 있는지 체크
	for (int i = 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int area = getArea(i, j);
			if (area > maxArea) {
				maxArea = area;
			}
		}
	}

	return maxArea;
}

int main(void) {
	vector<vector<int>> table = { {0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,0,1,0} };
	
	P11 p11(table);
	cout << p11.solution() << endl;

	return 0;
}

// 상속을 써먹어보자
// 현재는 정사각형만 구하도록 되어있지만 상속을 통해 가장 큰 직사각형의 면적을 구해보자

