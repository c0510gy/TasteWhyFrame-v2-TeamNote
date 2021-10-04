#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SPFA{
private:
    struct strt{
        int v, c;
    };
    int size;
    vector<int> dist;
    vector<bool> visit;
    vector<vector<strt>> G;
public:
    SPFA(int size){
        this->size = size;
        dist.resize(size);
        visit.resize(size);
        G.resize(size);
    }
    void add_Edge(int v, int u, int c){
        G[v].push_back({u, c});
    }
    void run(int sv){
        for(int j = 0; j < size; j++)
            visit[j] = false;
        dist[sv] = 0;
        queue<int> q;
        q.push(sv);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(int j = 0; j < G[v].size(); j++){
                strt u = G[v][j];
                if(!visit[u.v] || dist[u.v] > dist[v] + u.c){
                    dist[u.v] = dist[v] + u.c;
                    visit[u.v] = true;
                    q.push(u.v);
                }
            }
        }
    }
    int get_dist(int v){
        return dist[v];
    }
};
int main(){
    int size = 10;
    SPFA* spfa = new SPFA(size);
    for(int j = 0; j < size - 1; j++){
        spfa->add_Edge(j, j + 1, 1);
    }
    spfa->run(0);
    for(int j = 0; j < size; j++){
        cout << spfa->get_dist(j) << " ";
    }
    delete spfa;
    return 0;
}