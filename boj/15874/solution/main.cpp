#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char buf[100'010];
char tmp;
void solve_15874() {
    int K, N; scanf("%d %d", &K, &N);
    scanf("%c", &tmp); scanf("%c", &tmp);
    scanf("%[^\n]", buf);

    FOR(i,0,N) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            int c = buf[i] - 'A';
            int s = (c + K) % 26;
            buf[i] = s + 'A';
        } else if (buf[i] >= 'a' && buf[i] <= 'z') {
            int c = buf[i] - 'a';
            int s = (c + K) % 26;
            buf[i] = s + 'a';
        }
    }
    printf("%s", buf);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_15874(); 
    return 0;
}
