/*	3. ���� ����

	�ڿ��� n�� �Ű������� �־����ϴ�. 
	n�� x�� ���� �������� 1�� �ǵ��� �ϴ� ���� ���� �ڿ��� x�� return �ϵ��� solution �Լ��� �ϼ����ּ���. 
	���� �׻� �������� ����� �� �ֽ��ϴ�.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Modular
{
public:
	Modular(int n);
	int solve();

private:
	int n;
};

Modular::Modular(int n) :n(n) { ; }

int Modular::solve()
{
	for (int i = 1; i < n; i++) {
		if (n % i == 1) {
			return i;
		}
	}
}


int solution(int n) {
	int answer = 0;

	Modular m(n);
	answer = m.solve();
	
	return answer;
}