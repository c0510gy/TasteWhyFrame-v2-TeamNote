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

class Manacher{
    public:
    int n;
    string str;
    vector<int> dp;

    Manacher(string s){
        str.push_back(s[0]);
        for(int i=1; i<s.length(); i++){
            str.push_back('#');
            str.push_back(s[i]);
        }
        dp.resize(str.length());
        n=str.length();
    }

    int solve(){
        int p=0,len=0;
        for(int i=0; i<n; i++){
            if(p+len<i) dp[i]=0;
            else dp[i]=min(dp[2*p-i],p+len-i);
            while(i+dp[i]+1<n && i-dp[i]-1>=0 && str[i+dp[i]+1]==str[i-dp[i]-1]) dp[i]+=1;
            if(p+len<i+dp[i]){
                p=i;
                len=dp[i];
            }
        }

        int ret=0;
        for(int i=0; i<n; i++){
            if(str[i]=='#') ret=max(ret,(dp[i]+1)/2*2);
            else ret=max(ret,dp[i]/2*2+1);
        }
        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s;
    cin>>s;
    Manacher manacher=Manacher(s);
    cout<<manacher.solve();

    return 0;
}
