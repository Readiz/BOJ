#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_9414() {
    vector<ll> v;
    while(true) {
        int c; scanf("%d", &c);
        if (c == 0) break;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll remained = 5e6;
    ll t = 1;
    ll ans = 0;
    for(auto& c: v) {
        ll amount = 2 * pow(c, t);
        remained -= amount;
        if (remained < 0) {
            printf("Too expensive\n");
            return;
        }
        ans += amount;
        ++t;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_9414(); 
    return 0;
}
