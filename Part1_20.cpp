#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    vector<int> count;

    for (int i = 0; i < 1000; i++) {
        count.push_back(0);
    }

    for (int i = 0; i < array.size(); i++) {
        count[array[i]]++;
    }

    // ���� count�� ū ���� array���� �ֺ�
    int max = 0;
    int mode = 0;
    int cnt = 1;
    for (int i = 0; i < 1000; i++) {
        if (max <= count[i]) {
            if (max == count[i])     // �󵵰� ���� ���
                cnt++;
            else {
                cnt = 1;
            }
            max = count[i];
            mode = i;
        }
    }

    if (cnt > 1)
        return -1;

    return mode;
}