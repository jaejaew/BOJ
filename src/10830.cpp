#define MAXN	5
#define MAXMAT	100
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

vector<vector<ll> > mat;
vector<vector<ll> > mat_powered;
vector<vector<ll> > product;
int matCnt;
int N;
ll B;

void product_matrix(const vector<vector<ll> >& A, const vector<vector<ll> >& B) {
    for (int i=0; i<product.size(); i++) 
        for (int j = 0; j < product[i].size(); j++)
            product[i][j] = 0;
    

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                product[i][j] += ((A[i][k] * B[k][j]) % 1000);
}

void copy_matrix(vector<vector<ll> >& dst, const vector<vector<ll> >& src) {
    for (int i = 0; i < dst.size(); i++)
        for (int j = 0; j < dst[0].size(); j++)
            dst[i][j] = src[i][j];
}

void power_matrix(ll p) {
	// after this function, mat_powered will contain mat^p

	if (p <= 1LL) {
        copy_matrix(mat_powered, mat);
        return;
	}

	power_matrix(p << 1);
	product_matrix(mat_powered, mat_powered);
	copy_matrix(mat_powered, product);

	if (p & 1) {
        product_matrix(mat_powered, mat);
        copy_matrix(mat_powered, product);
	}
}

void print_matrix() {
	for (int i = 0; i < mat_powered.size(); i++){
        for (int j = 0; j < mat_powered[0].size(); j++){
            cout << mat_powered[i][j] << ' ';
        }
        cout << '\n';
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("../input.txt", "r", stdin);

	cin >> N;
	cin >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
		}
	}

        power_matrix(B);
        print_matrix();
}