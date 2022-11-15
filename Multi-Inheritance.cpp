#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Polygon
{
public:
    Polygon(int m, int n);
    virtual ~Polygon();
    //void draw();
    virtual void draw();
protected:
    int n, m;
};

Polygon::Polygon(int m, int n)
{
    this->m = m;
    this->n = n;
}

Polygon::~Polygon()
{
    cout << "destructor ~Polygon()" << endl;
}

void Polygon::draw()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "*";
        }
        cout << endl;
    }
}


class Rect : public Polygon {
public:
    Rect(int m, int n);
    void draw();
    ~Rect();
};

Rect::Rect(int m, int n) : Polygon(m, n) {}

void Rect::draw() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

Rect::~Rect()
{
    cout << "destructor ~Rect()" << endl;
}

class Triangle : public Polygon {
public:
    Triangle(int m, int n);
    void draw();
    ~Triangle();
};

Triangle::Triangle(int m, int n) : Polygon(m, n) {}

void Triangle::draw() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

Triangle::~Triangle()
{
    cout << "destructor ~Triangle()" << endl;
}

class MyMulti : public string, public Rect {
public:
    MyMulti(int m, int n, const char* str);
};

MyMulti::MyMulti(int m, int n, const char* str) : Rect(m, n), string(str)
{
}

int main(void) {
    MyMulti test(5, 3, "abc");
    test.draw();
    cout << test << endl;
    cout << test[2] << endl;
      
    return 0;
}
