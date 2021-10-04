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

class SCC {
public:
	int n;
	vector<vector<int>> adj;

	int dfsn = 0;
	vector<int> dfsnum;

	int sccn = 0;
	vector<int> sccnum;

	stack<int> st;

	SCC() {}

	SCC(int n) {
		this->n = n;
		adj.resize(n);
		dfsnum.resize(n);
		sccnum.resize(n, -1);
	}

	void addedge(int u, int v) {
		adj[u].push_back(v);
	}

	int dfs(int now) {
		st.push(now);
		dfsnum[now] = ++dfsn;
		int mindfsn = dfsnum[now];
		for (int nxt : adj[now]) {
			if (dfsnum[nxt] == 0) mindfsn = min(mindfsn, dfs(nxt));
			else if (sccnum[nxt] == -1) mindfsn = min(mindfsn, dfsnum[nxt]);
		}
		if (dfsnum[now] == mindfsn) {
			while (!st.empty()) {
				int top = st.top();
				st.pop();
				sccnum[top] = sccn;
				if (top == now) break;
			}
			sccn += 1;
		}
		return mindfsn;
	}

	void solve() {
		for (int i = 0; i < n; i++) {
			if (dfsnum[i] == 0) dfs(i);
		}
	}
};

class SAT {
public:
	int n;
	SCC scc;

	SAT(int n) {
		this->n = n;
		scc = SCC(2 * n);
	}

	void addedge(int u, int v) {
		scc.addedge(u, v);
	}

	bool solve() {
		scc.solve();
		for (int i = 0; i < n; i++) if (scc.sccnum[i] == scc.sccnum[n + i]) return false;
		return true;
	}

	vector<bool> answer() {
		vector<pii> v(2 * n);
		vector<bool> ret(2 * n);
		for (int i = 0; i < 2 * n; i++) v[i] = { scc.sccnum[i],i };
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < 2 * n; i++) {
			int now = v[i].second;
			if (!ret[now]) {
				ret[now] = false;
				ret[(now >= n) ? now - n : now + n] = true;
			}
		}
		return ret;
	}
};