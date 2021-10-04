#include <iostream>
using namespace std;

typedef long long int lli;
struct vector2{
    lli x, y;
    vector2(lli _x, lli _y){
        x = _x, y = _y;
    }
    lli cross(const vector2& other)const{
        return x * other.y - y * other.x;
    }
    vector2 operator-(vector2 other)const{
        return vector2(x - other.x, y - other.y);
    }
    bool operator==(vector2 other) const{
        return x == other.x && y == other.y;
    }
    bool operator<(vector2 other) const{
        if(x == other.x)
            return y < other.y;
        return x < other.x;
    }
};
/// CCW 이용한 교차 여부 판단
lli ccw(vector2 a, vector2 b, vector2 c){
    lli op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if(op > 0)
        return 1;
    else if(op == 0)
        return 0;
    return -1;
}
bool sementIntersects(vector2 a, vector2 b, vector2 c, vector2 d){
    lli ab = ccw(a, b, c) * ccw(a, b, d);
    lli cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}