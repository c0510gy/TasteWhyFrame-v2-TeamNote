#include <iostream>
#define MAXN 10000
using namespace std;

typedef long long int lli;
int N;
lli P[MAXN][2], ans;
int main(){
    cin >> N;
    for(int j = 0; j < N; j++)
        cin >> P[j][0] >> P[j][1];
    
    ans += P[N - 1][0] * P[0][1] - P[0][0] * P[N - 1][1];
    for(int j = 0; j < N - 1; j++)
        ans += P[j][0] * P[j + 1][1] - P[j + 1][0] * P[j][1];
    ans = ans > 0 ? ans : -ans;
    // 넓이 = ans / 2

    if(ans % 2)
        cout << ans / 2 << ".5";
    else
        cout << ans / 2 << ".0";
    return 0;
}