#include "set.h"
#include <iostream>

int main(){
	using namespace std;
	Set A;
	Set B("dcba321");
	cout << "B = " << B;
	B.Print();
	A = A + '4';
	cout << "A = A + 4 = " << A;
	A += B;
	cout << "A += B = " << A;
	A -= '2';
	cout << "A -= 2 = " << A;
	Set C(A * B);
	cout << "C = A * B = " << C;
	cout << "A == B ?" << endl;
	(A == B) ? cout << "true" << endl : cout << "false" << endl;
	Set D;
	cin >> D;
	cout << "D = " << D;
	cin.get();
	return 0;
}