#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <complex>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	ll c = (ll)(x2 - x1) * (ll)(y3 - y1) - (ll)(x3 - x1) * (ll)(y2 - y1);
	if (c > 0) return 1;
	else if (c < 0) return -1;
	return 0;
}