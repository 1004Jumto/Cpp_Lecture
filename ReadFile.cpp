#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Reading
{
public:
	Reading(int hour, double temp);
	~Reading();
	int hour;
	double temp;
private:

};

Reading::Reading(int hour, double temp)
{
	this->hour = hour;
	this->temp = temp;
}

Reading::~Reading()
{
}

void fill_vector(istream& ist, vector<int>& v, char terminator)
{ 
	// read integers from ist into v until we reach eof() or terminator
	for (int i; ist >> i; ) {       // read until ¡°some failure¡±
		v.push_back(i);				// store in v
	}
	if (ist.eof()) return;              // fine: we found the end of file
	if (ist.bad()) cout << "ist is bad" << endl; // stream corrupted; let¡¯s get out of here!

	if (ist.fail()) {     // clean up the mess as best we can and report the problem
		ist.clear();      // clear stream state, so that we can look for terminator
		char c;
		ist >> c;         // read a character, hopefully terminator

		if (c != terminator) {            // unexpected character
			ist.unget();                  // put that character back
			ist.clear(ios_base::failbit); // set the state back to fail()
		}
	}
}

int main(void) {
	vector<Reading> temps;
	ifstream ist("E:/sample.txt");
	int hour;
	double temp;
	
	while (ist >> hour >> temp) {
		if (hour < 0 || 23 < hour) {
			cout << "hour out of " << temp << endl;
		}
		cout << hour << ", " << temp << endl;
		temps.push_back(Reading{ hour, temp });
	}

	vector<int> temp2;
	ifstream ist2( "E:/sample2.txt" );
	fill_vector(ist2, temp2, 'q');

	//ist.exceptions(ist.exceptions() | ios_base::failbit);
	try {
		fill_vector(ist2, temp2, 'q');
	} catch (ios_base::failure &e) {
		cout << "exception handling" << endl;
	}
	cout << ist2.fail() << endl;		// 0ÀÌ ÂïÈ÷¸é fail¾Æ´Ô
	cout << ist2.eof() << endl;		

}