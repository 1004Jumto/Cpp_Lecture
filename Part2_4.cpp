#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toThird(int n) {
    int p = 1;
    string res = "";

    while (n > 2) {
        res = (char)((n % 3) + '0') + res;
        p *= 10;
        n /= 3;
    }
      
    res = (char)((n % 3) + '0') + res;
    
    cout << res << endl;
    return res;
}

string reverseNum(string n) {
    string tmp = "";

    for (int i = 0; i < n.length(); i++) {
        char c = n[i];
        tmp = c + tmp;
    }

    cout << tmp <<endl;
    return tmp;
}

int toDecimal(string n) {
    int res = 0;
    int p = 1;

    for (int i = n.length() - 1; i >= 0; i--, p *= 3) {
        res += (n[i] - '0')*p;
    }

    cout << res <<endl;
    return res;
}

int solution(int n) {
    int answer = 0;
    string res;
    res = toThird(n);
    res = reverseNum(res);
    answer = toDecimal(res);

    return answer;
}

int main(void) {
    int n;
    cin >> n;
    cout << solution(n)<<endl;

    return 0;
}

