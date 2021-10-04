#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MCMF{
private:
    struct strt{
        int v, c;
    };
    int size;
    vector<vector<strt>> G;
    vector<vector<int>> C, F;
public:
    MCMF(int size){
        this->size = size;
        G.resize(size);
        C.resize(size);
        F.resize(size);
        for(int j = 0; j < size; j++){
            C[j].resize(size, 0);
            F[j].resize(size, 0);
        }
    }
    void addEdge(int v, int u, int cost, int cap){
        G[v].push_back({u, cost});
        G[u].push_back({v, -cost});
        C[v][u] = cap;
        F[v][u] = 0;
    }
    pair<int, int> run(int S, int T){
        int mincost = 0, maxflow = 0;

        while(true){
            queue<int> q;
            vector<int> dist, pre;
            vector<bool> visit;
            dist.resize(size, 0);
            pre.resize(size, -1);
            visit.resize(size, false);
            visit[S] = true;
            q.push(S);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                
                for(int j = 0; j < G[v].size(); j++){
                    strt u = G[v][j];
                    if((!visit[u.v] || dist[u.v] > dist[v] + u.c)
                    && C[v][u.v] - F[v][u.v] > 0){
                        dist[u.v] = dist[v] + u.c;
                        visit[u.v] = true;
                        pre[u.v] = v;
                    }
                }
            }
            if(!visit[T])
                break;
            
            bool f = false;
            int minf = 0;
            for(int v = T; v != S; v = pre[v]){
                int u = pre[v];
                if(!f || minf > C[u][v] - F[u][v]){
                    minf = C[u][v] - F[u][v];
                    f = true;
                }
            }
            mincost += minf * dist[T];
            for(int v = T; v != S; v = pre[v]){
                int u = pre[v];
                F[u][v] += minf;
                F[v][u] -= minf;
            }
        }
        for(int j = 0; j < G[T].size(); j++){
            maxflow += F[G[T][j].v][T];
        }
        return {mincost, maxflow};
    }
};
int main(){
    int size = 10;
    MCMF* mcmf = new MCMF(size);
    delete mcmf;
    return 0;
}