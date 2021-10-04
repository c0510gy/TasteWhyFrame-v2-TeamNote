#include <iostream>
#include <vector>
using namespace std;

class FloydWarshall{
private:
    int size;
    vector<vector<int>> dist;
    vector<vector<bool>> check;
public:
    FloydWarshall(int size){
        this->size = size;
        dist.resize(size);
        check.resize(size);
        for(int j = 0; j < size; j++){
            dist[j].resize(size, 0);
            check[j].resize(size, false);
        }
    }
    void add_Edge(int v, int u, int c){
        dist[v][u] = c;
        check[v][u] = true;
    }
    void run(){
        for(int u = 0; u < size; u++){
            for(int s = 0; s < size; s++){
                for(int e = 0; e < size; e++){
                    if(!check[s][u] || !dist[u][e])
                        continue;
                    if(!check[s][e] || dist[s][e] > dist[s][u] + dist[u][e]){
                        check[s][e] = true;
                        dist[s][e] = dist[s][u] + dist[u][e];
                    }
                }
            }
        }
    }
    bool get_pos(int s, int e){
        return check[s][e];
    }
    int get_dist(int s, int e){
        return dist[s][e];
    }
};
int main(){
    int size = 10;
    FloydWarshall* floydwarshall = new FloydWarshall(size);
    for(int j = 0; j < size - 1; j++){
        floydwarshall->add_Edge(j, j + 1, 1);
    }
    floydwarshall->run();
    for(int s = 0; s < size; s++){
        for(int e = 0; e < size; e++){
            if(floydwarshall->get_pos(s, e))
                cout << floydwarshall->get_dist(s, e) << " ";
            else
                cout << "x ";
        }
        cout << "\n";
    }
    delete floydwarshall;
    return 0;
}