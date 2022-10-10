#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string solution(string polynomial);

int main(void) {
	string str;
	cin >> str;

	cout << solution(str) << endl;
	return 0;
}


string solution(string polynomial) {
	string answer = "";

	// 1. "+" 기준으로 분류
	int idxOld = 0;
	int idxNew = 0;
	vector<string> items;
	string op = "+";

	while (1) {
		idxNew = polynomial.find(op, idxOld);
		
		if (idxNew == -1) {
			items.push_back(polynomial.substr(idxOld));
			break;
		}

		else {
			items.push_back(polynomial.substr(idxOld, idxNew - idxOld));
			idxOld = idxNew + 1;
		}
	}

	// 2. 동류항끼리 묶기
	vector<int> itemX;
	vector<int> itemN;
	idxOld = 0, idxNew = 0;

	for (int i = 0; i < items.size(); i++) {
		idxNew = items[i].find("x");
		
		if (idxNew >= 0) {
			items[i].erase(idxNew, 1);
			
			// 앞에 계수가 1인 경우도 고려,,
			try {
				itemX.push_back(stoi(items[i]));
			}
			catch(...) {
				itemX.push_back(1);
			}
		}
		else {
			itemN.push_back(stoi(items[i]));
		}
	}

	// 3. 계산
	int sumX = 0;
	int sumN = 0;

	for (int i : itemX) {
		sumX += i;
	}

	for (int i : itemN) {
		sumN += i;
	}

	// 4. 출력
	if (sumX == 0)
		answer = to_string(sumN);

	else if (sumX == 1 && sumN == 0)
		answer = "x";

	else if (sumX != 1 && sumN == 0)
		answer = to_string(sumX) + "x";

	else if (sumX == 1 && sumN != 0)
		answer = "x + " + to_string(sumN);

	else
		answer = to_string(sumX) + "x + " + to_string(sumN);

	return answer;
}