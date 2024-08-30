#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int arr[1'000'010];
int ans[1'000'010];
// int SegN;
// struct SegTree {
//     int d[2'000'010];
//     void build() {
//         for(int i = SegN - 1; i >= 1; --i) d[i] = min(d[i<<1], d[i<<1|1]);
//     }
//     void updatePoint(int p, int v) {
//         p += SegN;
//         d[p] = v;
//         for(p>>=1; p > 0; p>>=1) {
//             d[p] = min(d[p<<1], d[p<<1|1]);
//         }
//     }
//     int getRange(int l, int r) {
//         // _D("get: %d ~ %d\n", l, r);
//         int ret = 987654321;
//         l += SegN, r += SegN;
//         for(;l<=r; l>>=1, r>>=1) {
//             if (l&1) ret = min(ret, d[l++]);
//             if (~r&1) ret = min(ret, d[r--]);
//         }
//         // _D("ret: %d\n", ret);
//         return ret;
//     }
// } seg;

void solve_24523() {
    int N; scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d", &arr[i]);
    }
    // _D("\n");
    arr[N] = arr[N - 1];
    ans[N] = -1;
    for(int i = N - 1; i >= 0; --i) {
        // int left_min = seg.getRange(0, arr[i] - 1);
        // int right_min = seg.getRange(arr[i]+1, idx);
        // // _D("[%d] left: %d / right: %d\n", i, left_min, right_min);
        // if (left_min == 987654321 && right_min == 987654321) {
        //     ans[i] = -1;
        // } else {
        //     ans[i] = min(left_min, right_min);
        // }
        // seg.updatePoint(arr[i], min(seg.d[arr[i] + SegN], i + 1));
        if (arr[i] == arr[i+1]) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = i + 2;
        }
    }
    FOR(i,0,N) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_24523(); 
    return 0;
}
