#include <bits/stdc++.h>
using namespace std;

#define _D(...)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

bool chk(int v) {
    while(v) {
        if (v % 10 == 1) {
            if (v / 10 == 0) return true;
            return false;
        } else if (v % 10 != 0) {
            return false;
        }
        v /= 10;
    }
    return false;
}
int calc(int v) {
    int ret = 0;
    while(v) {
        ++ret;
        v/=10;
    }
    return ret;
}

void solve_1748() {
    int N; scanf("%d", &N);
    int len = calc(N);
    // ex: 4자리
    // 9 * 1 + 90 * 2 + 900 * 3 + 4 * ? 인데 이거는 4자리의 시작 직전인 1000 - 1 부터 세면 됨
    int ans = 0;
    int unit = 9;
    int unit2 = 1;
    FOR(i,1,len) {
        ans += unit * i;
        _D("+ %d\n", unit* i);
        unit *= 10;
        unit2 *= 10;
    }
    ans += (N - unit2 + 1) * len;
    _D("+ %d\n", (N - unit2 + 1) * len);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_1748(); 
    return 0;
}
