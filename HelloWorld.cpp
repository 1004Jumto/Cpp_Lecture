//#include<iostream>
//#include "std_lib_facilities.h" // our course header
//
//using namespace std;
//
//int main()
//{
//	cout << "Please enter your first name (followed " << "by 'enter'):\n";
//	string first_name;
//	cin >> first_name;
//	cout << "Hello, " << first_name << '\n';
//}


#include <stdio.h>

int main(void) {
	char first_name[100];
	printf("Please enter your first name(followed ");
	printf("by 'enter'):\n");
	scanf("%s", first_name);
	printf("Hello %s \n", first_name);

}