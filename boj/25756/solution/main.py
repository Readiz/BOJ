import sys
input = lambda: sys.stdin.readline().rstrip()

N=int(input())
V=0
A=list(map(int,input().split()))
for c in A:
    V = 1 - (1 - V) * (1 - c / 100)
    print((V) * 100)

