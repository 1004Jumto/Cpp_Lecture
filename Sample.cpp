#include<iostream>
#include"Sample.h"

using namespace std;

Sample::Sample() {
    cout << "Sample() is called" << endl;
}

Sample::Sample(int x) {

}

Sample::Sample(const Sample& a){

}

Sample::~Sample()
{
}

void Sample::setM(int x)
{
}

int Sample::getM() const
{
    return 0;
}



Sample Sample::operator+(const Sample& a) {
    Sample x;
    x.m = this->m + a.m;
    x.n = this->n + a.n;

    return x;
}


Sample operator-(const Sample& a, const Sample& b){
    Sample x;
    x.m = a.m - b.m;
    x.n = a.n - b.n;

    return x;
}
