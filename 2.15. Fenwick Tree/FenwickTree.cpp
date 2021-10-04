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

class FenwickTree {
public:
	int n;
	vector<int> ftree;

	FenwickTree(int n) {
		this->n = n;
		ftree.resize(n + 1);
	}

	void update(int pos, int value) {
		while (pos <= n) {
			ftree[pos] += value;
			pos += pos & -pos;
		}
	}

	int query(int pos) {
		int ret = 0;
		while (pos >= 1) {
			ret += ftree[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};