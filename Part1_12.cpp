#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/////////// Solution 1 ////////////
int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());
    answer = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
    return answer;
}

/////////// Solution 2 ////////////
int solution(vector<int> numbers) {
    int answer = 0;
    int max = 0;
    int idx;
    int sec_max = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (max <= numbers[i]) {
            max = numbers[i];
            idx = i;
        }
    }
    numbers.erase(numbers.begin() + idx);

    for (int i = 0; i < numbers.size(); i++) {
        if (sec_max <= numbers[i]) {
            sec_max = numbers[i];
        }
    }

    answer = max * sec_max;
    return answer;
}