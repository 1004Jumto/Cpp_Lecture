#include<iostream>
using namespace std;

class mother {
public:
    mother() {
        cout << " mother : no parameter" << endl;
    }
    mother(int a) {
        cout << "mother: int parameter" << endl;
    }
};

class daughter : public mother {
public:
    daughter(int a) {
        cout << " daughter: int parameter" << endl;
    }
};

class son : public mother {
public:
    son(int a) : mother(a) {
        cout << "son : int parameter" << endl;
    }
};

int main(void) {
    daughter july(0);
    son dany(0);

    return 0;
}