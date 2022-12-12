/*	9. 문제 설명

    두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요.
    배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다.
    예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.
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
    int getLCM();   // 최소공배수
    int getGCD();   // 최대공약수

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
