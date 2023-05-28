#include <vector>

using namespace std;

/* number of divisors among the range [1, N] */
void getNumDivs(int N, vector<int>& numDivs) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N / i; j++)
            numDivs[i * j]++;
}

/* all divisors of a specific number N */
void getAllDivs_O_N(int N, vector<int>& divs) {
    for (int i = 1; i <= N; i++)
        if (N%i == 0)
            divs.push_back(i);
}

/* all divisors of a specific number N */
void getAllDivs_O_sqrtN(int N, vector<int>& divs) {
    for (int i = 1; i <= N; i++) {
        if (N%i == 0) {
            divs.push_back(i);
            if (i*i < N)
                divs.push_back(N / i);
        }
    }
}