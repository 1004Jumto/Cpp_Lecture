#include<iostream>
#include<vector>

using namespace std;

// 상속을 써먹어보자
// 현재는 정사각형만 구하도록 되어있지만 상속을 통해 가장 큰 직사각형의 면적을 구해보자

class P11 {
protected:
	int width;
	int height;
	vector<vector<int>> table;
	int getArea(int top, int left);
	bool isWhatIWant(int top, int left, int bottom, int right);
	virtual bool isCorrectSize(int top, int legt, int bottom, int right);

public:
	P11(vector<vector<int>> table);
	int solution();
};


P11::P11(vector<vector<int>> table)
{
	this->table = table;
	width = table[0].size();
	height = table.size();
}


int P11::getArea(int top, int left)
{
	int maxarea = 0;
	for (int j = left; j < width; j++) {
		for (int i = top; i < height; i++) {
			if (isWhatIWant(top, left, i, j)) {
				int area = (i - top + 1) * (j - left + 1);
				if (area > maxarea) {
					maxarea = area;
				}
			}
		}
	}

	return maxarea;
}

bool P11::isWhatIWant(int top, int left, int bottom, int right)
{

	if ((bottom - top) != (right - left)) {
		return false;
	}

	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if (table[i][j] != 1) {
				return false;
			}
		}
	}

	return true;
}

bool P11::isCorrectSize(int top, int left, int bottom, int right) {
	if ((bottom - top) != (right - left)){
		return false;
	}
	
	return true;
}

int P11::solution()
{
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

class P1122 : public P11 {
	// getArea에서 isSquare가 아니라 isRectangle로 개념이 좀 바뀔 필요가 있음
	// 이때 내가 할 수 있는 선택은 getArea를 오버라이드 하는 방법과, isRectangle함수를 추가하는 방법
private:
	bool isCorrectSize(int top, int left, int bottom, int right);
public:
	P1122(vector<vector<int>> table);
};

P1122::P1122(vector<vector<int>> table) : P11(table) {
}
bool P1122::isCorrectSize(int top, int left, int bottom, int right) {
	return true;
}

int main(void) {
	vector<vector<int>> table = { {0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,0,1,0} };

	P11 p11(table);
	cout << p11.solution() << endl;

	P1122 p1122(table);
	cout << p1122.solution() << endl;

	return 0;
}
