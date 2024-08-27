#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int vis[100][100][3];
int main() {
    int N, T;
    cin >> N >> T;
    
    vector<vector<int>> map_data(N, vector<int>(N));    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map_data[i][j];
        }
    }
    
    priority_queue<tuple<long long, long long, int, int, int, int>, vector<tuple<long long, long long, int, int, int, int>>, greater<>> pq;
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};
    
    pq.push(make_tuple(0, 0, 0, 0, 0, 0));  // (score, time, cnt, r, c, dir)
    
    int ans = -1;
    while (!pq.empty()) {
        auto [score, time, cnt, r, c, dir] = pq.top(); pq.pop();
        
        if (r == N - 1 && c == N - 1) {
            ans = time;
            break;
        }
        
        if (vis[r][c][cnt]) continue;
        vis[r][c][cnt] = 1;
        
        for (int p = 0; p < 4; ++p) {
            int nr = r + dr[p];
            int nc = c + dc[p];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            // if (vis[nr][nc][p][(cnt + 1) % 3] == 1) continue;
            
            long long ntime = time + T;
            if ((cnt + 1) % 3 == 0) {
                ntime += map_data[nr][nc];
            }
            long long score = ntime * 100 + abs(nr - N + 1) + abs(nc - N + 1);
            
            pq.push(make_tuple(score, ntime, (cnt + 1) % 3, nr, nc, p));
        }
    }
    
    cout << ans << endl;
    return 0;
}