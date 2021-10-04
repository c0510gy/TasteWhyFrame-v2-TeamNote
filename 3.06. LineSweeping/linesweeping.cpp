#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#define MAXN 100000
using namespace std;

struct strt{
    int x;
    int y;
    bool operator<(const strt& p)const {
        if(y == p.y)
            return x < p.x;
        return y < p.y;
    }
    bool operator>(const strt& p)const {
        if(y == p.y)
            return x > p.x;
        return y > p.y;
    }
};
bool cmp(strt a, strt b){
    return a.x < b.x;
}
int dist(strt p1, strt p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int n;
set<strt> C;
strt P[MAXN];
int main(){
    scanf("%d", &n);
    for(int j = 0; j < n; j++)
        scanf("%d %d", &P[j].x, &P[j].y);
    sort(P, P + n, cmp);
    int d = dist(P[0], P[1]);
    for(int j = 0, xrange = 0; j < n; j++){
        /// X거리가 d보다 큰 점을 탐색 후보에서 제외
        for(int i = xrange; i < j; i++){
            if((P[j].x - P[i].x) * (P[j].x - P[i].x) > d){
                C.erase(P[i]);
                xrange++;
            }else
                break;
        }
        /// y거리가 d보다 작은 점들을 찾아 탐색
        int dy = (int)sqrt((double)d) + 1;
        auto e = C.lower_bound((strt){10000, P[j].y + dy});
        auto s = C.upper_bound((strt){-10000, P[j].y - dy});
        for(auto it = s; it != e; it++)
            d = min(d, dist(*it, P[j]));
        C.insert(P[j]); /// y값을 기준으로 정렬되는 set
    }
    printf("%d", d);
    return 0;
}