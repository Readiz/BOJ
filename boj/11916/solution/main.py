import sys
input = lambda: sys.stdin.readline().rstrip()

N=int(input())
A=list(map(int,input().split()))

state = [0, 0, 0, 0]
cnt = 0
ball = 0
for m in A:
    if m == 1:
        ball += 1
        if ball == 4:
            ball = 0
            if state[3] > 0 and state[2] > 0 and state[1] > 0:
                cnt += 1
            if state[2] > 0 and state[1] > 0:
                state[3] = 1
            if state[1] > 0:
                state[2] = 1
            state[1] = 1
    elif m == 2:
        ball = 0
        if state[3] > 0 and state[2] > 0 and state[1] > 0:
            cnt += 1
        if state[2] > 0 and state[1] > 0:
            state[3] = 1
        if state[1] > 0:
            state[2] = 1
        state[1] = 1
    else:
        if state[3] > 0:
            cnt += 1
        state[3] = state[2]
        state[2] = state[1]
        state[1] = 0
        ball += 1
        if ball == 4:
            ball = 0
            state[1] = 1

print(cnt)