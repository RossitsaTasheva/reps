//============================================================================
// Name        : ~vector_sort_max_min.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

/*������3.
 ��������, ����� ������� ������ �� n ���������� ����� �
 - ������� ���������� ��
 - ������� ����������� � ���������� �� �������
 -������ ���� �� �������� ����� ��� �������
 - ������� ������ ������ ����� �� �������*/
bool prosto(int n) {
	if (n == 1)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
void write(vector<int> v) {
	cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n\n";
}
void read(vector<int> &v, int n) {
	srand(time(0));
	for (int i = 1; i <= n; i++) {
		int p = rand() % 100 + 1;
		v.push_back(p);
	}
}
int main() {
	cout << "n=";
	int n;
	cin >> n;
	vector<int> v;
	//��������� �� ������� ��� �������� �����
	read(v, n);
	write(v);
	vector<int>::iterator it, it1 = v.end();
	// ���������
	sort(v.begin(), v.end());
	write(v);
	//max �������
	cout << "max= " << *max_element(v.begin(), v.end()) << endl;
	//min �������
	cout << "min= " << *min_element(v.begin(), v.end()) << endl;
	//�������� �� ���� �� �������� �����
	cout << "Broi prosti chisla: " << count_if(v.begin(), v.end(), prosto)
			<< endl;
	//��������� �� �������� ����� �� �������
	it = remove_if(v.begin(), v.end(), prosto);
	v.erase(it, v.end());
	write(v);
	return 0;
}
