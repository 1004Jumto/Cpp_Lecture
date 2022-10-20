#include<iostream>
#include<string>
#include<vector>

using namespace std;

////////////////////  Solution /////////////////////////////
int myStoi(string num) {
    int digit = 1;
    int n = 0;

    // 1�� �ڸ����� ���ڷ� �ٲ� �����ش�
    for (int i = num.length() - 1; i >= 0; i--, digit *= 10) {
        n += (num[i] - '0') * digit;
    }

    return n;
}

string myItos(int n) {
    string num = "";

    for (int i = n; i > 0; i /= 10) {
        char tmp = (i % 10) + '0';
        num += tmp;
    }

    return num;
}

vector<string> tokenize(string letter) {
    vector<string> tokens;
    int i, j;

    for (i = 0; i < letter.length(); i = j + 1) {
        for (j = i; j < letter.length(); j++) {
            if (letter[j] == ' ') {
                tokens.push_back(letter.substr(i, j - i));
                break;
            }
        }
        if (j == letter.length()) {
            tokens.push_back(letter.substr(i, j - i + 1));
        }
    }

    return tokens;
}

string solution(string polynomial) {
    string answer = "";
    int cof = 0;
    int constant = 0;

    vector<string> tokens = tokenize(polynomial);   // ��ū���� ������ vector�� �־��ִ� �Լ�

    // �Ϲ� ���, x�� ���, + �������� ���а���. +�� �����ص� �ǰ� ����� ����� ������ ��

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {}

        else if (tokens[i][tokens[i].length() - 1] == 'x') {
            if (tokens[i].length() == 1) {        // X�� ����� 1�� ���
                cof++;
            }
            else {
                cof += myStoi(tokens[i].substr(0, tokens[i].length() - 1));
            }
        }
        else {
            constant += myStoi(tokens[i]);
        }
    }

    if (cof == 0) {
        answer = myItos(constant);
    }
    else {
        if (cof == 1) {
            answer = "x";
        }
        else {
            answer = myItos(cof) + "x";
        }
        if (constant > 0) {
            answer = myItos(cof) + "x + " + myItos(constant);
        }
    }

    return answer;
}

int main(void) {
    string str;
    getline(cin, str);

    cout << solution(str) << endl;
    return 0;
}

//////////////////// My Solution /////////////////////////////
string solution(string polynomial) {
	string answer = "";

	// 1. "+" �������� �з�
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

	// 2. �����׳��� ����
	vector<int> itemX;
	vector<int> itemN;
	idxOld = 0, idxNew = 0;

	for (int i = 0; i < items.size(); i++) {
		idxNew = items[i].find("x");
		
		if (idxNew >= 0) {
			items[i].erase(idxNew, 1);
			
			// �տ� ����� 1�� ��쵵 ���,,
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

	// 3. ���
	int sumX = 0;
	int sumN = 0;

	for (int i : itemX) {
		sumX += i;
	}

	for (int i : itemN) {
		sumN += i;
	}

	// 4. ���
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