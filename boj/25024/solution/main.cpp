#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;


// 시는 0시에서 23시까지, 분은 0분에서 59분까지가 유효하며, 월은 1월에서 12월까지가 유효하다. 1월, 3월, 5월, 7월, 8월, 10월, 12월은 1일에서 31일까지가 유효하고, 4월, 6월, 9월, 11월은 1일에서 30일까지가 유효하며, 2월은 1일에서 29일까지가 유효하다.

int dates[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve_25024() {
    int x,y; scanf("%d%d", &x,&y);
    if (x <= 23 && y <= 59) {
        printf("Yes ");
    } else {
        printf("No ");
    }
    if (x >= 1 && x <= 12 && y >= 1 && y <= dates[x]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_25024(); 
    return 0;
}
