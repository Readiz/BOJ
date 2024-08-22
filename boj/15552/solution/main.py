# 빠른 python 연습
import sys
input = lambda: sys.stdin.readline().rstrip()

N=int(input())
ret = []
for _ in range(N):
    a, b = map(int,input().split())
    ret.append(str(a+b))
print('\n'.join(ret))
