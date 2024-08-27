#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int N;
int check_col[21], check_d1[50], check_d2[50];
int get_d1(int r, int c) {
    return r + c - 1;
}
int get_d2(int r, int c) {
    return r - c + N;
}
int marked[21];
bool dfs(int r) {
    if (r == N+1) {
        return true;
    }
    if (marked[r]) {
        return dfs(r+1);
    }
    FOR(c,1,N+1) {
        if (check_col[c] || check_d1[get_d1(r,c)] || check_d2[get_d2(r,c)]) continue;
        marked[r]=c;
        check_col[c] = check_d1[get_d1(r,c)] = check_d2[get_d2(r,c)] = 1;
        bool ret = dfs(r+1);
        if (ret) return ret;
        marked[r]=0;
        check_col[c] = check_d1[get_d1(r,c)] = check_d2[get_d2(r,c)] = 0;
    }
    return false;
}
void solve_30242() {
    scanf("%d", &N);
    FOR(r,1,N+1) {
        int c; scanf("%d", &c);
        if (c == 0) continue;
        check_col[c] = 1;
        check_d1[get_d1(r,c)]=1;
        check_d2[get_d2(r,c)]=1;
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
    while(TC--) solve_30242(); 
    return 0;
}
