#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
int N;
unsigned int check_col;
long long check_d1, check_d2;
inline int get_d1(int r, int c) {
    return r + c - 1; // 1 ~ 2N-1 (1, 1) ~ (N, N)
}
inline int get_d2(int r, int c) {
    return c - r + N; // 1 ~ 2N-1  (1, N) ~ (N, 1)
}
int marked[31];
bool dfs(int r) {
    if (r == N+1) {
        return true;
    }
    if (marked[r]) {
        return dfs(r+1);
    }
    long long cur = (ll)check_col & (check_d1>>(r-1)) & (check_d2>>(N-r));
    assert((cur&1)==0);
    assert((check_col&1)==0);
    assert((check_d1&1)==0);
    assert((check_d2&1)==0);
    for(; cur != 0; cur -= cur & -cur) { // 실제 봐야할 bit만 순회한다.
        int c = __builtin_ctz(cur); // 사기스킬 - 현재 c는 갈 수 있다.
        check_col &= ~(1 << c); // 갈 수 없따
        check_d1 &= ~(1LL << get_d1(r,c));
        check_d2 &= ~(1LL << get_d2(r,c));
        bool ret = dfs(r+1);
        if (ret) {
            marked[r]=c;
            return ret;
        }
        check_col |= 1 << c; // 다시 갈 수 이따
        check_d1 |= 1LL << get_d1(r,c);
        check_d2 |= 1LL << get_d2(r,c);
    }
    return false;
}
void solve_30243() {
    scanf("%d", &N);
    check_col = (1<<(N+1)) - 1;
    check_col ^= 1;
    check_d1 = (1LL<<(2*N)) - 1;
    check_d1 ^= 1;
    check_d2 = (1LL<<(2*N)) - 1;
    check_d2 ^= 1;
    FOR(r,1,N+1) {
        int c; scanf("%d", &c);
        if (c == 0) continue;
        check_col ^= 1 << c;
        check_d1 ^= (1LL<<get_d1(r,c));
        check_d2 ^= (1LL<<get_d2(r,c));
        marked[r] = c;
    }
    bool ret = dfs(1);
    if (ret) {
        FOR(r,1,N+1) {
            printf("%d%c", marked[r], " \n"[r==N]);
        }
    } else {
        printf("-1\n");
    }
}
int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_30243(); 
    return 0;
}
