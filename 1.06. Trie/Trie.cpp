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

struct Trie{
    vector<Trie*> nxt;
    bool end;
    Trie(){
        nxt.resize(26,NULL);
        end=false;
    }
};

Trie *root;

void addpattern(string pattern){
    Trie *now=root;
    for(char ch : pattern){
        if(now->nxt[ch-'a']==NULL) now->nxt[ch-'a']=new Trie();
        now=now->nxt[ch-'a'];
    }
}