#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board);
vector<int> moveKey(string input, vector<int> board_size, vector<int> pos);

int main(void) {
    vector<string> key = { "left", "right", "up", "right", "right" };
    vector<int> bo = { 11,11 };

    solution(key, bo);
    return 0;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> position = { 0,0 };

    for (int i = 0; i < keyinput.size(); i++) {
        position = moveKey(keyinput[i], board, position);
        cout << position[0] << " " << position[1] << endl;
    }

    return board;
}

vector<int> moveKey(string input, vector<int> board_size, vector<int> pos) {

    if (input == "left" && pos[0] > -(board_size[0] / 2)) {
        pos[0]--;
    }

    else if (input == "right" && pos[0] < (board_size[0] / 2)) {
        pos[0]++;
    }

    else if (input == "up" && pos[1] < (board_size[1] / 2)) {
        pos[1]++;
    }

    else if (input == "down" && pos[1] > -(board_size[1] / 2)) {
        pos[1]--;
    }

    cout << pos[0] << " " << pos[1] << endl;
    return pos;
}

