#include<iostream>

using namespace std;

int main(void) {
	int weight;
	int bag5, remainder;
	int sum;
	
	cin >> weight;
	/* initialize bag5 and remainder */
	bag5 = weight / 5;
	remainder = weight - 5 * bag5;
	
	while (remainder % 3) {
		bag5--;
		remainder += 5;
		if (remainder > weight) break;
	}

	if (remainder % 3 == 0 && remainder <= weight)
		sum = remainder / 3 + bag5;	//	rem/3 = bag3
	else 
		sum = -1;

	cout << sum << endl;
}