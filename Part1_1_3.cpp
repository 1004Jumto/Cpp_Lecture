#include <string>
#include <vector>
#include <iostream>

using namespace std;

string shift(string str);

int main() {
    string A; string B;
    cin >> A >> B;

    int answer = 0;

    for (int i = 0; i < A.length(); i++) {
        
        if (A == B) {
            cout << answer;
            return answer;
        }

        A = shift(A);
        cout << A << endl;
        answer++;

    }

    if (answer == A.length()) {
        cout << -1;
        return -1;
    }

    cout << answer;
    return answer;



}

string shift(string str) {

    vector<char> v_str;
    vector<char> comp_str;

    if (str.length() == 1) {
        return str;
    }

    for (int i = 0; i < str.length(); i++) {
        v_str.push_back(str[i]);
    }

    comp_str.push_back(v_str[v_str.size() - 1]);

    for (int i = 0; i < v_str.size() - 1; i++) {
        comp_str.push_back(v_str[i]);
    }

    string res = "";

    for (int j = 0; j < comp_str.size(); j++) {
        res += comp_str[j];
    }

    return res;

}