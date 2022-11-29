#include<iostream>
using namespace std;

template<class T, int N>
class mysequence
{
public:
	void setmember(int x, T value);
	T getmember(int x);
private:
	T memblock[N];
};

template<class T, int N>
void mysequence<T, N>::setmember(int x, T value) {
	memblock[x] = value;
}

template<class T, int N>
T mysequence<T, N>::getmember(int x) {
	return memblock[x];
}

int main(void) {
	mysequence<int, 5> myint;
	mysequence<double, 5> myflo;
	myint.setmember(0, 100);
	myflo.setmember(3, 3.14);
	cout << myint.getmember(0) << endl;
	cout << myflo.getmember(3) << endl;

	return 0;
}