#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>

using namespace std;
using pii=pair<int,int>;
using ll=long long;

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int uf_find(int a)
    {
        if(parent[a]==a) return a;
        return parent[a]=uf_find(parent[a]);
    }

    void uf_union(int a, int b)
    {
        int ap=uf_find(a),bp=uf_find(b);
        if(ap==bp) return;
        if(rank[ap]>rank[bp]) swap(ap,bp);
        parent[ap]=bp;
        if(rank[ap]==rank[bp]) rank[bp]+=1;
    }
};