#include<iostream>
#include<stdlib.h>

using namespace std;

class notMovable{};

class Puzzle {
private:
	int x, y;
	int cell[9];
	void shuffle();
	int convert(int x, int y);

public:
	Puzzle();
	void move(char c);
	bool isDone();
	friend ostream& operator<<(ostream& os, Puzzle& p);
};

Puzzle::Puzzle() {
	for (int i = 0; i < 8; i++) {
		cell[i] = i + 1;
	}
	x = 2; y = 2;
	cell[8] = 0;
	shuffle();
}

int Puzzle::convert(int x, int y) {
	return 3 * y + x;
}

void Puzzle::shuffle() {
	srand(time(NULL));
	int rn;
	for (int i = 0; i < 1; i++) {
		rn = rand() % 4;
		try {
		switch (rn) {
		case 0:
			move('u'); break;
		case 1:
			move('d'); break;
		case 2:
			move('r'); break;
		case 3:
			move('l'); break;
		}

		}
		catch (notMovable& e) {
			;
		}
	}

}

void Puzzle::move(char c) {
	int to, from;

	switch (c) {
	case 'u':
		if (y == 0) throw notMovable();
		to = convert(x, y - 1);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		y--; break;

	case 'd':
		if (y == 2) throw notMovable();
		to = convert(x, y + 1);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		y++; break;

	case 'l':
		if (x == 0) throw notMovable();
		to = convert(x - 1, y);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x--; break;

	case 'r':
		if (x == 2) throw notMovable();
		to = convert(x + 1, y);
		from = convert(x, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x++; break;

	default:
		throw notMovable();
	}
}

bool Puzzle::isDone() {
	for (int i = 0; i < 8; i++) {
		if (cell[i] != i + 1) {
			return false;
		}
	}
	if (cell[8] != 0) {
		return false;	
	}
	return true;
}

ostream& operator<<(ostream& os, Puzzle& p) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << p.cell[k++] << " ";
		}
		os << endl;
	}

	return os;
}

int main(void) {
	Puzzle p;
	cout << p;
	while (!p.isDone()) {
		cout << "Choose Movement : ";
		char c;
		cin >> c;
		try {
			p.move(c);
			cout << p;
		}
		catch (notMovable& e) {

		}
	}

	cout << "Its done!";

	return 0;
}
