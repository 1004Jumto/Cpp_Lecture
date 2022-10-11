#include <vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int solution(int n);

int main(void) {
	int num;
	cin >> num;

	cout << solution(num) << endl;
	return 0;
}

int solution(int n) {
	int answer = 0;
	
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			answer++;
		}
	}

	return answer;
}