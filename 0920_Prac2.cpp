#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
ios::sync_with_stdio;



bool solution(vector<int> arr) {
	bool answer = true;

	// �ϴ� �迭 ���̿� �°� ���� �ִ��� Ȯ��
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= 0 || arr[i] > arr.size()) {
			answer = false;
			return answer;
		}
	}

	// �ߺ� Ȯ��
	int i_testNum = 1;
	sort(arr.begin(), arr.end());
	for (int j = 0; j < arr.size(); j++) {
		if (arr[j] != i_testNum++) {
			answer = false;
			return answer;
		}
	}
	return answer;
}

int main(void) {

}