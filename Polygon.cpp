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
        pol = new Triangle(a, b);   // Triangle�ȿ� ������ ����Ŭ������ Polygon�� ����ֱ� ������ �����ϴ�
    }                               // ����ų ��, �����δ� Triangle�ȿ� �ִ� Polygon�� ���� �ִ� ���̴�. ��, Polygon���� �����Ѵ�
                                    // ���� draw�� ȣ���� ��, polygon�� draw�� ȣ���Ѵ�
    else {
        pol = new Rect(a, b);   
    }

    pol->draw();
    delete pol;
    
    return 0;
}
/*
�̶�, ���α׷��Ӵ� polygon�� �Լ��� �ƴ� �� ����Ŭ������ �Լ��� ȣ���ϰ� ���� �� �ִ�. �׷��� ���ܳ� ������ virtual�̴�. 
virtual�̶� �����Լ��� ����� ����.
�����ϸ�ŷ Ÿ�ӿ� �����Ǿ� polygon�� draw�� ����������, virtual�� �����ϸ� ��Ÿ�ӽ� �� �Լ��� �����ϵ��� �����Ѵ�
�� �� �������̵� �� �Լ��� ȣ���ϵ��� �Ѵ� --> ���α׷��ӿ��� ���ñ��� �ش�

�׷��� �ڹٴ� ���α׷��ӿ��� ���ñ��� ���� �ʱ� ������, �ڹٴ� ��� ��Ÿ�ӽÿ� �����ǰ�, virtual�̶�� Ű���尡 ���� ����. 
�ӵ��� virtual�� �ƴ� �����ϸ�ŷŸ�ӿ� �����Ǵ� ���� �� ������ ������, ȿ������ �߿��� C++���� virtual�̾�� �� �͸� ���� ������ �� �ֵ���
���ñ��� �ִ� ���̴�

����Ŭ������ �߻�Ŭ������ ����� �����Լ��� ����� ���� ��ӿ����� ���� �߿��� ������ �Ѵ�. �� �����Ǿ�� �ϰ�, �⺻���� ö�и��� ��������
�װͿ� ���� ������ �������� �ڽ�Ŭ������ �������� �����Ѵ�

delete Pol 
����� ������ ���� �翬�� �޸𸮸� ��ȯ�� �ǹ��� �ִ�. 
�� Rect�� ������µ� delete���� Polygon�� �Ҹ��ڰ� ȣ��Ǿ�����?
��ü�� ȣ���� �Ҹ��ڸ� �����ϸ�ŷŸ�ӿ� �����ؾ��ϴµ�, �̶� Polygon���� ����Ǿ��� ������ Polygon�� �Ҹ��ڸ� ȣ���� �� �ۿ� ����.
����, Rect�� �Ҹ��ڸ� ȣ���ϰ� �ʹٸ� �Ҹ��ڸ� �����Լ��� �ٲ���Ѵ�   
��Ӱ��踦 �����صдٸ�, �Ҹ��ڴ� �����Լ��� ���س��� ���� ����̴�! �׷��� ����Ʈ �� ��, ����� ���󰡼� �ڽ��� �Ҹ��ڰ� ȣ��ȴ�.

==> �ڽ�Ŭ������� �������� �ʰ�, �� �ȿ� �ִ� �θ�Ŭ������� �����ϱ� ������ �̰��� �ذ��ϱ� ���� �����Լ��� �������, �̰��� ���� �Լ���
ã�ư����� �����ش�
*/

/*

*/