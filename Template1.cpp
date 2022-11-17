#include<iostream>
#include"Point.cpp"

using namespace std;

template<class T>
class mypair {
    T a, b;
public:
    mypair(T first, T second) {
        a = first;
        b = second;
    }
    T getmax();
};

template<class T>
T mypair<T>::getmax() {
    T ret;
    ret = a > b ? a : b;
    return ret;
}

int main(void) {
   /* mypair <int> myobj(100, 75);
    mypair <float> myobj2(75.2, 100.004);

    cout << myobj.getmax() << endl;
    cout << myobj2.getmax() << endl;*/

    mypair <Point> myobj3(Point(1,2), Point(3,4));
    cout << myobj3.getmax() << endl;
   
    return 0;
}