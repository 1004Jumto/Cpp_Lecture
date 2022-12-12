/* Practice 2
* 8개의 숫자가 있는 퍼즐 클래스를 구현한다
* 1 2 3
* 4 5 6 
* 7 8 0
* 이 상태를 만들어주어야한다

* 초기화 상태에서 shuffle이라는 함수 호출. shuffle은 랜덤하게 초기화된 퍼즐을 바꿔줌
* u/d/l/r을 입력받아 0을 이동시킨다
* 0이 이동할 수 없는 경우 NotMovable 예외를 던진다
* isDone은 퍼즐이 완성되어있는지 검사하는 함수
* << 연산자 오버로딩 : 현재 퍼즐 상태를 출력
*/

// 랜덤 넘버 만드는 코드

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

class notMovable{};

class Puzzle {
private:
	int pos;
	int board[9];
	void shuffleBoard();
	void Init();
	void swap(int a, int b);

public:
	Puzzle();
	void movePos(char c);
	bool isDone();
	friend ostream& operator<<(ostream& os, Puzzle& p);
};

Puzzle::Puzzle() {
	Init();				// 1,2,3,4,5,6,7,8,0 board 초기화
	try {
		shuffleBoard();		// 랜덤으로 보드 셔플
	}
	catch (notMovable& e) {
		;
	}
}

void Puzzle::Init() {
	for (int i = 0; i < 9; i++) {
		board[i] = i + 1;
	}

	board[8] = 0;
	pos = 8;
}

bool Puzzle::isDone() {
	int k = 1;
	for (int i = 0; i < 8; i++, k++) {
		if (board[i] != k) {
			return false;
		}
	}

	if (board[8] != 0) {
		return false;
	}
	else {
		return true;
	}
}

void Puzzle::shuffleBoard() {
	// 랜덤으로 섞고
	srand(time(NULL));
	int n;
	for (int i = 0; i < 6; i++) {
		n = rand() % 4;

		switch (n) {
		case 0:
			movePos('u'); break;
		case 1:
			movePos('d'); break;
		case 2:
			movePos('r'); break;
		case 3:
			movePos('l'); break;
		default:
			break;
		}
	}
}

void Puzzle::movePos(char c) {
	switch (c) {
	case 'u':
		if (0 <= pos && pos <= 2) throw notMovable();
		swap(pos, pos - 3);
		break;

	case 'd':
		if (6 <= pos && pos <= 8) throw notMovable();
		swap(pos, pos + 3);
		break;

	case 'r':
		if (pos == 2 || pos == 5 || pos == 8) throw notMovable();
		swap(pos, pos + 1);
		break;

	case 'l':
		if (pos == 0 || pos == 3 || pos == 6) throw notMovable();
		swap(pos, pos - 1);
		break;

	default:
		throw notMovable();
	}
}

void Puzzle::swap(int a, int b) {
	int tmp = board[a];
	board[a] = board[b];
	board[b] = tmp;
	pos = b;
}

ostream& operator<<(ostream& os, Puzzle& p) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << p.board[k++];
		}
		os << endl;
	}

	return os;
}

int main(void) {
	Puzzle puzzle;
	char in;
	cout << puzzle;

	while (puzzle.isDone() == false) {
		cout << "Choose Movement :";
		cin >> in;
		try {
			puzzle.movePos(in);
		}
		catch (notMovable& e) {
			cout << "notMovable" << endl;
		}
		cout << puzzle;
	}

	cout << "It's Done!";

	return 0;
}


