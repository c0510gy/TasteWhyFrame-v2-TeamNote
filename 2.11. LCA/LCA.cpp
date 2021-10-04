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

class LCA {
public:
	int n, m;
	vector<vector<int>> adj;
	vector<vector<int>> parent;
	vector<int> lv;

	LCA(int n) {
		this->n = n;
		this->m = (int)ceil(log2(n)) + 1;
		adj.resize(n);
		parent.resize(n, vector<int>(m, -1));
		lv.resize(n);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int now, int p) {
		for (int nxt : adj[now]) {
			if (nxt == p) continue;
			parent[nxt][0] = now;
			lv[nxt] = lv[now] + 1;
			dfs(nxt, now);
		}
	}

	void maketree() {
		dfs(0, -1);
	}

	void makeparent() {
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (parent[j][i - 1] != -1) parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
	}

	int solve(int a, int b) {
		for (int i = m - 1; i >= 0; i--) {
			if (lv[a] - (1 << i) >= lv[b]) a = parent[a][i];
			if (lv[b] - (1 << i) >= lv[a]) b = parent[b][i];
		}
		if (a == b) return a;
		for (int i = m - 1; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		return parent[a][0];
	}
};