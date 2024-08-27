import sys
import heapq
input = lambda: sys.stdin.readline().rstrip()

N, T = map(int, input().split())
map_data = []
vis = [[[[0] * 3 for _ in range(4)] for _ in range(N)] for _ in range(N)]

for _ in range(N):
    map_data.append(list(map(int, input().split())))

pq = []
dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]

heapq.heappush(pq, (0, 0, 0, 0, 0))  # (time, cnt, r, c, dir)

ans = -1
while len(pq) > 0:
    time, cnt, r, c, dir = heapq.heappop(pq)
    if r == N - 1 and c == N - 1:
        ans = time
        break
    
    vis[r][c][dir][cnt] = 1
    
    for p in range(4):
        nr = r + dr[p]
        nc = c + dc[p]
        
        if nr < 0 or nr >= N or nc < 0 or nc >= N:
            continue
        if vis[nr][nc][p][(cnt + 1) % 3] == 1:
            continue
        
        ntime = time + T
        if (cnt + 1) % 3 == 0:
            ntime += map_data[nr][nc]
        
        heapq.heappush(pq, (ntime, (cnt + 1)%3, nr, nc, p))

print(ans)