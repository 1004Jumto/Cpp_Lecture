#include <string>
#include <vector>

using namespace std;

/////////////// My Solution //////////////
string solution(int age) {
    string answer = "";
    vector<string> str;
    string sage[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };

    while (age != 0) {
        str.push_back(sage[age % 10]);
        age /= 10;
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        answer += str[i];
    }

    return answer;
}


/////////// Professor Solution ///////////
string solution(int age) {
    string answer = "";

    for (int i = age; i > 0; i /= 10) {
        answer = (char)('a' + (i % 10)) + answer;
    }

    return answer;
}