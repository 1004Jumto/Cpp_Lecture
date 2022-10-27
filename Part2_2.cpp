#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    // ū ���� �������� ����
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }

    // �� ū �� ã�� 
    int max0 = 0, max1 = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] >= max0) {
            max0 = sizes[i][0];
        }
        if (sizes[i][1] >= max1) {
            max1 = sizes[i][1];
        }
    }

    answer = max0 * max1;
    return answer;
}