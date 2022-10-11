#include <vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string solution(string letter);
int main(void) {
	string str;
	getline(cin, str);

	cout << solution(str) << endl;
	return 0;
}

string solution(string letter) {
    string answer = "";
    string morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                        ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                        ".--","-..-","-.--","--.." };
    // a~z 91~122

    // 공백으로 나누어 담기
    vector<string> morseLetter;
    string tmp ="";
    for (char c : letter) {
        if (isspace(c)) {
            morseLetter.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += c;
        }
    }
    morseLetter.push_back(tmp);

    // 하나씩 해석하기
    for (int i = 0; i < morseLetter.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (morseLetter[i] == morse[j]) {
                answer += (j + 97);
                
            }
        }
    }

    return answer;

}