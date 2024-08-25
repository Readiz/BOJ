import sys
input = lambda: sys.stdin.readline().rstrip()

N,C=map(int,input().split())
p1,p2,p3,p4=map(float,input().split())
a=[1-C]*(N+1)
b=[C]*(N+1)

for i in range(1,N+1):
    a[i]=a[i-1]*p1+b[i-1]*p3
    b[i]=a[i-1]*p2+b[i-1]*p4

# print(a)
# print(b)
print(round(a[N] * 1000))
print(round(b[N] * 1000))