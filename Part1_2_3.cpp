#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

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