#include<iostream>

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

int main(void) {
    Polygon* pol;

    int a, b;
    int type;
    cin >> type >> a >> b;

    if (type == 3) {  
        pol = new Triangle(a, b);   // Triangle안에 어차피 기초클래스인 Polygon이 들어있기 때문에 가능하다
    }                               // 가리킬 때, 실제로는 Triangle안에 있는 Polygon을 보고 있는 것이다. 즉, Polygon으로 간주한다
                                    // 따라서 draw를 호출할 때, polygon의 draw를 호출한다
    else {
        pol = new Rect(a, b);   
    }

    pol->draw();
    delete pol;
    
    return 0;
}
/*
이때, 프로그래머는 polygon의 함수가 아닌 그 유도클래스의 함수를 호출하고 싶을 수 있다. 그래서 생겨난 문법이 virtual이다. 
virtual이란 가상함수를 만드는 선언.
컴파일링킹 타임에 결정되어 polygon의 draw로 결정되지만, virtual을 선언하면 런타임시 그 함수를 결정하도록 보류한다
그 후 오버라이드 된 함수를 호출하도록 한다 --> 프로그래머에게 선택권을 준다

그러나 자바는 프로그래머에게 선택권을 주지 않기 때문에, 자바는 모두 런타임시에 결정되고, virtual이라는 키워드가 따로 없다. 
속도는 virtual이 아닌 컴파일링킹타임에 결정되는 것이 더 빠르기 때문에, 효율성이 중요한 C++에서 virtual이어야 할 것만 따로 선언할 수 있도록
선택권을 주는 것이다

기초클래스를 추상클래스로 만들고 가상함수로 만드는 것이 상속에서의 아주 중요한 역할을 한다. 꼭 구현되어야 하고, 기본적인 철학만을 남기지만
그것에 대한 직접적 구현에서 자식클래스의 자유도를 보장한다

delete Pol 
사용이 끝나고 나면 당연히 메모리를 반환할 의무가 있다. 
왜 Rect을 만들었는데 delete에서 Polygon만 소멸자가 호출되었을까?
객체가 호출할 소멸자를 컴파일링킹타임에 결정해야하는데, 이때 Polygon으로 선언되었기 때문에 Polygon의 소멸자를 호출할 수 밖에 없다.
따라서, Rect의 소멸자를 호출하고 싶다면 소멸자를 가상함수로 바꿔야한다   
상속관계를 염두해둔다면, 소멸자는 가상함수로 정해놓는 것이 상식이다! 그래야 딜리트 할 때, 제대로 따라가서 자식의 소멸자가 호출된다.

==> 자식클래스라고 생각하지 않고, 그 안에 있는 부모클래스라고 생각하기 때문에 이것을 해결하기 위해 가상함수를 만들었고, 이것은 실제 함수를
찾아가도록 도와준다
*/

/*

*/