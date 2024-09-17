#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int chk(int v) {
    int ans = 0;
    for(int i = 1; i < v; ++i) {
        if (v % i == 0) {
            ans += i;
        }
    }
    return ans;
}

void solve_27065() {
    int N; scanf("%d", &N);
    _D("N: %d\n", N);
    bool checker = true;
    FOR(i,1,N) {
        if (N % i == 0) {
            _D("i: %d, sum: %d\n", i, chk(i));
            if (chk(i) <= i) continue;
            checker = false;
            break;
        }
    }
    if (chk(N) > N && checker) printf("Good Bye\n");
    else printf("BOJ 2022\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_27065(); 
    return 0;
}
