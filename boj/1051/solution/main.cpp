#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char Map[51][51];
void solve_1051() {
    int N, M; scanf("%d %d", &N, &M);
    FOR(i,0,N) {
        scanf("%s", Map[i]);
    }
    int ans = 1;
    FOR(i,0,N) {
        FOR(j,0,M) {
            char origin = Map[i][j];
            FOR(l,1,max(N,M)) {
                if (i + l >= N || j + l >= M) break;
                if (Map[i+l][j+l] == origin && Map[i][j+l] == origin && Map[i+l][j] == origin) {
                    ans = max(ans, (l+1) * (l+1));
                }
            }
        }
    }
    printf("%d", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_1051(); 
    return 0;
}
