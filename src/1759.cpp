#define MAXN	16

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int L, C;
char en[MAXN];
char ans[MAXN];
void dfs(int lv) {
	if (lv == L) {
		int onum = 0;
		for (char& c : ans)
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				onum++;
		if (onum < 1) return;
		if (strlen(ans) - onum < 2) return;

		cout << ans << '\n';
		return;
	}

	for (int i = 0; i < C; i++) {
		if (lv == 0 || ans[lv - 1] < en[i]) {
			ans[lv] = en[i];
			dfs(lv + 1);
			ans[lv] = '\0';
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/1759.txt", "r", stdin);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> en[i];

	for (int i = 0; i < C; i++)
		for (int j = i + 1; j < C; j++)
			if (en[i] > en[j]) swap(en[i], en[j]);

	dfs(0);
}