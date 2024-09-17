#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int concat(int a, int b) {
    int lenb = 0;
    for(int t = b; t > 0; t /= 10) ++lenb;
    FOR(i,0,lenb) a *= 10;
    return a + b;
}

void solve_5619() {
    int N; scanf("%d", &N);
    vector<int> v;
    int ans[4], ansSz = 0;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    FOR(i,0,N) FOR(j,0,N) {
        if (i == j) continue;
        ans[ansSz++] = concat(v[i], v[j]);
        for(int k = ansSz - 1; k > 0; --k) {
            if (ans[k] < ans[k - 1]) {
                swap(ans[k], ans[k-1]);
            }
        }
        if (ansSz > 3) ansSz = 3;
    }
    printf("%d\n", ans[2]);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_5619(); 
    return 0;
}
