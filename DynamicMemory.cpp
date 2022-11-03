#include<iostream>
#include<new>

using namespace std;

int main() {
	int i, n;
	int* p;

	cout << "How many numbers would you like to type? ";

	cin >> i;
	p = new (nothrow) int[i];	// 메모리 할당에 실패했다는 exception이 날아감

	if (p == 0) {
		cout << "Error: memory could not be allocated";
	}
	else {
		for (n = 0; n < i; n++) {
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++) {
			cout << p[n] << ", ";
		}
		delete[] p;

	}
	return 0;
}