#include<iostream>
#include<cmath>
#include<string>


using namespace std;

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		if (i * i == N) {
			return 1;
		}
	}

	return 2;

}