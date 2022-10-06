#include<iostream>

using namespace std;

long long int product(int num, int count) {
    long long int answer = 1;
    for (int i = 0; i < count; i++) {
        answer = answer * (num - i);
        if (answer == 0) answer = 1;
    }

    return answer;
}

long long int solution(int balls, int share) {
    long long int a = product(balls, share);
    long long int b = product(share, share);
    long long int answer = a / b;
    return answer;
}

int main(void) {
    while (true) {
        int ball, shar;
        cin >> ball >> shar;
        if (ball == -1) {
            break;
        }
        cout << solution(ball, shar) << endl;

    }
    return 0;
}