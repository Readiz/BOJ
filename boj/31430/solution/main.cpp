#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_31430() {
    int N; scanf("%d", &N);
    if (N == 1) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long c = a + b;
        char buf[14] = {};
        FOR(i,0,13) buf[i] = 'a';
        FOR(i,0,13) {
            buf[i] += c % 26;
            c /= 26;
        }
        printf("%s", buf);
    } else {
        char buf[14];
        scanf("%s", buf);
        long long ret = 0;
        long long unit = 1;
        FOR(i,0,13) {
            ret += (buf[i] - 'a') * unit;
            unit *= 26;
        }
        printf("%lld", ret);
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_31430(); 
    return 0;
}
