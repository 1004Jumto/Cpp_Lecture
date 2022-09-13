#include<iostream>
using namespace std;

int main(void) {
	double op1, op2;
	string op;

	cin >> op >> op1 >> op2;

	// 1.Using String
	if (op == "+") {
		cout << op1 + op2 << endl;
	}
	else if (op == "-"){
		cout<< op1 - op2 << endl;
	}
	else if (op == "*"){
		cout << op1 * op2 << endl;
	}
	else {
		cout << op1 / op2 << endl;
	}


	// 2.Using Char --> Able to use Switch
	char cOp;

	cin >> cOp >> op1 >> op2;

	switch (cOp) {

	case '+':
		cout << op1 + op2;
		break;
	
	case '-':
		cout << op1 - op2;
		break;
	
	case '*':
		cout << op1 * op2;
		break;
	
	case '/':
		cout << op1 / op2;
		break;

	default:
		cout << "Cannnot Operate";
	}
	

	return 0;

}