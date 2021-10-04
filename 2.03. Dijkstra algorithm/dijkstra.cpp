#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Dijkstra{
private:
    struct strt{
        int v, c;
        bool operator<(const strt& s)const{
            return c < s.c;
        }
        bool operator>(const strt& s)const{
            return c > s.c;
        }
    };
    vector<vector<strt>> G;
    vector<int> dist;
    int size;
public:
    Dijkstra(int size){
        this->size = size;
        G.resize(size);
        dist.resize(size, 0);
    }
    void add_edge(int v, int u, int c){
        G[v].push_back({u, c});
    }
    void run(int sv){
        priority_queue<strt, vector<strt>, greater<strt>> pq;
        for(int j = 0; j < size; j++)
            dist[j] = -1;
        pq.push({sv, 0});
        dist[sv] = 0;
        while(!pq.empty()){
            strt t = pq.top(); pq.pop();
            if(t.v != sv && dist[t.v] < t.c)
                continue;
            for(int j = 0; j < G[t.v].size(); j++){
                strt u = G[t.v][j];
                if(dist[u.v] == -1 || dist[u.v] > dist[t.v] + u.c){
                    dist[u.v] = dist[t.v] + u.c;
                    pq.push({u.v, dist[u.v]});
                }
            }
        }
    }
    int get_dist(int v){
        return dist[v];
    }
};

int main(){
    Dijkstra* dijk = new Dijkstra(10);
    for(int j = 0; j < 10 - 1; j++){
        dijk->add_edge(j, j + 1, 1);
    }
    dijk->run(1);
    for(int j = 0; j < 10; j++){
        cout << dijk->get_dist(j) << endl;
    }
    delete dijk;
    return 0;
}