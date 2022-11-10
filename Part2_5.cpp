#include <string>
#include <vector>

using namespace std;

bool isCorrect(string s) {
    int len = s.length();

    if (len != 4 && len != 6) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

bool solution(string s) {
    bool answer = true;

    answer = isCorrect(s);

    return answer;
}

int main(void) {
    string str = "1234";
    solution(str);

    return 0;
}