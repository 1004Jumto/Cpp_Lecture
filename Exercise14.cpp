#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class outOfBound {};
class Game;
class Path;
class PathQue;

class Path {
private:
    int x1, y1, x2, y2;
public:
    Path(int x1, int y1, int x2, int y2);
    friend bool operator==(Path& p1, Path& p2);
};

Path::Path(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) { ; }

bool operator==(Path& p1, Path& p2) {
    if (p1.x1 == p2.x1 && p1.y1 == p2.y1 && p1.x2 == p2.x2 && p1.y2 == p2.y2) {
        return true;
    }

    if (p1.x1 == p2.x2 && p1.y1 == p2.y2 && p1.x2 == p2.x1 && p1.y2 == p2.y1) {
        return true;
    }

    return false;
}

class PathQue {
private:
    vector<Path> pq;
    bool isIn(Path& p);

public:
    void push(Path& p);
    int count();
};

void PathQue::push(Path& p) {
    if (!isIn(p)) {
        pq.push_back(p);
    }
}

bool PathQue::isIn(Path& p) {
    for (int i = 0; i < pq.size(); i++) {
        if (pq[i] == p) {
            return true;
        }
    }
    return false;
}

int PathQue::count() {
    return pq.size();
}

class Game {
private:
    string command;
    int x, y;
    void move(char c);
    PathQue que;

public:
    Game();
    int getX();
    int getY();
    int getCount();
    void move(string& c);
};

Game::Game() :x(0), y(0) { ; }

int Game::getX() {
    return x;
}

int Game::getY() {
    return y;
}

void Game::move(string& c) {
    for (int i = 0; i < c.length(); i++) {
        try {
            move(c[i]);
        }
        catch (outOfBound& e) {
            ;
        }
    }
}

void Game::move(char c) {
    int prevx = x;
    int prevy = y;

    switch (c) {
    case 'U':
        if (y == 5) throw outOfBound();
        y++;
        break;

    case 'D':
        if (y == -5) throw outOfBound();
        y--;
        break;

    case 'R':
        if (x == 5)throw outOfBound();
        x++;
        break;

    case 'L':
        if (x == -5)throw outOfBound();
        x--;
        break;
    }

    Path tmp(prevx, prevy, x, y);
    que.push(tmp);
}

int Game::getCount() {
    return que.count();
}

int main(void) {
    Game game;
    string commands = "ULURRDLLU";

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