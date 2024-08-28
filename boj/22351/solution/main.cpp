#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

char buf[3000];
int parse(int s, int e) {
    int ret = 0;
    FOR(i,s,e) {
        ret *= 10;
        ret += buf[i] - '0';
    }
    return ret;
}
bool is999(int v) {
    if (v == 0) return false;
    while (v) {
        if (v % 10 != 9) return false;
        v /= 10;
    }
    return true;
}
void solve_22351() {
    scanf("%s", buf);
    int len=0;
    for(char* c=buf; *c!=0;++c) ++len;
    for(int slen=1; slen<=3; ++slen) {
        int p=0;
        int unit = slen;
        int next = -1;
        bool isFirst = true;
        bool isMatched = false;
        int firstNum = -1;
        int lastNum = -1;
        for(int p = 0; p < len;) {
            if (p+unit > len) break;
            if (p+unit == len) {
                // 마지막 확인
                isMatched = true;
            }
            if (isFirst) {
                int cur = parse(p, p+unit);
                firstNum = lastNum = cur;
                next = cur+1; // 처음에는 그냥 넣고
                p+=unit;
                if (is999(cur)) unit++;
                // _D("start! startNum: %d, nunit: %d\n", cur, unit);
                isFirst = false;
            } else {
                int cur = parse(p, p+unit);
                // _D("cNum: %d (cunit: %d)\n", cur, unit);
                // slen 증가 조건에 따라 증가
                if (cur != next) {
                    isMatched = false;
                    break;
                }
                lastNum = cur;
                next = cur + 1;
                p+=unit;
                if (is999(cur)) unit++;
            }
        }
        if (isMatched) {
            // 처음 숫자와 마지막 숫자 보자.
            printf("%d %d", firstNum, lastNum);
            return;
        }
    }
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_22351(); 
    return 0;
}
