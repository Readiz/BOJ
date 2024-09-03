#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_15721() {
    int A,T,C; scanf("%d%d%d", &A,&T,&C);
    int cur = 2; // 뻔 수
    int idx = -1;
    int cnt_b = 0, cnt_d = 0;
    while (true) {
        cnt_b += 1; idx += 1;
        if (C == 0 && cnt_b >= T) {
            printf("%d\n", idx % A);
            return;
        }
        cnt_d += 1; idx += 1;
        if (C == 1 && cnt_d >= T) {
            printf("%d\n", idx % A);
            return;
        }
        cnt_b += 1; idx += 1;
        if (C == 0 && cnt_b >= T) {
            printf("%d\n", idx % A);
            return;
        }
        cnt_d += 1; idx += 1;
        if (C == 1 && cnt_d >= T) {
            printf("%d\n", idx % A);
            return;
        }
        FOR(i,0,cur) {
            cnt_b += 1; idx += 1;
            if (C == 0 && cnt_b >= T) {
                printf("%d\n", idx % A);
                return;
            }
        }
        FOR(i,0,cur) {
            cnt_d += 1; idx += 1;
            if (C == 1 && cnt_d >= T) {
                printf("%d\n", idx % A);
                return;
            }
        }

        cur += 1;
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_15721(); 
    return 0;
}
