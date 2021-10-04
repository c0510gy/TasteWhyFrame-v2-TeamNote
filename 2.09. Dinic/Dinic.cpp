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

class Dinic {
public:
	struct EDGE {
		int dst;
		int capacity;
		int flow;
		EDGE* r;
		EDGE(int dst, int capacity) {
			this->dst = dst;
			this->capacity = capacity;
			this->flow = 0;
			this->r = NULL;
		}
	};

	int n;
	vector<vector<EDGE*>> adj;
	vector<int> work;
	vector<int> lv;

	Dinic(int n) {
		this->n = n;
		adj.resize(n);
		lv.resize(n);
		work.resize(n);
	}

	void addedge(int u, int v, int capacity) {
		EDGE* e1 = new EDGE(v, capacity);
		EDGE* e2 = new EDGE(u, 0);
		e1->r = e2;
		e2->r = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	bool bfs() {
		fill(lv.begin(), lv.end(), -1);
		queue<int> q;
		q.push(0);
		lv[0] = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto& nxt : adj[now]) {
				if (lv[nxt->dst] == -1 && nxt->capacity - nxt->flow > 0) {
					lv[nxt->dst] = lv[now] + 1;
					q.push(nxt->dst);
				}
			}
		}
		return lv[n - 1] != -1;
	}

	int dfs(int now, int minflow) {
		if (now == n - 1) return minflow;
		for (int& i = work[now]; i < adj[now].size(); i++) {
			if (lv[adj[now][i]->dst] == lv[now] + 1 && adj[now][i]->capacity - adj[now][i]->flow > 0) {
				int flow = dfs(adj[now][i]->dst, min(minflow, adj[now][i]->capacity - adj[now][i]->flow));
				if (flow > 0) {
					adj[now][i]->flow += minflow;
					adj[now][i]->r->flow -= minflow;
					return flow;
				}
			}
		}
		return 0;
	}

	int solve() {
		int ret = 0;
		while (bfs()) {
			fill(work.begin(), work.end(), 0);
			while (true) {
				int flow = dfs(0, INT_MAX);
				if (flow == 0) break;
				ret += flow;
			}
		}
		return ret;
	}
};