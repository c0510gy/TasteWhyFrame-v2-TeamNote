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
#include <list>
#include <ctime>
#include <complex>

using namespace std;
using pii=pair<int,int>;
using ll=long long;

class AhoCorasick{
    public:
    struct Trie{
        vector<Trie*> nxt;
        Trie *fail;
        bool end;
        Trie(){
            nxt.resize(26,NULL);
            fail=NULL;
            end=false;
        }
    };

    Trie *root;
    AhoCorasick(){
        root=new Trie();
    }

    void addpattern(string pattern){
        Trie *now=root;
        for(char ch : pattern){
            if(now->nxt[ch-'a']==NULL) now->nxt[ch-'a']=new Trie();
            now=now->nxt[ch-'a'];
        }
        now->end=true;
    }

    void makefail(){
        queue<Trie*> q;
        q.push(root);
        while(!q.empty()){
            Trie* now=q.front();
            q.pop();
            for(int i=0; i<26; i++){
                if(now->nxt[i]==NULL) continue;
                if(now==root) now->nxt[i]->fail=root;
                else{
                    Trie *j=now->fail;
                    while(j!=root && j->nxt[i]==NULL) j=j->fail;
                    if(j->nxt[i]!=NULL) now->nxt[i]->fail=j->nxt[i];
                    else now->nxt[i]->fail=root;
                    if(now->nxt[i]->fail->end) now->nxt[i]->end=true;
                }
                q.push(now->nxt[i]);
            }
        }
    }

    bool solve(string target){
        Trie *now=root;
        for(char ch : target){
            while(now!=root && now->nxt[ch-'a']==NULL) now=now->fail;
            if(now->nxt[ch-'a']!=NULL){
                if(now->nxt[ch-'a']->end) return true;
                now=now->nxt[ch-'a'];
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    AhoCorasick aho=AhoCorasick();
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        aho.addpattern(s);
    }
    aho.makefail();
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(aho.solve(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
