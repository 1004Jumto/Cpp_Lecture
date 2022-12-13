/* 11. 문제 설명

1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다.
표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요.
(단, 정사각형이란 축에 평행한 정사각형을 말합니다.)
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class P11 {
private:
	vector<vector<int>> table;
	int width, height;
	int getArea(int top, int left);
	bool isWhatIWant(int top, int left, int bottom, int right);

public:
	P11(vector<vector<int>> t);
	int solution();
};

P11::P11(vector<vector<int>> t) : table(t) {
	width = t[0].size();
	height = t.size();
}

int P11::getArea(int top, int left) {
	int maxarea = 0;

	for (int j = left; j < width; j++) {
		for (int i = top; i < height; i++) {
			if (isWhatIWant(top, left, i, j)) {
				int area = (i - top + 1) * (j - left + 1);
				if (area > maxarea)maxarea = area;
			}
		}
	}
	return maxarea;
}

bool P11::isWhatIWant(int top, int left, int bottom, int right)

int P11::solution() {
	int maxArea = 0;
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