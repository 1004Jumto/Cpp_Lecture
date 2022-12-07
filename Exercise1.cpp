 /*	1. 문제 설명

	배열 arr가 주어집니다.배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.
	이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
	단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.
	예를 들면,
	arr = [1, 1, 3, 3, 0, 1, 1] 이면[1, 3, 0, 1] 을 return 합니다.
	arr = [4, 4, 4, 3, 3] 이면[4, 3] 을 return 합니다.
	배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요. 
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Array
{
public:
	Array(vector<int> arr);
	~Array();
	void remove();
	vector<int> getArray();

private:
	vector<int> array;
};

Array::Array(vector<int> arr)
{
	array = arr;
}

Array::~Array()
{
	cout << "Array Destructor is called" << endl;
}

/* 중복 제거 */
void Array::remove()
{
	vector<int> tmp;
	tmp.push_back(array[0]);

	for (int i = 1; i < array.size(); i++) {
		if (array[i] != array[i - 1]) {
			tmp.push_back(array[i]);
		}
	}

	array = tmp;
}

vector<int> Array::getArray() {
	return array;
}


vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	Array a(arr);
	a.remove();
	answer = a.getArray();

	return answer;
}


