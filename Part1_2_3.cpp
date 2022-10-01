#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

///////////// My Solution

string solution(string bin1, string bin2);
int toDecimal(string s);
string toBinary(int n);

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    string res = solution(s1, s2);

    cout << res;
    return 0;

}


string solution(string bin1, string bin2) {
    string answer = "";

    // 2진수를 10진수로 변환
    int num1 = toDecimal(bin1);
    int num2 = toDecimal(bin2);

    // 계산
    int res = num1 + num2;

    // 10진수를 2진수로 변환
    answer = toBinary(res);

    return answer;
}

int toDecimal(string s) {
    int i_N = 0;
    int exp = 0;

    if (s == "0") {
        return 0;
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        
        if (s[i] == '1') {
            i_N += pow(2, exp++);
            cout << i_N << endl;
        }
        else {
            exp++;
        }
    }
    return i_N;
}

string toBinary(int n) {
    string bi = "";
    vector<string> v_bi;

    while (n > 1) {
        v_bi.push_back(to_string(n % 2));
        n /= 2;
    }

    v_bi.push_back(to_string(n));

    for (int i = v_bi.size() - 1; i >= 0; i--) {
        bi += v_bi[i];
    }
    return bi;
}


////////// Professor's Solution

string makeAnswer(string ans, int i);
int getDigit(string bin, int i);

string solution_(string bin1, string bin2) {
    string answer = "";
    int a, b, c, s;     // 첫번째 자리, 두번째 자리, 자리올림용, 덧셈한 자릿값
    int len = bin1.length();
    c = 0;

    if (len < bin2.length()) 
        len = bin2.length();

    for (int i = 0; i < len; i++) {
        a = getDigit(bin1, i);
        b = getDigit(bin2, i);
        s = (a + b + c) % 2;
        c = (a + b + c) / 2;

        answer = makeAnswer(answer, s);
    }

    if (c == 1) {
        answer = makeAnswer(answer, c);

        return answer;
    }
}

string makeAnswer(string ans, int i) {
    if (i == 1) {
        return "1" + ans;
    }
    else {
        return "0" + ans;
    }
}

int getDigit(string bin, int i) {
    if (bin.length() < i) {
        return bin[bin.length() - i - 1] - '0';

    }
    else return 0;
}