#include <iostream>
#include <vector>
#include <algorithm>
#define MAXV 100000
using namespace std;

struct strt{
    int a, b;
    bool operator<(const strt& s)const{
        if(a == s.a)
            return b < s.b;
        return a < s.a;
    }
    bool operator>(const strt& s)const{
        if(a == s.a)
            return b > s.b;
        return a > s.a;
    }
};
int V, E, ord[MAXV + 1], d, K;
vector<int> G[MAXV + 1];
vector<strt> ans;
int dfs(int v, int parv){
    ord[v] = ++d;
    int ret = ord[v];
    for(int j = 0, cnt = G[v].size(); j < cnt; j++){
        if(G[v][j] == parv)
            continue;
        if(ord[G[v][j]]){
            ret = min(ret, ord[G[v][j]]);
        }else{
            int mord = dfs(G[v][j], v);
            ret = min(ret, mord);
            if(ord[v] < mord){
                ans.push_back({min(v, G[v][j]), max(v, G[v][j])});
                K++;
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for(int j = 0; j < E; j++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int j = 1; j <= V; j++)
        if(!ord[j])
            dfs(j, 0);
    sort(ans.begin(), ans.end());
    cout << K << "\n";
    for(int j = 0; j < K; j++)
        cout << ans[j].a << " " << ans[j].b << "\n";
    return 0;
}