import sys
input = lambda: sys.stdin.readline().rstrip()

a=list(map(int,input().split()))
ans=a[4]
a[4]=0
while a[3]:
    if a[0] > 0:
        a[3]-=1
        a[0]-=1
        ans+=1
    else:
        a[3]-=1
        ans+=1
while a[2]: # 3, 스스로는 2개 못넣음
    if a[1] > 0:
        a[1]-=1
        a[2]-=1
        ans+=1
    elif a[0] > 0:
        if a[0] >= 2:
            a[0] -= 2
            a[2] -=1
        else:
            a[0] -=1
            a[2] -=1
        ans+=1
    else:
        a[2]-=1
        ans+=1
while a[1]:
    if a[1] >= 2:
        if a[0] >= 1:
            a[1]-=2
            a[0]-=1
            ans+=1
        else:
            a[1]-=2
            ans+=1
    else:
        if a[0] >= 3:
            a[0]-=3
            a[1]-=1
            ans+=1
        elif a[0] >= 2:
            a[0]-=2
            a[1]-=1
            ans+=1
        elif a[0] >= 1:
            a[0]-=1
            a[1]-=1
            ans+=1
        else:
            a[1]-=1
            ans+=1
while a[0]:
    if a[0] >= 5:
        a[0] -= 5
        ans+=1
    else:
        a[0]=0
        ans+=1
print(ans)