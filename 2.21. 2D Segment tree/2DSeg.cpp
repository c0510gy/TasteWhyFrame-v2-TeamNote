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
#define MAX 1030

using namespace std;
using pii = pair<int, int>;
using ll = long long;

class SegTree{
public:
	int tree[MAX*2];
	int leaf;
	void init(int n) {for(leaf=1;leaf<n;leaf<<=1);}
	void update(int x, int v){
		x += leaf; tree[x] = v;
		while(x >>= 1){
			tree[x] = tree[x << 1] + tree[x << 1 | 1];
		}
	}
	int query(int lo, int hi){
		lo += leaf, hi += leaf;
		int ans = 0;
		while(lo < hi){
			if(lo & 1) ans += tree[lo++];
			if(!(hi & 1)) ans += tree[hi--];
			lo >>= 1; hi >>= 1;
		}
		if(lo == hi) ans += tree[lo];
		return ans;
	}
};

class seg2d{
public:
    SegTree tree[MAX*2];
    int n, leaf;

    seg2d(int n){
        for(leaf=1;leaf<n;leaf<<=1);
        for(int i=0;i<=leaf*2;i++) tree[i].init(n);
    }

    void update(int x, int y, int v) {
        x += leaf; tree[x].update(y, v);
        while(x >>= 1){
            int t1 = tree[x << 1].query(y, y);
            int t2 = tree[x << 1 | 1].query(y, y);
            tree[x].update(y, t1+t2);
        }
    }

    int query(int x1, int x2, int y1, int y2){
        x1 += leaf, x2 += leaf;
        int ans = 0;
        while(x1 < x2){
            if(x1 & 1) ans += tree[x1++].query(y1, y2);
            if(!(x2 & 1)) ans += tree[x2--].query(y1, y2);
            x1 >>= 1, x2 >>= 1;
        }
        if(x1 == x2) ans += tree[x1].query(y1, y2);
        return ans;
    }
};