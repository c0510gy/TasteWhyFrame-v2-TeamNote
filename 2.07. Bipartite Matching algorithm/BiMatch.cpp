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

class BiMatch {
public:
	int n, m;
	vector<vector<int>> adj;
	vector<int> parent;
	vector<bool> visited;

	BiMatch(int n, int m) {
		this->n = n;
		this->m = m;
		adj.resize(n);
		parent.resize(m, -1);
		visited.resize(n);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
	}

	bool dfs(int now) {
		if (visited[now]) return false;
		visited[now] = true;
		for (int nxt : adj[now]) {
			if (parent[nxt] == -1 || dfs(parent[nxt])) {
				parent[nxt] = now;
				return true;
			}
		}
		return false;
	}

	int solve() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)) ret += 1;
		}
		return ret;
	}
};