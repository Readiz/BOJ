#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char Map[51][51];
int N;
int calc() {
    int ret = 1;
    // 좌우 max
    FOR(i,0,N) {
        int cur = 1;
        FOR(j,1,N) {
            if (Map[i][j] == Map[i][j-1]) {
                cur += 1;
            } else {
                ret = max(ret, cur);
                cur = 1;
            }
        }
        ret = max(ret, cur);
    }
    // 상하 max
    FOR(i,0,N) {
        int cur = 1;
        FOR(j,1,N) {
            if (Map[j][i] == Map[j-1][i]) {
                cur += 1;
            } else {
                ret = max(ret, cur);
                cur = 1;
            }
        }
        ret = max(ret, cur);
    }

    return ret;
}
void solve_3085() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%s", Map[i]);
    }
    int ans = 0;
    // 좌우 스왑
    FOR(i,0,N) FOR(j,0,N-1) {
        swap(Map[i][j], Map[i][j+1]);
        int cur = calc();
        ans = max(cur, ans);
        swap(Map[i][j], Map[i][j+1]);
    }
    // 상하 스왑
    FOR(i,0,N-1) FOR(j,0,N) {
        swap(Map[i][j], Map[i+1][j]);
        int cur = calc();
        ans = max(cur, ans);
        swap(Map[i][j], Map[i+1][j]);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_3085(); 
    return 0;
}
