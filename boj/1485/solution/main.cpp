#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

struct Point {
    ll x,y;
    ll operator-(const Point& t) const {
        return (x-t.x)*(x-t.x) + (y-t.y)*(y-t.y);
    }
} p[4];

int cur[4];
bool checker[4];
bool dfs(int d) {
    if (d == 4) {
        // FOR(i,0,4) {
        //     _D("%d ", cur[i]);
        // }
        // _D(" -> ");
        // FOR(i,0,4) {
        //     _D("%d ", p[cur[(i-1+4)%4]] - p[cur[i]]);
        // }
        // _D("\n");
        ll v = p[cur[0]] - p[cur[3]];
        FOR(i,1,4) {
            if (p[cur[i]] - p[cur[i - 1]] == v) continue;
            return false;
        }

        // 마름모 체크
        if (p[cur[0]] - p[cur[2]] == p[cur[1]] - p[cur[3]]) return true;
        return false;
    }
    FOR(i,0,4) {
        if (checker[i]) continue;
        checker[i] = true;
        cur[d] = i;
        if (dfs(d+1)) return true;
        checker[i] = false;
    }
    return false;
}

void solve_1485() {
    FOR(i,0,4) {
        checker[i] = false;
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    if (dfs(0)) printf("1\n");
    else printf("0\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_1485(); 
    return 0;
}
