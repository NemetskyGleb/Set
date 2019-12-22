#include "set.h"
#include <iostream>
#include <set>

int main(){
	using namespace std;
	Set A("bvf31");
	Set B("bvf3");
	(A != B) ? cout << "true" << endl : cout << "false" << endl;
	cin.get();
	return 0;
}