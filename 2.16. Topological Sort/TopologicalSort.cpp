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

class TopologicalSort {
public:
	int n;
	vector<vector<int>> adj;
	vector<int> indegree;

	TopologicalSort(int n) {
		this->n = n;
		adj.resize(n);
		indegree.resize(n);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
		indegree[v] += 1;
	}

	vector<int> solve() {
		vector<int> ret;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			ret.push_back(now);
			for (int nxt : adj[now]) {
				indegree[nxt] -= 1;
				if (indegree[nxt] == 0) q.push(nxt);
			}
		}
		return ret;
	}
};