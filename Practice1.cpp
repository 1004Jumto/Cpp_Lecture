#include<iostream>
using namespace std;

int main(void) {
	int val1, val2;		// 선언과 정의를 한번에 한 경우
						// extern : 선언만 하게 해줌
	extern int K;		// (전역변수)K 라는 변수가 다른 파일 어딘가에 정의되어있으니 에러를 띄우지 말아라는 뜻. 메모리가 잡히지 않은 상태

	cout << "Please enter two integers : ";
	cin >> val1 >> val2;

	int smallest, largest, sum, difference, mul, ratio;	// 초기화를 하는 습관이 좋음
	
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

	cout << "smallest = " << smallest << "\n";		// \n보다는 endl을 권장하는 이유: machine defendency를 피할 수 있는 좋은 습관
	cout << "largest = " << largest << "\n";
	cout << "sum = " << sum << "\n";
	//cout << "sum = " << largest + smallest << "\n";	// 연산자 우선순위는 <<보다 +가 더 우선됨. 헷갈린다면 괄호로 명시
	//cout << "sum = " << (largest + smallest) << "\n";	
	cout << "difference = " << difference << "\n";
	cout << "mul = " << mul << "\n";
	cout << "ratio = " << ratio << "\n";
	
	
	return 0;

}