#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100000
using namespace std;

typedef long long lli;
typedef pair<lli, lli> Line;
const lli inf = 2e18;

/// Li Chao tree (min)
struct LiChaoTree{
    lli f(Line l, lli x){
        return l.first * x + l.second;
    }
    struct Node{
        int lnode, rnode;
        lli xl, xr;
        Line l;
    };
    vector<Node> nodes;
    void init(lli xmin, lli xmax){
        nodes.push_back({-1,-1,xmin,xmax,{0,1e18}});
    }

    void insert(int n, Line newline){
        lli xl = nodes[n].xl, xr = nodes[n].xr;
        lli xm = (xl + xr) >> 1;

        Line llow = nodes[n].l, lhigh = newline;
        if( f(llow, xl) >= f(lhigh,xl) ) swap(llow, lhigh);

        if( f(llow, xr) <= f(lhigh, xr) ){
            nodes[n].l = llow;
            return;
        }

        else if( f(llow, xm) <= f(lhigh, xm) ){
            nodes[n].l = llow;
            if( nodes[n].rnode == -1 ){
                nodes[n].rnode = nodes.size();
                nodes.push_back({-1,-1,xm+1,xr,{0,1e18}});
            }
            insert(nodes[n].rnode, lhigh);
        }

        // 2-b. 교점이 구간의 왼쪽 절반에 존재하는 경우
        // llow를 저장하고 왼쪽 노드로 lhigh를 이용해 재귀호출
        else{
            nodes[n].l = lhigh;
            if( nodes[n].lnode == -1 ){
                nodes[n].lnode = nodes.size();
                nodes.push_back({-1,-1,xl,xm,{0,1e18}});
            }
            insert(nodes[n].lnode, llow);
        }
    }
    lli get(int n, lli xq){
        if( n == -1 ) return 1e18;
        lli xl = nodes[n].xl, xr = nodes[n].xr;
        lli xm = (xl + xr) >> 1;

        if( xq <= xm ) return min(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
        else return min(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
    }

};

lli N, D[MAXN], P[MAXN], S[MAXN], dp[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int j = 0; j < N - 1; j++){
        cin >> D[j + 1];
        D[j + 1] += D[j];
    }
    for(int j = 0; j < N - 1; j++){
        cin >> P[j] >> S[j];
    }
    LiChaoTree tree;
    tree.init(0, 100000000);
    dp[0] = 0;
    for(int j = 1; j < N; j++){
        /// y = ax + b
        lli a = S[j - 1];
        lli b = dp[j - 1] + P[j - 1] - S[j - 1] * D[j - 1];
        tree.insert(0, {a, b});

        dp[j] = tree.get(0, D[j]);
    }
    cout << dp[N - 1];
    return 0;
}