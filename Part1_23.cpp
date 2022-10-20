#include <string>
#include <vector>
#include <iostream>

using namespace std;

////////////// My Solution /////////////////
bool isPalindrome(int num);

int solution(int n, int m) {
    int answer = 0;

    for (int i = n; i <= m; i++) {
        if (isPalindrome(i))
            answer++;
    }
    return answer;
}

bool isPalindrome(int num) {
    if (1 <= num && num <= 9)
        return true;

    string s = to_string(num);

    for (int i = 0; i < (s.length() / 2); i++) {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }

    return true;

}

////////////// Professor Solution /////////////////