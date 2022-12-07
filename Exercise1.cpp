 /*	1. ���� ����

	�迭 arr�� �־����ϴ�.�迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�.
	�̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�.
	��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�.
	���� ���,
	arr = [1, 1, 3, 3, 0, 1, 1] �̸�[1, 3, 0, 1] �� return �մϴ�.
	arr = [4, 4, 4, 3, 3] �̸�[4, 3] �� return �մϴ�.
	�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���. 
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

/* �ߺ� ���� */
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


