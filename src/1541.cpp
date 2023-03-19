#define MAXN 55

#include<iostream>
#include<string>
#include<cstring>

using namespace std;
bool op[MAXN];
int num[MAXN];
char str[MAXN];

int main(void) {
//	freopen("./input/1541.txt", "r", stdin);
	int res = 0;
	int tmp=0;
	int cnt = 0;
	cin >> str;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			/* number */
			tmp = tmp * 10 + (str[i] - '0');
			if (i == strlen(str)-1)
				num[cnt++] = tmp;
		}
		else if (str[i] == '-' || str[i] == '+') {
			/* operator */
			num[cnt] = tmp;
			op[cnt] = str[i] == '-' ? false : true;
			cnt++;	tmp = 0;
		}
	}
	bool flag = false;
	res = num[0];
	for (int i = 0; i < cnt-1; i++) {
		if (flag) res -= num[i+1];
		else if (op[i]) res += num[i+1];
		else {
			res -= num[i+1];
			flag = true;
		}
	}

	cout << res;
	return 0;
}