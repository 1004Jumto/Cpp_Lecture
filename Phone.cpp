#include<iostream>

using namespace std;

class PhoneNumber
{
public:
	PhoneNumber(string num);
	~PhoneNumber();
	string masking(int k) const;
	friend ostream& operator<<(ostream& os, const PhoneNumber& p);	
private:
	string number;
};

PhoneNumber::PhoneNumber(string num)
{
	number = num;
}

PhoneNumber::~PhoneNumber()
{
}

string PhoneNumber::masking(int k) const{
	string masked = "";
	for (int i = 0; i < number.length(); i++) {
		if (i < k) {
			masked += "*";
		}
		else {
			masked += number[i];
		}
	}
	return masked;
}

ostream& operator<<(ostream& os, const PhoneNumber& p) {
	string masked = p.masking(7); // const로 묶었기 때문에 p에 대한 변경을 허용하지 않는다
								  // 따라서 p가 변할 수도 있는 멤버함수를 호출하려면 멤버함수도 const선언된 함수여야 함
	os << masked;
	return os;
}

int main(void) {
	PhoneNumber number("01073489592");
	cout << number.masking(7);
	return 0;
}