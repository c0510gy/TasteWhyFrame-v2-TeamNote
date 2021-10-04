#include <iostream>
#include <vector>
using namespace std;

class BellmanFord{
private:
    struct strt{
        int v, c;
    };
    int size;
    vector<int> dist;
    vector<bool> visit;
    vector<vector<strt>> G;
    bool edge_raxation(){
        bool ret = false;
        for(int v = 0; v < size; v++){
            if(!visit[v])
                continue;
            for(int i = 0; i < G[v].size(); i++){
                strt u = G[v][i];
                if(!visit[u.v] || dist[u.v] > dist[v] + u.c){ 
                    visit[u.v] = true;
                    dist[u.v] = dist[v] + u.c;
                    ret = true;
                }
            }
        }
        return ret;
    }
public:
    BellmanFord(int size){
        this->size = size;
        dist.resize(size);
        visit.resize(size);
        G.resize(size);
    }
    void add_edge(int v, int u, int c){
        G[v].push_back({u, c});
    }
    bool run(int sv){
        dist[sv] = 0;
        visit[sv] = true;
        for(int j = 0; j < size - 1; j++){
            if(!edge_raxation())
                break;
        }
        if(edge_raxation())
            return false; // 음수 사이클 존재
        return true;
    }
    int get_dist(int v){
        return dist[v];
    }
};

int main(){
    int size = 10;
    BellmanFord* bellmanford = new BellmanFord(size);
    for(int j = 0; j < size - 1; j++){
        bellmanford->add_edge(j, j + 1, -1);
    }
    bool pos = bellmanford->run(0);
    if(pos){
        for(int j = 0; j < size; j++){
            cout << bellmanford->get_dist(j) << " ";
        }
    }
    delete bellmanford;
    return 0;
}