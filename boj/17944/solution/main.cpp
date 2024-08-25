#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_17944() {
    int N, T; scanf("%d %d", &N, &T);
    int ans = 1;
    bool mode = 0;
    FOR(i,0,T-1) {
        if (mode == 0) {
            if (ans < 2*N) ++ans;
            else {
                mode = 1;
                ans = 2 * N - 1;
            }
        } else {
            if (ans > 1) --ans;
            else {
                mode = 0;
                ans = 2;
            }
        }
    }
    printf("%d", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_17944(); 
    return 0;
}
