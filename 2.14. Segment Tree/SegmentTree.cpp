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

class SegmentTree {
public:
	int n;
	vector<int> segtree;

	SegmentTree(int n) {
		this->n = n;
		segtree.resize(1 << ((int)ceil(log2(n)) + 1));
	}

	void update(int ns, int ne, int p, int pos, int value) {
		if (ns > p || ne < p) return;
		segtree[pos] += value;
		if (ns >= p && ne <= p) return;
		int mid = (ns + ne) / 2;
		update(ns, mid, p, pos * 2, value);
		update(mid + 1, ne, p, pos * 2 + 1, value);
	}

	int query(int ns, int ne, int s, int e, int pos) {
		if (ns > e || ne < s) return 0;
		if (s <= ns && ne <= e) return segtree[pos];
		int mid = (ns + ne) / 2;
		return query(ns, mid, s, e, pos * 2) + query(mid + 1, ne, s, e, pos * 2 + 1);
	}
};