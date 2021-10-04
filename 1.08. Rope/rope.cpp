#include <cstdio>
#include <cstring>
#include <ext/rope>
#define MAXL 100000
using namespace std;
using namespace __gnu_cxx;

int Q, L;
char S[MAXL + 1];
crope rop;
int main(){
    ios::sync_with_stdio(false);
    scanf("%s %d", &S, &Q);
    L = strlen(S);
    rop.insert(0, S);
    while(Q--){
        int t, x, y;
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d", &x, &y);
            crope tmp = rop.substr(x, y - x + 1);
            rop.erase(x, y - x + 1);
            rop.insert(0, tmp);
        }else if(t == 2){
            scanf("%d %d", &x, &y);
            crope tmp = rop.substr(x, y - x + 1);
            rop.erase(x, y - x + 1);
            rop.insert(L - (y - x + 1), tmp);
        }else if(t == 3){
            scanf("%d", &x);
            printf("%c\n", rop[x]);
        }
    }
    return 0;
}