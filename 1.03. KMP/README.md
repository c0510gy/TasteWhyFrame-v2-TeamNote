# KMP

문자열 n에서 문자열 m을 찾는 과정에서, pi배열을 이용하여 각 n의 위치마다 이전에 비교해서 일치했던 위치를 알아내어 m과 1회만 비교하는 방식으로 O(n + m)만에 검색을 완료하는 알고리즘

## pi 배열
pi[i] = i번째 문자까지의 문자열에서 prefix == subfix인 최대 길이

pi배열을 통해 m의 어느 위치부터 탐색해야 하는지 알아낼 수 있다.