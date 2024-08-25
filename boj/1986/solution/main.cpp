#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int knight[8][2] = {2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1};
int queen[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
int m[1010][1010];

struct Point {
    int r, c;
};
int N, M;
bool isIn(int r,int c) {
    return r >= 1 && r <= N && c >= 1 && c <= M;
}
void solve_1986() {
    scanf("%d %d", &N, &M);
    vector<Point> queens,knights,pawns;
    int cnt;
    scanf("%d", &cnt);
    FOR(i,0,cnt) {
        int r,c; scanf("%d %d", &r, &c);
        queens.push_back({r,c});
        m[r][c]=1; // 1 방해물, 2 공격범위
    }
    scanf("%d", &cnt);
    FOR(i,0,cnt) {
        int r,c; scanf("%d %d", &r, &c);
        knights.push_back({r,c});
        m[r][c]=1;
    }
    scanf("%d", &cnt);
    FOR(i,0,cnt) {
        int r,c; scanf("%d %d", &r, &c);
        pawns.push_back({r,c});
        m[r][c]=1;
    }
    for(auto& k: knights) {
        FOR(p,0,8) {
            int nr = k.r + knight[p][0];
            int nc = k.c + knight[p][1];
            if (isIn(nr,nc) && m[nr][nc] == 0) {
                m[nr][nc] = 2;
            }
        }
    }
    for(auto& q: queens) {
        queue<int> dir;
        FOR(i,0,8) dir.push(i);
        int r = q.r;
        int c = q.c;
        while(dir.size()) {
            auto p = dir.front(); dir.pop();
            int nr = r + queen[p][0];
            int nc = c + queen[p][1];
            while(true) {
                if (isIn(nr,nc) && m[nr][nc] != 1) {
                    m[nr][nc] = 2;
                    nr += queen[p][0];
                    nc += queen[p][1];
                    continue;
                }
                break;
            }
        }
    }
    int ans = 0;
    FOR(i,1,N+1) FOR(j,1,M+1) {
        if (m[i][j] == 0) ++ans;
    }
    printf("%d", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_1986(); 
    return 0;
}
