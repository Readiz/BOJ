#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

// java hash code 함수
int get_hash_code(const char c[]) {
    int h = 0;
    int length = 0;
    for(char* p=(char*)c; *p!=0;++p) ++length;
    
    if (h == 0 && length > 0) {
        for (int i = 0; i < length; i++) {
            h = 31 * h + c[i];
        }
    }
    return h;
}

void solve_15551() {
    int N; scanf("%d", &N);
    string a = "", b = "";
    FOR(i,0,N) a += 'S';
    FOR(i,0,N-2) b += 'S';
    b += 'R';
    b += 'R' + 32;
    // _D("%d vs %d\n", get_hash_code(a.c_str()), get_hash_code(b.c_str()));
    printf("%s\n%s", a.c_str(), b.c_str());
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_15551(); 
    return 0;
}
