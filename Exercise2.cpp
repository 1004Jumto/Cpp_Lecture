/*	2. ���� ����

   ���� ������ ����� ȸ�翡�� ������ ũ�⸦ ���Ϸ��� �մϴ�. 
   �پ��� ���� ũ���� ���Ե��� ��� ������ �� �����鼭, �۾Ƽ� ��� �ٴϱ� ���� ������ ������ �մϴ�. 
   �̷��� ����� �����ϴ� ������ ����� ���� ���������� ��� ������ ���� ���̿� ���� ���̸� �����߽��ϴ�.

	�Ʒ� ǥ�� 4���� ������ ���� ���̿� ���� ���̸� ��Ÿ���ϴ�.

	���� ��ȣ	���� ����	���� ����
		1			60			50
		2			30			70
		3			60			30
		4			80			40

	���� �� ���� ���̿� ���� ���̰� ���� 80, 70�̱� ������ 80(����) x 70(����) ũ���� ������ ����� ��� ���Ե��� ������ �� �ֽ��ϴ�. 
	������ 2�� ������ ���η� ���� �����Ѵٸ� 80(����) x 50(����) ũ���� �������� ��� ���Ե��� ������ �� �ֽ��ϴ�. 
	�̶��� ���� ũ��� 4000(=80 x 50)�Դϴ�.

	��� ������ ���� ���̿� ���� ���̸� ��Ÿ���� 2���� �迭 sizes�� �Ű������� �־����ϴ�.
	��� ������ ������ �� �ִ� ���� ���� ������ ���� ��, ������ ũ�⸦ return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class NameCard
{
public:
	NameCard(int h, int w);
	int getH();
	int getW();	

private:
	int height;
	int width;
};

NameCard::NameCard(int h, int w) :height(h), width(w) { ; }

int NameCard::getH()
{
	return height;
}

int NameCard::getW()
{
	return width;
}



class Wallet
{
public:
	Wallet();
	void push(NameCard& n);
	int getSize();

private:
	vector<NameCard> cards;
};

Wallet::Wallet() { ; }

void Wallet::push(NameCard& n) {
	cards.push_back(n);
}

int Wallet::getSize() {
	// ���� ����� ���ؾ���
	// ���� ���� �� �� ū ���� ���ο� �ְ�, ���ο� �� ���� ���� �ִ´�
	// �������� ���� ū ���� ������ ���� ���� �ȴ�
	vector<int> w, h;
	for (int i = 0; i < cards.size(); i++) {
		int tempH = cards[i].getH();
		int tempW = cards[i].getW();

		if (tempW > tempH) {
			w.push_back(tempW);
			h.push_back(tempH);
		}
		else {
			w.push_back(tempH);
			h.push_back(tempW);
		}
	}

	sort(w.begin(), w.end());
	sort(h.begin(), h.end());

	return w[w.size() - 1] * h[w.size() - 1];

}



int solution(vector<vector<int>> sizes) {
    int answer = 0;
	Wallet wallet;

	for (int i = 0; i < sizes.size(); i++) {
		NameCard card(sizes[i][0], sizes[i][1]);
		wallet.push(card);
	}

	answer = wallet.getSize();
	
    return answer;
}