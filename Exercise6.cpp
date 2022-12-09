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