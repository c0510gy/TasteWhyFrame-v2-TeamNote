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

template<class T>
class SegmentTreeWithLazy {
public:
	int n;
	vector<T> segtree;
	vector<T> lazy;

	SegmentTreeWithLazy(int n) {
		this->n = n;
		int siz = 1 << ((int)ceil(log2(n)) + 1);
		segtree.resize(siz);
		lazy.resize(siz);
	}

	void lazypropagation(int ns, int ne, int pos) {
		if (lazy[pos] != 0) {
			segtree[pos] += (ne - ns + 1) * lazy[pos];
			if (ns != ne) {
				lazy[pos * 2] += lazy[pos];
				lazy[pos * 2 + 1] += lazy[pos];
			}
			lazy[pos] = 0;
		}
	}

	void update(int ns, int ne, int s, int e, int pos, T value) {
		lazypropagation(ns, ne, pos);
		if (ne<s || ns>e) return;
		if (s <= ns && ne <= e) {
			lazy[pos] += value;
			lazypropagation(ns, ne, pos);
			return;
		}
		int mid = (ns + ne) / 2;
		update(ns, mid, s, e, pos * 2, value);
		update(mid + 1, ne, s, e, pos * 2 + 1, value);
		segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
	}

	T query(int ns, int ne, int s, int e, int pos) {
		lazypropagation(ns, ne, pos);
		if (ne<s || ns>e) return 0;
		if (s <= ns && ne <= e) return segtree[pos];
		int mid = (ns + ne) / 2;
		return query(ns, mid, s, e, pos * 2) + query(mid + 1, ne, s, e, pos * 2 + 1);
	}
};
