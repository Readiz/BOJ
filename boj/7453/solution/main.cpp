#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

struct Info {
    int sum;
    int cnt;
};

const int HSIZE = (1<<20);
const int HMASK = (1<<20)-1;
struct FashHash {
    vector<Info> h[HSIZE];
    void add(int v) {
        auto& vec = h[v&HMASK];
        for(auto& c: vec) {
            if (c.sum == v) {
                c.cnt++;
                return;
            }
        }
        vec.push_back({v, 1});
    }
    int get(int v) {
        auto& vec = h[v&HMASK];
        for(auto& c: vec) {
            if (c.sum == v) {
                return c.cnt;
            }
        }
        return 0;
    }
} Hash;

void solve_7453() {
    int N; scanf("%d", &N);
    vector<int> A,B,C,D;
    FOR(i,0,N) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    FOR(i,0,N) FOR(j,0,N) {
        Hash.add(C[i] + D[j]);
    }
    ll ans = 0;
    FOR(i,0,N) FOR(j,0,N) {
        ans += Hash.get(-(A[i] + B[j]));
    }
    printf("%lld", ans);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_7453(); 
    return 0;
}
