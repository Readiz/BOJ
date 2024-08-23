// dfs, 백트래킹 연습.. 맵을 잘 캐싱하고 가지치기를 잘 하자.
#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char m[9][10];
char chk_row[9][10], chk_col[9][10], chk_area[9][10];
int get_area(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}
void update_chk() {
    FOR(i,0,9) FOR(j,0,9) {
        chk_row[i][m[i][j]] = 1;
        chk_col[j][m[i][j]] = 1;
        chk_area[get_area(i,j)][m[i][j]] = 1;
    }
}
bool dfs(int i) {
    if (i == 81) {
        // 다 맞는 case니까 리턴
        return true;
    }
    int r = i / 9;
    int c = i % 9;
    if (m[r][c]) { // 초기값 차 있는 상태, skip
        _D("(%d, %d) is already inserted, skip to next.\n", r, c);
        return dfs(i + 1);
    }
    _D("(%d, %d) is checking...\n", r, c);
    int a = get_area(r, c);
    // 아니라면, 채우고 넘어간다.
    FOR(n,1,10) {
        _D("   try %d!\n", n);
        if (chk_row[r][n] == 1 || chk_col[c][n] == 1 || chk_area[a][n] == 1) continue;
        chk_row[r][n] = 1; chk_col[c][n] = 1; chk_area[a][n] = 1;
        bool ret = dfs(i + 1);
        if (ret) {
            m[r][c] = n; // 찾았으면 채운다.
            return true;
        }
        chk_row[r][n] = 0; chk_col[c][n] = 0; chk_area[a][n] = 0;
    }
    return false;
}

void solve_2239() {
    FOR(i,0,9) {
        scanf("%s", m[i]);
    }
    FOR(r,0,9) FOR(c,0,9) {
        m[r][c] = m[r][c] - '0';
    }
    // 처음 맵의 상태를 체크해서 넣어둠
    update_chk();
    auto ret = dfs(0);
    // assert(ret);
    FOR(r,0,9) FOR(c,0,9) {
        m[r][c] = m[r][c] + '0';
    }
    FOR(i,0,9) {
        printf("%s%c", m[i], i==8?' ':'\n');
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_2239(); 
    return 0;
}
