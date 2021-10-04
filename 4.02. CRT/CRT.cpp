#include <iostream>
#define MAXN 100
using namespace std;

typedef long long int lli;
struct strt{
    lli g, x, y;
};

lli N, M[MAXN], R[MAXN], MM = 1, X;
lli gcd(lli a, lli b){
    if(!b)
        return a;
    return gcd(b, a % b);
}
strt egcd(lli a, lli b){
    if(!b)
        return {a, 1, 0};
    strt t = egcd(b, a % b);
    return {t.g, t.y, t.x - (a / b) * t.y};
}
lli get_inverse(lli n, lli m){
    lli ret = -1;
    if(gcd(n, m) == 1)
        ret = (egcd(n, m).x + m) % m;
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int j = 0; j < N; j++){
        cin >> M[j] >> R[j]; // M[j]으로 나누었을 때, 나머지 R[j]
        MM *= M[j];
    }
    for(int j = 0; j < N; j++){
        X += (MM / M[j]) * get_inverse(MM / M[j], M[j]) * R[j] % MM;
        X %= MM;
    }
    cout << X;
    return 0;
}
