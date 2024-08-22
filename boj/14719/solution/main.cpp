#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int h[510];
void solve_14719() {
    int H, W; scanf("%d %d", &H, &W);
    FOR(i,1,W+1) {
        scanf("%d", &h[i]);
    }
    int ans = 0;
    auto func = [&](int start, int& end) {
        FOR(s,start,W+1) {
            for(int e=W; e > s; --e) {
                int wall = min(h[s], h[e]);
                int water = 0;
                FOR(i,s+1,e) {
                    if (h[i] >= wall) {
                        water = -1;
                        break;
                    }
                    water += wall - h[i];
                }
                if (water > 0) {
                    end = e;
                    return water;
                }
            }
        }
        return -1;
    };
    int start = 1;
    while(true) {
        int end;
        int ret = func(start, end);
        if (ret > 0) {
            ans += ret;
            start = end;
        } else {
            // 더이상 웅덩이 없음
            break;
        }
    }

    printf("%d", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_14719(); 
    return 0;
}
