#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {

	// First Way
	// Using Array
	int arr[3];

	cout << " Please Enter three integers: ";

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 3);

	cout << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;


	
	// Second Way
	// Considering all case
	int n1, n2, n3; 
	int first, second, third;
	cout << " Please Enter three integers: ";

	cin >> n1 >> n2 >> n3;

	if (n1 > n2 && n1 > n3) {
		if (n2 > n3) {
			second = n2;
			third = n3;
		}
		else {
			second = n3;
			third = n2;
		}
		first = n1;
	}
	else if (n2 > n3 && n2 > n1) {
		if (n1 > n3) {
			second = n1;
			third = n3;
		}
		else {
			second = n3;
			third = n1;
		}
		first = n2;
	}
	else {
		if (n1 > n2) {
			second = n1;
			third = n2;
		}
		else {
			second = n2;
			third = n1;
		}
		first = n3;
	}

	cout << first << ", " << second << ", " << third << endl;

	return 0;
}