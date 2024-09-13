#include <bits/stdc++.h>
using namespace std;

#define _D(...)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_2641() {
    int N; scanf("%d", &N);
    vector<int> input(N);
    for(auto& i:input) scanf("%d", &i);
    deque<int> origin, rev;
    FOR(i,0,N) origin.push_back(input[i]);
    _D("rev: ");
    for(register int i = N-1; i>=0;--i) {
        rev.push_back((input[i] - 1 + 2) % 4 + 1);
        _D("%d ", rev[rev.size() - 1]);
    }
    _D("\n");
    int M; scanf("%d", &M);
    int ans = 0;
    vector<string> ansVec;
    FOR(m,0,M) {
        vector<int> cur;
        string ansStr = "";
        FOR(i,0,N) {
            int v; scanf("%d", &v);
            cur.push_back(v);
            ansStr += to_string(v) + " ";
        }
        _D("checking: %s\n", ansStr.c_str());
        bool check = false;
        FOR(i,0,N) {
            bool check1 = true;
            FOR(k,0,N) {
                if (cur[k] != origin[k]) {
                    check1 = false;
                    break;
                }
            }
            if (check1) {
                check = true;
                break;
            }
            bool check2 = true;
            FOR(k,0,N) {
                if (cur[k] != rev[k]) {
                    check2 = false;
                    break;
                }
            }
            if (check2) {
                check = true;
                break;
            }
            int o = origin.front(); origin.pop_front();
            origin.push_back(o);
            int b = rev.front(); rev.pop_front();
            rev.push_back(b);
        }
        if (check) {
            ++ans;
            ansVec.push_back(ansStr);
        }
    }
    printf("%d\n", ans);
    for(auto& s: ansVec) {
        printf("%s\n", s.c_str());
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_2641(); 
    return 0;
}
