/* 6.���� ����
* 
* �� �������� ǥ�� �Է����� �� ���� ���� n�� m�� �־����ϴ�.
* ��(*) ���ڸ� �̿��� ������ ���̰� n, ������ ���̰� m�� ���簢�� ���¸� ����غ�����.
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