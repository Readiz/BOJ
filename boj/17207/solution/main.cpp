#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

struct Matrix {
    int d[5][5];
    string name;
    void input() {
        FOR(i,0,5) FOR(j,0,5) {
            scanf("%d", &d[i][j]);
        }
    }
    void mul(Matrix& t) {
        int nd[5][5] = {0,};
        FOR(i,0,5) FOR(j,0,5) FOR(k,0,5) {
            nd[i][j] += d[i][k] * t.d[k][j];
        }
        FOR(i,0,5) FOR(j,0,5) {
            d[i][j] = nd[i][j];
        }
    }
} m[2];

void solve_17207() {
    m[0].input();
    m[1].input();
    m[0].mul(m[1]);

    string names[5] = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};
    int minVal = 987654321;
    int minIdx = -1;
    FOR(i,0,5) {
        int cVal = 0;
        FOR(j,0,5) cVal += m[0].d[i][j];
        if (cVal <= minVal) {
            minVal = cVal;
            minIdx = i;
        }
        // printf("[%d] %d\n", i, cVal);
    }
    printf("%s", names[minIdx].c_str());
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_17207(); 
    return 0;
}
