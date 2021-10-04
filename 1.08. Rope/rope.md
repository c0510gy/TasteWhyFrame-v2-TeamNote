# Rope 자료구조

## Index
def : index(i) : return the character at position i

O(logN)
## Concat
def : Concat(S1, S2) : concatenate two ropes, S1 ans S2, into a single rope

O(1) (or O(logN) time to compute the root weight)
## Split
def : Split(i, S) : split the string S into two new string S1 and S2

O(logN)
## Insert
def : insert(i, S') : insert the string S' beginning at position i in the string S

O(logN)
## Delete
def : Delete(i, j) : delete substring Ci, .., C_(i + j - 1)

O(logN)
## Report
def : Report(i, j) : output the string Ci, ..., C_(i + j - 1)

O(j + logN)