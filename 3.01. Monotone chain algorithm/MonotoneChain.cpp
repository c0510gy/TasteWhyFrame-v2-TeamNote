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

class MonotoneChain {
public:
	int n;
	vector<pii> points;
	vector<pii> convex;

	MonotoneChain(vector<pii>& p) {
		points = p;
		n = points.size();
	}

	void solve() {
		sort(points.begin(), points.end());
		for (pii& p : points) {
			while (convex.size() >= 2) {
				pii& p1 = convex[convex.size() - 2];
				pii& p2 = convex.back();
				if (ccw(p1.first, p1.second, p2.first, p2.second, p.first, p.second) <= 0) convex.pop_back();
				else break;
			}
			convex.push_back(p);
		}
		int base = convex.size();
		for (int i = n - 2; i >= 0; i--) {
			pii& p = points[i];
			while (convex.size() >= base + 1) {
				pii& p1 = convex[convex.size() - 2];
				pii& p2 = convex.back();
				if (ccw(p1.first, p1.second, p2.first, p2.second, p.first, p.second) <= 0) convex.pop_back();
				else break;
			}
			convex.push_back(p);
		}
		convex.pop_back();
	}
};