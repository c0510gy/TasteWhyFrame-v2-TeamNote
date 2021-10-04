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

using namespace std;
using pii=pair<int,int>;
using ll=long long;

class SALCP{
    public:
    string str;
    int n;

    vector<int> rnk1,rnk2;
    vector<int> idx1,idx2;
    vector<int> cnt;

    vector<int> sa;
    vector<int> lcp;

    SALCP(string str)
    {
        this->n=str.length();
        this->str=str;
        rnk1.resize(n);
        rnk2.resize(n);
        idx1.resize(n);
        idx2.resize(n);
        cnt.resize(max(27,n+1));
        sa.resize(n);
        lcp.resize(n);
    }

    void getsa()
    {
        for(int i=0; i<n; i++) rnk1[i]=str[i]-'a'+1;
        if(n==1) rnk1[0]=1;
        for(int i=1; i<n; i<<=1){
            fill(cnt.begin(),cnt.end(),0);
            for(int j=0; j<n; j++) cnt[(j+i>=n)?0:rnk1[j+i]]+=1;
            for(int j=1; j<cnt.size(); j++) cnt[j]+=cnt[j-1];
            for(int j=n-1; j>=0; j--) idx1[--cnt[(j+i>=n)?0:rnk1[j+i]]]=j;
            fill(cnt.begin(),cnt.end(),0);
            for(int j=0; j<n; j++) cnt[rnk1[j]]+=1;
            for(int j=1; j<cnt.size(); j++) cnt[j]+=cnt[j-1];
            for(int j=n-1; j>=0; j--) idx2[--cnt[rnk1[idx1[j]]]]=idx1[j];
            rnk2[idx2[0]]=1;
            for(int j=1; j<n; j++){
                if(rnk1[idx2[j-1]]==rnk1[idx2[j]] && rnk1[idx2[j-1]+i]==rnk1[idx2[j]+i]) rnk2[idx2[j]]=rnk2[idx2[j-1]];
                else rnk2[idx2[j]]=rnk2[idx2[j-1]]+1;
            }
            rnk1=rnk2;
        }
        for(int i=0; i<n; i++) sa[i]=idx2[i]+1;
    }

    void getlcp()
    {
        int common=0;
        for(int i=0; i<n; i++){
            if(rnk1[i]==1) lcp[rnk1[i]-1]=-1;
            else{
                int prv=sa[rnk1[i]-2]-1;
                while(i+common<n && prv+common<n && str[i+common]==str[prv+common]) common+=1;
                lcp[rnk1[i]-1]=common;
                if(common>0) common-=1;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    string s;
    cin>>s;
    SALCP salcp=SALCP(s);
    salcp.getsa();
    salcp.getlcp();
    for(int a : salcp.sa) cout<<a<<" ";
    cout<<"\n";
    for(int a : salcp.lcp){
        if(a==-1) cout<<"x ";
        else cout<<a<<" ";
    }
}