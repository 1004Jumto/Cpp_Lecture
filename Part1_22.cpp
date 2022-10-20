#include <string>
#include <vector>

using namespace std;

////////////////////// My Solution /////////////////////////////
int getCommonDivisor(int denum, int num);
vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;

    // 통분한 분자 분모
    int denum = denum1 * num2 + denum2 * num1;
    int num = num1 * num2;

    // 공약수 찾기
    int CD = getCommonDivisor(denum, num);
    while (CD != 1) {
        denum /= CD;
        num /= CD;
        CD = getCommonDivisor(denum, num);
    }

    answer.push_back(denum);
    answer.push_back(num);

    return answer;
}

int getCommonDivisor(int denum, int num) {
    int r;

    while (num != 0) {
        r = denum % num;
        if (r == 0) return num;

        denum = num;
        num = r;
    }

    return denum;
}

////////////////////// Professor Solution /////////////////////////////

// 두 개 이상의 리턴 value가 필요할 때 call by ref는 유용하다
void getSum(int& denum, int& num, int denum1, int num1, int denum2, int num2);
void postDiv(int& denum, int& num);

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;
    int denum, num;

    getSum(denum, num, denum1, num1, denum2, num2);
    postDiv(denum, num);

    answer.push_back(denum);
    answer.push_back(num);

    return answer;
}

void getSum(int& denum, int& num, int denum1, int num1, int denum2, int num2) {
    num = num1 * num2;
    denum = denum1 * num2 + denum2 * num1;
}

void postDiv(int& denum, int& num) {
    for (int i = 2; denum > 1 && num > 1 && denum >= i && num >= i; ) {
        if (denum % i == 0 && num % i == 0) {
            denum = denum / i;
            num = num / i;
        }
        else
            i++;
    }
}