#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char buf1[30], buf2[30];
bool solve_9229() {
    scanf("%s", buf1);
    if (buf1[0] == '#') return false;
    bool ans = true;
    while(true) {
        scanf("%s", buf2);
        if (buf2[0] == '#') {
            if (ans) printf("Correct\n");
            else printf("Incorrect\n");
            return true;
        }

        int len1 = strlen(buf1);
        int len2 = strlen(buf2);
        if (len1 != len2) {
            ans = false;
        } else {
            int diffCnt = 0;
            for(int i = 0; i < len1; ++i) {
                if (buf1[i] != buf2[i]) ++diffCnt;
            }
            if (diffCnt != 1) ans = false;
        }
        strcpy(buf1, buf2);
    }
    return true;
}

int main() {
    while(true) if (!solve_9229()) break; 
    return 0;
}
