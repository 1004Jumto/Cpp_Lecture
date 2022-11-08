#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Number 
{
private:
    string n;
    int k;
    void setNum(int n);

public:
    Number(int n);
    void changeNum(int k);
    string getN();
    int getNum();
    void setNum(string n);
};

Number::Number(int n) 
{
    this->k = 10;
    setNum(n);
}

//int -> string 변환 함수
void Number::setNum(int n) 
{
    this->n = "";
    for (int m = n; m > 0; m /= 10) {
        this->n = (char)('0' + (m % 10)) + this->n;
    }
}

// string을 10진수 숫자로 변환하는 함수
int Number::getNum() 
{
    int i = 1;
    int dec = 0;

    for (int m = n.length() - 1; m >= 0; m--) {
        dec += (n[m]-'0') * i;
        i *= k;
    }

    return dec;
}

// k진법으로 변환하는 함수
void Number::changeNum(int k)
{
    int dec = getNum();
    this->k = k;
    this->n = "";
    
    for (int m = dec; m > 0; m /= k) {
        this->n = (char)('0' + (m % k)) + this->n;
    }
}

string Number::getN()
{
    return n;
}

void Number::setNum(string n)
{
    this->n = n;
}

class Converter
{
public:
    static string reverse(string s);
};

string Converter::reverse(string s)
{
    string ret = "";
    
    for (int i = 0; i < s.length(); i++) {
        ret = s[i] + ret;
    }

    return ret;
}

int main(void) {
    Number mynum(45);
    cout << mynum.getN() << endl;
    
    mynum.changeNum(3);
    cout << mynum.getN() << endl;
    mynum.setNum(Converter::reverse(mynum.getN()));
    cout << mynum.getN() << endl;

    //mynum.changeNum(10);
    //cout << mynum.getN() << endl;

    cout << mynum.getNum() << endl;

    return 0;
}
