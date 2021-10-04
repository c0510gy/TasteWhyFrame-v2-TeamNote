#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 500000
using namespace std;
string str;
int SA[MAXN], tG[MAXN], G[MAXN + 1], T, LCP[MAXN];
bool comp(int a, int b){
    if(G[a] == G[b])
        return G[a + T] < G[b + T];
    return G[a] < G[b];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    /// suffix array
    G[str.size()] = -1;
    for(int j = 0; j < str.size(); j++){
        SA[j] = j;
        G[j] = str[j] - 'a';
    }
    T = 1;
    while(T <= str.size()){
        sort(SA, SA + str.size(), comp);
        tG[0] = 0;
        for(int j = 0; j < str.size() - 1; j++)
            tG[j + 1] = tG[j] + comp(SA[j], SA[j + 1]);
        for(int j = 0; j < str.size(); j++)
            G[SA[j]] = tG[j];
        if(tG[str.size() - 1] == str.size() - 1)
            break;
        T <<= 1;
    }
    return 0;
}
