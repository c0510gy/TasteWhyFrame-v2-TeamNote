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

class SCC{
    public:
    int n;
    int dfsn;
    int sccn;

    vector<vector<int>> adj;
    vector<int> dfsnum;
    stack<int> s;

    vector<int> sccnum;

    SCC(int n){
        adj.resize(n);
        dfsnum.resize(n,-1);
        sccnum.resize(n,-1);
        this->n=n;
        dfsn=0;
        sccn=0;
    }

    void addedge(int u, int v)
    {
        adj[u].push_back(v);
    }

    int dfs(int now)
    {
        s.push(now);
        dfsn+=1;
        dfsnum[now]=dfsn;
        int ret=dfsnum[now];

        for(int nxt : adj[now]){
            if(dfsnum[nxt]==-1) ret=min(ret,dfs(nxt));
            else if(sccnum[nxt]==-1) ret=min(ret,dfsnum[nxt]);
        }

        if(ret==dfsnum[now]){
            while(!s.empty()){
                int top=s.top();
                s.pop();
                sccnum[top]=sccn;
                if(top==now) break;
            }
            sccn+=1;
        }

        return ret;
    }

    void solve()
    {
        for(int i=0; i<n; i++){
            if(dfsnum[i]==-1) dfs(i);
        }
    }
};