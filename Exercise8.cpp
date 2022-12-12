/*	8. ���� ����

    1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.
    �Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
    (1�� �Ҽ��� �ƴմϴ�.)
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

class P8 :public P {
private:

public:
    P8(int n);
    int solution();     // �Ҽ� ���� ã�ƾ���
};

P8::P8(int n) :P(n) { ; }

int P8::solution() {
    int res = 0;

    for (int i = 2; i <= num; i++) {
        if (Util::isPrime(i)) {
            res++;
        }
    }

    return res;
}

int main(void) {
    P* p = new P8(5);
    int res = p->solution();

    cout << res << endl;
    P8 p2(20);

    int cont = p2.solution();
    cout << cont;

    return 0;
}
