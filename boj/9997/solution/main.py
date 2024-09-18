def solve_9997():
    import sys
    
    input = sys.stdin.readline
    N = int(input().strip())
    v = [0] * 25
    
    for i in range(N):
        buf = input().strip()
        for char in buf:
            v[i] |= 1 << (ord(char) - ord('a'))
    
    e = 1 << N
    mask = (1 << 26) - 1
    ans = 0
    
    for p in range(e):
        cur = 0
        for i in range(N):
            if p & (1 << i):
                cur |= v[i]
        if cur == mask:
            ans += 1
    
    print(ans)

def main():
    TC = 1
    # TC = int(input().strip())
    for _ in range(TC):
        solve_9997()

if __name__ == "__main__":
    main()