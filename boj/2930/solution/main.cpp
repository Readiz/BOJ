#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char s[51];
char f[51][51];
void solve_2930() {
    int R; scanf("%d", &R);
    scanf("%s", s);
    int N; scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%s", f[i]);
    }
    int s1 = 0, s2 = 0;
    FOR(r,0,R) {
        char cur = s[r];
        int cnt[3] = {0, };
        FOR(i,0,N) {
            if (cur == 'R' && f[i][r] == 'S') s1 += 2;
            if (cur == 'P' && f[i][r] == 'R') s1 += 2;
            if (cur == 'S' && f[i][r] == 'P') s1 += 2;
            if (cur == f[i][r]) s1 += 1;
            if (f[i][r] == 'R') cnt[0]++;
            if (f[i][r] == 'P') cnt[1]++;
            if (f[i][r] == 'S') cnt[2]++;
        }
        int curMax = 0;
        FOR(i,0,3) {
            int cur = cnt[i] * 2 + cnt[(i + 1) % 3];
            if (cur > curMax) curMax = cur;
        }
        s2 += curMax;
    }
    printf("%d\n%d\n", s1, s2);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_2930(); 
    return 0;
}
