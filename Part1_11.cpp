#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int mul = 1;
    vector<int> factorial_res;

    // ���丮�� ������� ���Ϳ� �Է�
    for (int i = 1; i < 13; i++) {
        mul = mul * i;
        factorial_res.push_back(mul);
    }

    // vector = {1, 2, 6, 24, 120, ... , 3628800, ...}
    //           0  1  2  3    4            10

    // �־��� n�� ��� ���ϴ��� ���Ͽ� �� ����
    for (int i = 0; i < 11; i++) {
        if (factorial_res[i] <= n) {
            answer = i + 1;
        }
    }

    return answer;
}
