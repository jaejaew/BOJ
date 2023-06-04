#include <algorithm>
#include <vector>

using namespace std;

/* assume: v is sorted in ascending order */
vector<int> v;
int K;

/* std binary search */
auto x = std::lower_bound(v.begin(), v.end(), K); /* return iterator to v[i], where i is minimum, i >= K */
auto y = std::upper_bound(v.begin(), v.end(), K); /* return iterator to v[i], where i is minimum, i > K */


/* find first/last true */
const bool f(int);

int first_true(int l, int r) {
    /* [l, r) */
    while (l!=r) {
        int m = l + (r - l) >> 1;
        f(m) ? r = m : l = m + 1;
    }
    return l;
}

int last_true(int l, int r) {
    /* (l, r] */
    while (l!=r) {
        int m = l + (r - l) >> 1;
        f(m) ? l = m : r = m - 1;
    }
    return l;
}

/* parametric search */
/* f를 잘 만들어서 이분 탐색을 결정 문제에서 사용할 수 있다. 
 * 최적화: f(x)=True가 되는 x의 최대/최소를 구하라
 * 결정: 어떤 x에서 f(x)가 True?
 * 
 * (x1<x2) && (f(x2)==true) -> f(x1)==true
 * 위 조건을 만족하는 f를 설계할 수 있으면 x를 binary search를 이용해 구할 수 있다.
 */
