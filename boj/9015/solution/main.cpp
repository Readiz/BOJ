#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

ll key(int x, int y) {
    return (((ll)x+10000) << 15) | (y+10000);
}

void solve_9015() {
    int N; scanf("%d", &N);
    unordered_set<ll> checker; // checker
    vector<pair<int,int>> v;
    FOR(i,0,N) {
        int x, y; scanf("%d%d",&x,&y);
        checker.insert(key(x,y));
        v.push_back({x,y});
    }

    ll ans = 0;
    FOR(i,0,N) {
        int x = v[i].first;
        int y = v[i].second;
        FOR(j,0,N) {
            if (i==j) continue;
            // 2점을 고른다.
            {
                int cx = v[j].first;
                int cy = v[j].second;
                int dx = cx - x;
                int dy = cy - y;
                // 나머지 두 점 확인
                cx -= dy; cy += dx;
                // _D("%d,%d / %d,%d / %d,%d\n", x, y, cx + dy, cy - dx, cx, cy);
                if (checker.find(key(cx,cy)) != checker.end()) {
                    cx -= dx; cy -= dy;
                    if (checker.find(key(cx,cy)) != checker.end()) {
                        ll area = (ll)dx * dx + (ll)dy * dy;
                        if (area > ans) ans = area;
                        // _D("area chk:%lld 111\n", area);
                    }
                }
            }
            // {
            //     int cx = v[j].first;
            //     int cy = v[j].second;
            //     int dx = cx - x;
            //     int dy = cy - y;
            //     // 나머지 두 점 확인
            //     cx += dy; cy -= dx;
            //     // _D("%d,%d / %d,%d / %d,%d [%d, %d]\n", x, y, cx - dy, cy + dx, cx, cy, dx, dy);
            //     if (checker.find(key(cx,cy)) == checker.end()) continue;
            //     cx += dx; cy += dy;
            //     if (checker.find(key(cx,cy)) == checker.end()) continue;
            //     ll area = (ll)dx * dx + (ll)dy * dy;
            //     if (area > ans) ans = area;
                
            //     cx += dy; cy -= dx;
            //     if (checker.find(key(cx,cy)) != checker.end()) {
            //         cx += dx; cy += dy;
            //         if (checker.find(key(cx,cy)) != checker.end()) {
            //             ll area = (ll)dx * dx + (ll)dy * dy;
            //             if (area > ans) ans = area;
            //             // _D("area chk:%lld 222\n", area);
            //         }
            //     }
            // }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_9015(); 
    return 0;
}
