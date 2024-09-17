#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

struct Info {
    int p;
    int step;
};
int vis[100'001];
void solve_12761() {
    int A, B, N, M; scanf("%d%d%d%d", &A, &B, &N, &M);
    queue<Info> q;
    q.push({N, 0});
    while(q.size()) {
        auto cur = q.front(); q.pop();
        if (cur.p == M) {
            printf("%d\n", cur.step);
            return;
        }
        if (vis[cur.p]) continue;
        vis[cur.p] = 1;
        if (cur.p - 1 >= 0) {
            if (vis[cur.p - 1] == 0) {
                q.push({cur.p - 1, cur.step + 1});
            }
        }
        if (cur.p + 1 <= 100'000) {
            if (vis[cur.p + 1] == 0) {
                q.push({cur.p + 1, cur.step + 1});
            }
        }
        if (cur.p - A >= 0) {
            if (vis[cur.p - A] == 0) {
                q.push({cur.p - A, cur.step + 1});
            }
        }
        if (cur.p + A <= 100'000) {
            if (vis[cur.p + A] == 0) {
                q.push({cur.p + A, cur.step + 1});
            }
        }
        if (cur.p - B >= 0) {
            if (vis[cur.p - B] == 0) {
                q.push({cur.p - B, cur.step + 1});
            }
        }
        if (cur.p + B <= 100'000) {
            if (vis[cur.p + B] == 0) {
                q.push({cur.p + B, cur.step + 1});
            }
        }
        if (cur.p * A <= 100'000) {
            if (vis[cur.p * A] == 0) {
                q.push({cur.p * A, cur.step + 1});
            }
        }
        if (cur.p * B <= 100'000) {
            if (vis[cur.p * B] == 0) {
                q.push({cur.p * B, cur.step + 1});
            }
        }
    }
    printf("-1\n");
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_12761(); 
    return 0;
}
