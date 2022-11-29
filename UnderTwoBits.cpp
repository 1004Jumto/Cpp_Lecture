#include<iostream>
#include<vector>

using namespace std;

class FX
{
public:
	FX(long long n);
	long long solution();

protected:
	long long n;
	int diff(long long num, long long com);		// �ٸ� ��Ʈ�� ���� �����ϴ� �Լ�
												// protectedȤ�� private�������� ��������
	virtual int limit();						// �� �� solution�� FX���� �ֱ� ������ limit�� FX�� limit�� ȣ��ȴ�. 
												// �̸� �����ϱ� ���� virtual�� �������־�� �Ѵ�
};

FX::FX(long long n)
{
	this->n = n;		// ���� ���� �̸� �ߺ��� ���ϴ°� ����, �������� this ���°� �����ַ��� �Ϻη�
}

long long FX::solution() {
	long long i;

	for (i = n + 1; diff(n, i) > limit(); i++) {
		return i;
	}
	//diff(n, i) > 2 �� ��ġ�� ���� ���ϴ� �ڸ��� �˻縦 �� �� �ִµ�,, ����� �̿��ϴ� ���� ����
}

int FX::diff(long long num, long long com) {
	int count = 0;				// �ٸ� ���� ī��Ʈ �ϴ� ����
	int len = sizeof(num) * 8;	// n�� �� ��Ʈ�� �̷���� �ִ��� ���� �� 8�� ���� ������
	long long mask = 1;

	for (int j = 0; j < len; j++) {
		// ��� �ڸ��� ��Ʈ�� �˻�
		// n&mask, i&mask => �� ������ ��Ʈ�� �����ٰ�..? ��Ʈ ������..?
		if ((num & mask) != (com & mask)) {
			count++;
		}
		mask = (mask << 1);		// �������� �ѹ� �ű�
	}

	return count;
}

int FX::limit() {
	return 2;
}

class FX2 : public FX {
protected:
	int limit();

public:
	FX2(long long n);
	//long long solution();	// override
	// �̶� solution�Լ��� ���� �ϳ� ���� ���� ��ģ��. �ߺ��� �ּ�ȭ ��Ű�� ���� c++�� ö���̹Ƿ� ������ �ʿ䰡 �ִ�.
	// ����ϴ� ��Ʈ���� ������ִ� �Լ��� �ϳ� �����.
};


FX2::FX2(long long n) : FX(n) { ; }

int FX2::limit() {
	return 3;
}	

//long long FX2::solution() {
//	long long i;
//
//	for (i = n + 1; diff(n, i) > 3; i++) {
//		return i;
//	}
//}

int main(void) {
	long long n = 7;
	FX fx(n);
	cout << n << " : " << fx.solution() << endl;

	FX2 fx2(n);
	cout << n << " : " << fx2.solution() << endl;
}