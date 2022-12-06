#include <string>
#include <vector>
#include <iostream>

using namespace std;

class OutOfBound {};

class Path
{
public:
	Path(int x1, int y1, int x2, int y2);
	friend bool operator==(Path& a, Path& b);

private:
	int x1, y1, x2, y2;
};

Path::Path(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) { ; }

bool operator==(Path& a, Path& b)
{
	if (a.x1 == b.x1 && a.y1 == b.y1 && a.x2 == b.x2 && a.y2 == b.y2) {
		return true;
	}

	if (a.x1 == b.x2 && a.y1 == b.y2 && a.x2 == b.x1 && a.y2 == b.y1) {
		return true;
	}

	return false;
}

/* Path를 계속 집어넣는 맞춤형 자료구조와 같음 */
class PathQue
{
public:
	void push(Path& a);		// 기존에 동일한 path가 저장된 것이 있는지 검사해야함
	int count();

private:
	vector<Path> paths;
	bool isIn(Path& a);
};

bool PathQue::isIn(Path& a) {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i] == a) {
			return true;
		}
	}
	return false;
}

void PathQue::push(Path& a) {
	if (!isIn(a)) {
		paths.push_back(a);
	}
}

int PathQue::count() {
	return paths.size();
}

/* 문제를 직접적으로 풀기 위한 클래스 */
class Game
{
public:
	Game();
	void move(string& commands);
	int getX();
	int getY();
	int getCount();

private:
	int x, y;
	void move(char c);
	PathQue que;
};

Game::Game() : x(0), y(0) { ; }

void Game::move(string& commands)
{
	for (int i = 0; i < commands.length(); i++) {
		try
		{
			int preX = x;
			int preY = y;
			move(commands[i]);
			Path temp(preX, preY, x, y);
			que.push(temp);
		}
		catch (OutOfBound& e) {

		}
	}
}

int Game::getX() {	return x;  }

int Game::getY() {  return y;  }

int Game::getCount()
{
	return que.count();
}

void Game::move(char c)
{
	switch (c) {
	case'U':
		if (y == 5) throw OutOfBound();
		else {
			y++;
		}
		break;

	case'D':
		if (y == -5) throw OutOfBound();
		else {
			y--;
		}
		break;

	case'R':
		if (x == 5) throw OutOfBound();
		else {
			x++;
		}
		break;

	case'L':
		if (x == -5) throw OutOfBound();
		else {
			x--;
		}
		break;
	}
}

int main(void) {
	Game game;
	string commands = "LULLLLLLU";

	game.move(commands);
	
	cout << "(" << game.getX() << ", " << game.getY() << ") : " << game.getCount() << endl;

	/* Path 만든거 테스트 */
	/*
	Path path1(1, 2, 3, 4), path2(3, 4, 1, 2);
	cout << (path1 == path2) << endl;
	
	Path path3(1, 2, 3, 4), path4(1, 2, 3, 4);
	cout << (path3 == path4) << endl;
	
	Path path5(1, 2, 3, 4), path6(3, 4, 1, 1);
	cout << (path5 == path6) << endl;
	*/

	Path p1(1, 2, 3, 4), p2(1, 2, 5, 6), p3(3, 4, 1, 2);
	PathQue myque;
	myque.push(p1);
	myque.push(p2);
	myque.push(p3);
	cout << myque.count() << endl;

	return 0;
}


