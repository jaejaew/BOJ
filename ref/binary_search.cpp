#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int K;

/* assume: v is sorted in ascending order */
auto x = lower_bound(v.begin(), v.end(), K); /* return iterator to v[i], where i is minimum, i >= K */
auto y = upper_bound(v.begin(), v.end(), K); /* return iterator to v[i], where i is minimum, i > K */

