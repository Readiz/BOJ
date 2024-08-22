#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char buf[51];
char ret[51];
int cnt[26];
void solve_1213() {
    scanf("%s", buf);
    int len = 0;
    for(char* p=buf; *p!=0;++p) {
        cnt[*p - 'A']++;
        ++len;
    }
    int cnt1 = 0;
    char pos1 = -1;
    FOR(i,0,26) {
        if (cnt[i] % 2 == 1) {
            ++cnt1;
            pos1 = i;
        }
    }
    if (len % 2 == 1) {
        if (cnt1 == 1) {
            // special case
            ret[len/2] = 'A' + pos1;
            cnt[pos1]--;
            int left = len/2 - 1;
            int right = len/2 + 1;
            while(true) {
                if (left < 0 || right >= len) break;
                for(int i = 25; i >=0; --i) {
                    if (cnt[i]) {
                        ret[left] = 'A' + i;
                        ret[right] = 'A' + i;
                        cnt[i]-=2;
                        break;
                    }
                }
                --left; ++right;
            }
        } else if (cnt1 > 1) {
            printf("I'm Sorry Hansoo");
            return;
        }
    } else {
        if (cnt1) {
            printf("I'm Sorry Hansoo");
            return;
        }
        int left = len/2 - 1;
        int right = len/2;
        while(true) {
            if (left < 0 || right >= len) break;
            for(int i = 25; i >=0; --i) {
                if (cnt[i]) {
                    ret[left] = 'A' + i;
                    ret[right] = 'A' + i;
                    cnt[i]-=2;
                    break;
                }
            }
            --left; ++right;
        }
    }
    printf("%s", ret);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_1213(); 
    return 0;
}
