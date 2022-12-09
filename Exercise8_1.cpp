/*	8. ���� ����

    1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.
    �Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
    (1�� �Ҽ��� �ƴմϴ�.)
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Utility
{
public:
    Utility(int n);
    ~Utility();
    virtual int solution() = 0;

protected:
    int num;
};


class P8 : public Utility
{
public:
    P8(int n);
    ~P8();
    int solution();

private:
    bool isPrime(int n);
};

P8::P8(int n) :Utility(n) { ; }



int P8::solution()
{
    cout << "P8 solution" << endl;
    int count = 0;
    for (int i = 2; i <= num; i++)
    {
        if (isPrime(i)) 
        {
            count++;
        }
    }
    return count;
}

bool P8::isPrime(int n)
{
    if (n % 2 == 0) {
        return false;
    }
    
    if (n % 3 == 0) {
        return false;
    }

    for(int i)
    return false;
}

int main()
{
    Utility* first, * second;
    first = new P8(12);
    second = new P8(5);
    cout << "P8, 12: " << first->solution() << endl;
    cout << "P8, 5: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P10(12);
    second = new P10(5);
    cout << "p10, 12: " << first->solution() << endl;
    cout << "p10, 5: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P9(12, 8);
    second = new P9(12, 6);
    cout << "p9, 12, 8: " << first->solution() << endl;
    cout << "p9, 12, 6: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P92(12, 8);
    second = new P92(12, 6);
    cout << "p92, 12, 8: " << first->solution() << endl;
    cout << "p92, 12, 6: " << second->solution() << endl;
    delete first;
    delete second;
}

Utility::Utility(int n) :num(n) { ; }
