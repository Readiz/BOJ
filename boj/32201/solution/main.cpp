#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_32201() {
    int N; scanf("%d", &N);
    unordered_map<int,int> m;
    FOR(i,0,N) {
        int a; scanf("%d", &a);
        m[a] = i;
    }
    vector<int> v;
    int lastup = 0;
    FOR(i,0,N) {
        int a; scanf("%d", &a);
        int up = m[a] - i;
        if (lastup < up) {
            v.clear();
            v.push_back(a);
            lastup = up;
        } else if (lastup == up) {
            v.push_back(a);
        }
    }
    for(auto& i:v) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_32201(); 
    return 0;
}
