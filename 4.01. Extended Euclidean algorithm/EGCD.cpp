#include <iostream>
using namespace std;

auto egcd(int a, int b){
   if(b == 0){
      return {a, 1, 0};
   }
   auto t = egcd(b, a % b);
   return {t.g, t.y, t.x - (a / b) * t.y};
}
