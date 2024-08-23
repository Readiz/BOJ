#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int chk_col[14], chk_diag1[28], chk_diag2[28];
int m[14][14];
int N;
int cnt;
int get_d1(int r, int c) {
    return r + c;
}
int get_d2(int r, int c) {
    return r - c + N - 1;
}
// row마다 queen이 1개만 들어간다는 점을 이용한다.
void dfs(int r) {
    if (r == N) {
        ++cnt;
        return;
    }
    FOR(c,0,N) {
        int d1=get_d1(r,c), d2=get_d2(r,c);
        if (chk_col[c] || chk_diag1[d1] || chk_diag2[d2]) continue;
        chk_col[c]=1,chk_diag1[d1]=1,chk_diag2[d2]=1;
        dfs(r+1);
        chk_col[c]=0,chk_diag1[d1]=0,chk_diag2[d2]=0;
    }
}
void solve_9663() {
    // N <= 14
    scanf("%d", &N);
    dfs(0);
    printf("%d", cnt);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_9663(); 
    return 0;
}
