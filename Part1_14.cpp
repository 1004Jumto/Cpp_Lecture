#include<iostream>
#include<vector>

using namespace std;

int Factorial(int num) {
    if (num == 0) {
        return 1;
    }

    if (num == 1) {
        return 1;
    }

    else {
        return num * Factorial(num - 1);
    }
}

long long int product(int num, int count) {
    long long int answer = 1;
    for (int i = 0; i < count; i++) {
        answer = answer * (num - i);
        if (answer == 0) answer = 1;
    }

    return answer;
}

int solution(int balls, int share) {
    vector<int> top;
    vector<int> bottom;

    for (int i = share + 1; i <= balls; i++) {
        top.push_back(i);
    }

    for (int i = 1; i <= share; i++) {
        bottom.push_back(i);
    }

    for (int i = 0; i < bottom.size(); i++) {
        for (int j = 0; j < top.size(); j++) {
            if (bottom[i] == top[j]) {
                bottom.erase(bottom.begin() + i);
                top.erase(top.begin() + j);
                break;
            }
        }
    }

    int totalTop = 1;
    int totalBottom = 1;

    for (int i = 0; i < top.size(); i++) {
        totalTop *= top[i];
    }
    for (int i = 0; i < bottom.size(); i++) {
        totalBottom *= bottom[i];
    }

    int answer = totalTop / totalBottom;

    return answer;

}

int main(void) {
    while (true) {
        int ball, shar;
        cin >> ball >> shar;
        if (ball == -1 || shar == -1) {
            break;
        }
        cout << solution(ball, shar) << endl;

    }
    return 0;
}