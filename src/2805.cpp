#define MAXN		1'000'100
#define MAXM		2'000'000'200

#include<iostream>
#include<cstring>

using namespace std;
int sorted[MAXN];
int tree[MAXN];

void merge(int a[], int start, int end) {
	int mid = (start + end) / 2;
	int i, j, k;
	i = start; j = mid + 1; k = start;

	while (i <= mid && j <= end) {
		if (a[i] > a[j]) 
			sorted[k++] = a[i++];
		else 
			sorted[k++] = a[j++];
	}
	while (i <= mid) sorted[k++] = a[i++];
	while (j <= end) sorted[k++] = a[j++];

	for (int i = start; i <= end; i++)
		a[i] = sorted[i];
	return;
}
void mergeSort(int a[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, end);
	}
}

int main(void) {
	freopen("./input/2805.txt", "r", stdin);
	int N, M, H, sum, cnt;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> tree[i];
	cnt = 0;
	mergeSort(tree, 0, N - 1);

	cnt = 0; sum = 0; H = tree[cnt];
	while (H >= 0) {
		sum += cnt;
		if (sum >= M) break;
		while (H == tree[cnt]) cnt++;
		H--;
	}
	cout << H;
	
	return 0;
}