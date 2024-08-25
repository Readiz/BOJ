import sys
input = lambda: sys.stdin.readline().rstrip()

N=int(input())

MOD = 987654321

def correct_perfect_pairs(n):
    if n % 2 != 0:  # 홀수는 무조건 0
        return 0
    
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(2, n + 1, 2):
        for j in range(0, i, 2):
            dp[i] += dp[j] * dp[i - j - 2]
            dp[i] %= MOD
    
    return dp[n]

print(correct_perfect_pairs(N))
