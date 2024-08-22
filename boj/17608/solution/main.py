N=int(input())
A=[]
for _ in range(N):
    cur=int(input())
    A.append(cur)

A.reverse()

cur = 0
ans = 0
for i in A:
    if i > cur:
        ans += 1
        cur = i

print(ans) 
