/* 11. ���� ����

1�� 0�� ä���� ǥ(board)�� �ֽ��ϴ�. ǥ 1ĭ�� 1 x 1 �� ���簢������ �̷���� �ֽ��ϴ�.
ǥ���� 1�� �̷���� ���� ū ���簢���� ã�� ���̸� return �ϴ� solution �Լ��� �ϼ��� �ּ���.
(��, ���簢���̶� �࿡ ������ ���簢���� ���մϴ�.)
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