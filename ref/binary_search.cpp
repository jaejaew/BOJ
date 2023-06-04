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
/* l, r의 범위를 조정할 때 열린 구간인지, 닫힌 구간인지
 * 고려하면 쉽게 1을 어디에 더하거나 빼야 하는지 알 수 있다.
 
 * first true에 f(m)이 true라면 m 기준 오른쪽 구간은 모두 true
 * 곧 r을 왼쪽으로 당겨야 하는데, r은 열린 구간이니 그대로 당겨오면 된다.
 * last true에서 f(m)이 true라면 m 기준 왼쪽 구간은 모두 true
 * 곧, l을 오른쪽으로 당겨야 하는데, l은 열린 구간이니 그대로 당겨오면 된다.
 * 
 * 두 상황에서 m은 모두 닫힌 구간을 base로 구한다.
 */
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
        int m = r - (r - l) >> 1;
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
