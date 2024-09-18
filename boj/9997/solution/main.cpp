#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_9997() {
    int N; scanf("%d", &N);
    int v[25] = {0, };
    char buf[110];
    FOR(i,0,N) {
        scanf("%s", buf);
        for(char* p = buf; *p != 0; ++p) {
            v[i] |= 1 << (*p - 'a');
        }
    }
    int e = 1 << N;
    int mask = (1 << 26) - 1;
    int ans = 0;
    FOR(p,0,e) {
        int cur = 0;
        for(int i = 0, j = 1; i < N; ++i, j <<= 1) {
            if (p & j) {
                cur |= v[i];
            }
        }
        if (cur == mask) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_9997(); 
    return 0;
}
