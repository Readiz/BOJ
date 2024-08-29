#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

ll strToLL(char c[]) {
    ll ret = 0;
    FOR(i,0,11) {
        ret *= 27;
        if (c[i] != 0) ret += c[i] - 'A' + 1;
    }
    return ret;
}

void solve_20124() {
    int N; scanf("%d", &N);
    int maxScore = -1;
    ll maxString = -1;
    char maxStringActual[11];
    FOR(i,0,N) {
        char buf[11] = {0, };
        int score;
        scanf("%s %d", buf, &score);
        if (score > maxScore) {
            maxScore = score;
            maxString = strToLL(buf);
            strcpy(maxStringActual, buf);
        } else if (score == maxScore) {
            if (maxString > strToLL(buf)) {
                maxString = strToLL(buf);
                strcpy(maxStringActual, buf);
            }
        }
    }
    printf("%s", maxStringActual);
}


int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_20124(); 
    return 0;
}
