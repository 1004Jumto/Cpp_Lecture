#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 내 풀이
int solution(vector<int> sides) {

    sort(sides.begin(), sides.end());

    if (sides[2] < sides[0] + sides[1]) {
        return 1;
    }

    return 2;
}


// 교수님 풀이
int getLongest(vector<int> sides) {
	int longest = -1;
	for (int i - 0; i < sides.size(); i++) {
		if (sides[i] > longest) {
			longest = sides[i];
		}
	}
	return longest;
}

int getOthersum(vector<int>sides, itn longest) {
	int othersum = 0;
	for (int i = 0; i < sides.size(); i++) {
		othersum += sides[i];
	}
	return othersum - longest;
}

int solution(vector<int> sides) {
	int answer = 2;
	int longest = getLongest(sides);
	int othersum = getOthersum(sides, longest);

	if (longest < othersum) {
		answer = 1;
	}

	return answer;
}