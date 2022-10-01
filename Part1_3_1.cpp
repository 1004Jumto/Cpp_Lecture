#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int height, width;

    for (int i = 0; i < 4; i++) {
        if (dots[0][0] == dots[i][0]) {
            height = getLength(dots[0][1], dots[i][1]);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (dots[0][1] == dots[i][1]) {
            width = getLength(dots[0][0], dots[i][0]);
        }
    }

    answer = height * width;
    return answer;
}

int getLength(int a, int b) {
    if (a > b) {
        return a - b;
    }
    
    return b - a;
}