#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
int r, c, k;
int A[110][110];
int R, C;
void row() {
    int cmax = 0;
    FOR(r,1,R+1) {
        int cnt[101] = {0,};
        FOR(c,1,C+1) {
            cnt[A[r][c]]++;
        }
        vector<pair<int,int>> v;
        FOR(i,1,101) {
            if (cnt[i]) {
                v.push_back({cnt[i], i});
            }
        }
        sort(v.begin(), v.end());
        int idx = 1;
        FOR(i,1,101) {
            A[r][i] = 0;
        }
        FOR(i,0,v.size()) {
            A[r][idx++] = v[i].second;
            A[r][idx++] = v[i].first;
        }
        cmax = max(cmax, (int)v.size() * 2);
    }
    C = cmax;
}
void col() {
    int rmax = 0;
    FOR(c,1,C+1) {
        int cnt[101] = {0,};
        FOR(r,1,R+1) {
            cnt[A[r][c]]++;
        }
        vector<pair<int,int>> v;
        FOR(i,1,101) {
            if (cnt[i]) {
                v.push_back({cnt[i], i});
            }
        }
        sort(v.begin(), v.end());
        int idx = 1;
        FOR(i,1,101) {
            A[i][c] = 0;
        }
        FOR(i,0,v.size()) {
            A[idx++][c] = v[i].second;
            A[idx++][c] = v[i].first;
        }
        rmax = max(rmax, (int)v.size() * 2);
    }
    R = rmax;
}
void solve_17140() {
    int r, c, k; scanf("%d%d%d", &r, &c, &k);
    R = C = 3;
    FOR(r,1,4)FOR(c,1,4) scanf("%d", &A[r][c]);
    if (A[r][c] == k) {
        printf("0");
        return;
    }
    for(int T=1; T<=100; ++T) {
        if (R>=C) row();
        else col();
        // _D("T: %d / %d, %d\n", T, R, C);
        // FOR(i,1,R+1) FOR(j,1,C+1) {
        //     _D("%d%c",A[i][j]," \n"[j==C]);
        // }
        if (A[r][c]==k) {
            printf("%d", T);
            return;
        }
    }
    printf("-1");
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_17140(); 
    return 0;
}
