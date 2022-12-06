#include<iostream>
#include<vector>

using namespace std;

class Matrix
{
public:
	Matrix(vector<vector<int>> v);
	Matrix operator*(Matrix& m);
	friend ostream& operator<<(ostream& os, const Matrix& m);

private:
	vector<vector<int>> values;
	int getInnerProduct(Matrix& m, int i, int j);

protected:

};

Matrix::Matrix(vector<vector<int>> v)
{
	values = v;
}

Matrix Matrix::operator*(Matrix& m)
{
	vector<vector<int>> v;
	
	for (int i = 0; i < values.size(); i++) {
		vector<int> row;
		for (int j = 0; j < m.values[0].size(); j++) {
			row.push_back(getInnerProduct(m, i, j));
		}
		v.push_back(row);
	}

	return Matrix(v);
}

int Matrix::getInnerProduct(Matrix& m, int i, int j)
{
	int sum = 0;
	for (int k = 0; k < values[0].size(); k++) {
		sum += values[i][k] * m.values[k][j];
	}

	return sum;
}

ostream& operator<<(ostream& os, const Matrix& m) {
	for (int i = 0; i < m.values.size(); i++) {
		for (int j = 0; j < m.values[0].size(); j++) {
			os << m.values[i][j] << ' ';
		}
		os << endl;
	}
	return os;
}

int main(void) {
	vector<vector<int>> v, w;
	vector<int> row;
	
	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	v.push_back(row);
	row.clear();

	row.push_back(4);
	row.push_back(5);
	row.push_back(6);
	v.push_back(row);
	row.clear();

	row.push_back(1);
	row.push_back(2);
	w.push_back(row);
	row.clear();

	row.push_back(3);
	row.push_back(4);
	w.push_back(row);
	row.clear();

	row.push_back(5);
	row.push_back(6);
	w.push_back(row);
	row.clear();

	Matrix arr1(v);
	Matrix arr2(w);
	Matrix res = arr1 * arr2;
	cout << res << endl;

	return 0;
}