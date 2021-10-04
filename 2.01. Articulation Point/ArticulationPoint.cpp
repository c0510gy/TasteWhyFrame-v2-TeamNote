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

class ArticulationPoint {
public:
	int n;
	vector<vector<int>> adj;
	vector<int> dfsnum;
	int dfsn;
	vector<bool> answer;

	ArticulationPoint(int n) {
		this->n = n;
		dfsn = 0;
		dfsnum.resize(n);
		adj.resize(n);
		answer.resize(n);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int dfs(int now, bool root) {
		dfsnum[now] = ++dfsn;
		int mindfsn = dfsnum[now];
		int cnt = 0;
		for (int nxt : adj[now]) {
			if (dfsnum[nxt] == 0) {
				cnt += 1;
				int res = dfs(nxt, false);
				if (!root && res >= dfsnum[now]) answer[now] = true;
				mindfsn = min(mindfsn, res);
			}
			else mindfsn = min(mindfsn, dfsnum[nxt]);
		}
		if (root && cnt >= 2) answer[now] = true;
		return mindfsn;
	}

	void solve() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (dfsnum[i] == 0) dfs(i, true);
		}
	}
};