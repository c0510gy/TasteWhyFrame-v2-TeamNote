# Extended Euclidean Algorithm (확장 유클리드 알고리즘)

`ax + by = gcd(a, b)`인 선형 디오판토스 방정식에서 정수해 x, y값을 빠르게 찾을 수 있는 알고리즘

유클리드 알고리즘을 기반으로 `bx' + (a % b)y' = gcd(b, a % b)`와 같이 변형하여 해결한다.

## 증명
```
ax + by = gcd(a, b)
a = bq + r (단, q = floor(a / b), r = a mod b)
ax + by = (bq + r)x + by = b(qx + y) + rx = gcd(a, b) = gcd(b, r)
=> bx' + ry' = gcd(b, r)
=> qx + y = x', x = y'
=> x = y', y = x' - [a / b]x = x' - [a / b]y'

결국 b = 0이 될 것이므로 재귀함수는 a + 0 = gcd(a, b) = a 일때를 재귀 종료조건으로 한다.
```

## 곱셈의 역원
어떤 값 a의 곱셈 역원을 x라 하면 다음을 만족한다.

`ax = 1 (mod M)`

이는 임의의 정수 y에 대해 `ax + My = 1` 과 같음을 알 수 있고 `gcd(a, M) = 1`일때 확장 유클리드 알고리즘을 통해 x의 값을 구할 수 있다.

이때, x의 값이 [0, M)에 속하지 않을 수 있으므로 `x = (x + M) % M` 으로 가공해준다.

## 기타
이와 같은 특성을 통해 `ax + by = c`꼴의 선형 디오판토스 방정식에 대해 정수해가 존재하는지를 판단할 수 있다. (예 - https://codeforces.com/contest/1202/problem/B)
