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

class HopcroftKarp {
public:
	int n, m;
	vector<vector<int>> adj;
	vector<int> parent;
	vector<bool> visited;
	vector<int> lv;

	HopcroftKarp(int n, int m) {
		this->n = n;
		this->m = m;
		adj.resize(n);
		parent.resize(m, -1);
		visited.resize(n);
		lv.resize(n);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
	}

	void bfs() {
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (visited[i]) lv[i] = -1;
			else {
				lv[i] = 1;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int nxt : adj[now]) {
				if (parent[nxt] != -1 && lv[parent[nxt]] == -1) {
					lv[parent[nxt]] = lv[now] + 1;
					q.push(parent[nxt]);
				}
			}
		}
	}

	bool dfs(int now) {
		for (int nxt : adj[now]) {
			if (parent[nxt] == -1 || (lv[now] + 1 == lv[parent[nxt]] && dfs(parent[nxt]))) {
				visited[now] = true;
				parent[nxt] = now;
				return true;
			}
		}
		return false;
	}

	int solve() {
		int ret = 0;
		while (true) {
			bfs();
			int match = 0;
			for (int i = 0; i < n; i++) {
				if (!visited[i] && dfs(i)) match += 1;
			}
			if (match == 0) break;
			ret += match;
		}
		return ret;
	}
};