N=int(input())
A=list(map(int,input().split()))
A.insert(0, 0)
M=int(input())
for _ in range(M):
    gender, i = map(int,input().split())
    if gender == 1:
        st = i
        while True:
            if st > N:
                break
            A[st] = 1 - A[st]
            st += i
    else:
        left = i - 1
        right = i + 1
        A[i] = 1 - A[i]
        while True:
            if left <= 0 or right > N:
                break
            if A[left] != A[right]:
                break
            A[left] = 1 - A[left]
            A[right] = 1 - A[right]
            left -= 1
            right += 1

ret = ''
for i in range(1,N+1):
    ret += str(A[i]) + ' '
    if i % 20 == 0:
        ret += '\n'

print(ret)

