import sys
input = lambda: sys.stdin.readline().rstrip()

N,mode=map(str,input().split())
N = int(N)
ans = 0
if mode == "bad":
    ans = 200 * N
elif mode == "cool":
    ans = 400 * N
elif mode == "great":
    ans = 600 * N
elif mode == "perfect":
    ans = 1000 * N
    
print(ans)