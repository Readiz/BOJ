#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_2477() {
    int N; scanf("%d", &N);
    int a[6], dummy;
    FOR(i,0,6) {
        scanf("%d %d", &dummy, &a[i]);
    }
    int max_val = 0;
    int max_idx = -1;
    FOR(i,0,6) {
        int l = a[i];
        int r = a[(i+1)%6];
        if (l*r > max_val) {
            max_val = l*r;
            max_idx = i;
        }
    }
    printf("%d", (max_val - a[(max_idx+3)%6]*a[(max_idx+4)%6]) * N);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_2477(); 
    return 0;
}
