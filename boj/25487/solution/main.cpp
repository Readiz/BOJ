#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_25487() {
    int a,b,c; scanf("%d%d%d", &a,&b,&c);
    int ans = min(min(a,b),min(b,c));
    // FOR(i,1,a+1) FOR(j,1,b+1) FOR(k,1,c+1) {
    //     if (i % j == j % k && j % k == k % i) {
    //         ++ans;
    //     }
    // }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_25487(); 
    return 0;
}
