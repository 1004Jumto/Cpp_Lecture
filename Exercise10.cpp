/* 10. 문제 설명

정수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수, solution을 완성해주세요.
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

class P10 :public P {
private:

public:
    P10(int n);
    int solution();
};

P10::P10(int n) :P(n) { ; }

// 약수 합 구하기
int P10::solution()
{
    int count = 0;
    for (int i = 0; i <= num; i++) {
        if (num % i == 0) {
            count += i;
        }
    }

    return count;
}

int main(void) {
    P* p = new P10(10);

    cout << p->solution();

    return 0;
}