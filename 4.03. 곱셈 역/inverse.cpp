#include <iostream>
using namespace std;

typedef long long int lli;
struct strt{
    lli g, x, y;
};
lli N, A, ans1, ans2 = -1;
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A; // A를 N으로 나눌 때
    ans1 = N - A; // 덧셈 역원
    if(gcd(A, N) == 1) // ax + My = 1 
        ans2 = (egcd(A, N).x + N) % N; // 곱셈 역원
    cout << ans1 << " " << ans2;
    return 0;
}