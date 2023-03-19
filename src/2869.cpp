#include<iostream>

using namespace std;

int main(void) {
	int A, B, V;
	int day;
	/* climb A, down B, height V*/
	cin >> A >> B >> V;

	if (A >= V) day = 1;
	else {
		day = (V - A) / (A - B) + 1;
		if ((V - A) % (A - B) != 0) 
			++day;
	}
	cout << day << endl;
	return 0;
}