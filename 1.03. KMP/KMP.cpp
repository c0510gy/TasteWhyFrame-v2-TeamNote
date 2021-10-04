#include <iostream>
#include <vector>
#include <string>
#define MAXN 1000000
using namespace std;

string T, P;
int pi[MAXN];
vector<int> ans;
void get_pi(){
    for(int j = 1, i = 0; j < P.size(); j++){
        while(i > 0 && P[j] != P[i])
            i = pi[i - 1];
        if(P[j] == P[i])
            pi[j] = ++i;
    }
}
void kmp(){
    for(int j = 0, i = 0; j < T.size(); j++){
        while(i > 0 && T[j] != P[i])
            i = pi[i - 1];
        if(T[j] == P[i]){
            if(i == P.size() - 1){
                ans.push_back(j - P.size() + 1);
                i = pi[i];
            }else
                i++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, T);
    getline(cin, P);
    get_pi();
    kmp();
    cout << ans.size() << "\n";
    for(int j = 0; j < ans.size(); j++)
        cout << ans[j] + 1 << " ";
    return 0;
}