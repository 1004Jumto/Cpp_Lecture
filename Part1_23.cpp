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
bool isPal(int num);
void getStr(string& s, int k);
void getRevStr(string& s, int k);

int solution(int n, int m) {
    int answer = 0;
    for (int i = 0; i <= m; i++) {
        if (isPal(i)) // palindrome인지 아닌지 검사하는 함수
            answer++;
    }
    
    return answer;
}

bool isPal(int k) {
    string str, revstr;
    
    getStr(str, k);         // 숫자 k를 문자열로 바꾸는 함수
    getRevStr(revstr, k);   // 거꾸로 문자열을 만드는 함수
    
    if (str == revstr)
        return true;
    else
        return false;
}

void getStr(string& s, int k) {
    s = "";
    for (int i = k; i > 0; i /= 10) {
        s = (char)('0' + (i % 10)) + s;
    }
}

void getRevStr(string& s, int k) {
    s = "";
    for (int i = k; i > 0; i /= 10) {
        s += (char)('0' + (i % 10));
    }
}