/*	9. ���� ����

    �� ���� �Է¹޾� �� ���� �ִ������� �ּҰ������ ��ȯ�ϴ� �Լ�, solution�� �ϼ��� ������.
    �迭�� �� �տ� �ִ�����, �״��� �ּҰ������ �־� ��ȯ�ϸ� �˴ϴ�.
    ���� ��� �� �� 3, 12�� �ִ������� 3, �ּҰ������ 12�̹Ƿ� solution(3, 12)�� [3, 12]�� ��ȯ�ؾ� �մϴ�.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Util {
private:
    static bool isDiv(int a, int b);
public:
    static bool isPrime(int n);
};

bool Util::isPrime(int n) {
    int i;
    for (i = 2; i <= n; i++) {
        if (isDiv(i, n)) {
            break;
        }
    }
    if (i == n) {
        return true;
    }
    else {
        return false;
    }
}

bool Util::isDiv(int a, int b) {
    return (b % a == 0);
}

class P {
protected:
    int num;

public:
    P(int n);
    virtual int solution() = 0;
};

P::P(int n) :num(n) { ; }

class P9 : public P {
private:
    int n2;
    int getLCM();   // �ּҰ����
    int getGCD();   // �ִ�����

public:
    P9(int a, int b);
    int solution();
};

int P9::getLCM()
{
    return num * n2 / (getGCD());
}

int P9::getGCD()
{
    int res;
    int a = num;
    int b = n2;

    while (b != 0) {
        res = a % b;
        a = b;
        b = res;
    }

    return res;
}

P9::P9(int a, int b) :P(a), n2(b) { ; }

int P9::solution()
{
    int gcd = getGCD();
    int lcm = getLCM();

    cout << gcd << "\n" << lcm;

    return 0;
}

int main(void) {
    P* p = new P9(3, 12);
    p->solution();

    return 0;
}
