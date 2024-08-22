#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_31614() {
    int H, M; scanf("%d %d", &H, &M);
    printf("%d\n", H * 60 + M);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_31614(); 
    return 0;
}
