
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

typedef long long ll;

ll _min, _max;
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/1016.txt", "r", stdin);

	cin >> _min >> _max;
	int res = _max - _min + 1;
	ll s = (ll)sqrt(_min);
	ll e = (ll)sqrt(_max);
	cout << res - (e - s + 1) << '\n';
}