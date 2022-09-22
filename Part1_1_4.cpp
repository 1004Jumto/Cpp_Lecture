#include<iostream>
#include<vector>
#include<string>
/*
���ӵ� �� ���� ������ ���� 12�� �Ǵ� ���� 3, 4, 5�Դϴ�.
�� ���� num�� total�� �־����ϴ�. ���ӵ� �� num���� ���� ���� total�� �� ��, 
���� �迭�� ������������ ��� return�ϵ��� solution�Լ��� �ϼ��غ�����.
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

    