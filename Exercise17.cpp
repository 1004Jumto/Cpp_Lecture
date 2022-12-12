#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Numbers {
private:
    vector<int> nums;

public:
    vector<int> sum;
    Numbers(vector<int> n);
    void getSum(int len);
};

Numbers::Numbers(vector<int> n) {
    nums = n;
}

void Numbers::getSum(int len) {
    int res = 0;
    int size = nums.size(); //5
    int k = 0;

    for (int i = 0; i < size; i++) {
        k = i;
        for (int j = 0; j < len; j++, k++) {
            res += nums[k % size];
        }
        sum.push_back(res);
        res = 0;
    }
}

int solution(vector<int> elements) {
    int answer = 0;

    Numbers n(elements);

    for (int i = 1; i <= elements.size(); i++) {
        n.getSum(i);
    }

    sort(n.sum.begin(), n.sum.end());
    n.sum.erase(unique(n.sum.begin(), n.sum.end()), n.sum.end());


    return n.sum.size();
}