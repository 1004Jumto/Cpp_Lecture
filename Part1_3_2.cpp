#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

}

int solution(string my_string) {
    int answer = 0;
    string tmp = "";
    vector <int> num;

    for (int i = 0; i < my_string.length(); i++) {
        if (47 < my_string[i] && my_string[i] < 58) {
            tmp += my_string[i];
            if (my_string[i + 1] > 57 || my_string[i + 1] < 48) {
                num.push_back(stoi(tmp));
                tmp = "";
            }
        }
    }

    for (int i = 0; i < num.size(); i++) {
        answer += num[i];
    }

    return answer;
}