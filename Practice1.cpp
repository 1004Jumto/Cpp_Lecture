#include<iostream>
using namespace std;

int main(void) {
	int val1, val2;		// ����� ���Ǹ� �ѹ��� �� ���
						// extern : ���� �ϰ� ����
	extern int K;		// (��������)K ��� ������ �ٸ� ���� ��򰡿� ���ǵǾ������� ������ ����� ���ƶ�� ��. �޸𸮰� ������ ���� ����

	cout << "Please enter two integers : ";
	cin >> val1 >> val2;

	int smallest, largest, sum, difference, mul, ratio;	// �ʱ�ȭ�� �ϴ� ������ ����
	
	if (val1 < val2) {
		smallest = val1;
		largest = val2;
	}
	else{
		smallest = val2;
		largest = val1;
	}

	sum = val1 + val2;
	difference = largest - smallest;
	ratio = largest / smallest;
	mul = largest * smallest;

	cout << "smallest = " << smallest << "\n";		// \n���ٴ� endl�� �����ϴ� ����: machine defendency�� ���� �� �ִ� ���� ����
	cout << "largest = " << largest << "\n";
	cout << "sum = " << sum << "\n";
	//cout << "sum = " << largest + smallest << "\n";	// ������ �켱������ <<���� +�� �� �켱��. �򰥸��ٸ� ��ȣ�� ���
	//cout << "sum = " << (largest + smallest) << "\n";	
	cout << "difference = " << difference << "\n";
	cout << "mul = " << mul << "\n";
	cout << "ratio = " << ratio << "\n";
	
	
	return 0;

}