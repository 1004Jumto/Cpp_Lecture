#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
ios::sync_with_stdio;



bool solution(vector<int> arr) {
	bool answer = true;

	// 일단 배열 길이에 맞게 숫자 있는지 확인
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= 0 || arr[i] > arr.size()) {
			answer = false;
			return answer;
		}
	}

	// 중복 확인
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