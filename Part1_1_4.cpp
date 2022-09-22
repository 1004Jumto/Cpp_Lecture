#include<iostream>
#include<vector>
#include<string>
/*
연속된 세 개의 정수를 더해 12가 되는 경우는 3, 4, 5입니다.
두 정수 num과 total이 주어집니다. 연속된 수 num개를 더한 값이 total이 될 때, 
정수 배열을 오름차순으로 담아 return하도록 solution함수를 완성해보세요.
*/

using namespace std;

vector<int> solution(int num, int total);

int main(void) {
    int num, total;
    cin >> num >> total;

    solution(num, total);
    return 0;
}


vector<int> solution(int num, int total) {
    vector<int> answer;

    int sum = 0;

    for (int i = -total; i <= total; i++) {
        int tmp = i;

        for (int j = 0; j < num; j++) {
            sum += tmp++;
        }

        if (sum == total) {
            for (int k = 0; k < num; k++) {
                answer.push_back(i++);
            }

            for (int i = 0; i < num; i++) {
                cout << answer[i] << " ";
            }

            return answer;
        }
        else {
            sum = 0;
        }
    }
}

    