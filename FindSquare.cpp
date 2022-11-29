#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class P11 {
private:
	int width;
	int height;
	vector<vector<int>> table;
	int getArea(int top, int left);		// i,j�� ���ʻ�� ���϶� ���� ū ���簢�� ������ ���ϴ� �Լ�
	bool isSquare(int top, int left, int bottom, int right);

public:
	P11(vector<vector<int>> table);
	int solution();		// ���� ū ���簢�� ���� ���ϴ� �Լ�
};


P11::P11(vector<vector<int>> table)
{
	this->table = table;
	width = table[0].size();	// �� ������
	height = table.size();		// �� ������
}

// ���������� ���� ���� �Լ����� �ܺ������� ������ ���� �Լ��� �ƴ�.
// ���� �� Ŭ���� �ۿ��� �� �Լ��� �� �ʿ�� ����
// ���� Sub�� ������� �Լ����� private���� ���� ���� ����
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
	// ���ο� ���ΰ� �Ȱ�����
	if ((bottom - top) != (right - left)) {
		return false;
	}
	
	// ���ο� ���ΰ� ���� �� �� ���� ��� 1�� ä���� �ִ��� �˻�
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

	// ���� 1�� �̾��� ������ ã��, �� ������ �Ʒ��� �ڶ� �� �ִ��� üũ
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

// ����� ��Ծ��
// ����� ���簢���� ���ϵ��� �Ǿ������� ����� ���� ���� ū ���簢���� ������ ���غ���

