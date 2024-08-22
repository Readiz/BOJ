#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int db[11][2] = {
    {12, 1600},
    {11, 894},
    {11, 1327},
    {10, 1311},
    {9, 1004},
    {9, 1178},
    {9, 1357},
    {8, 837},
    {7, 1055},
    {6, 556},
    {6, 773}
};
void solve_31429() {
    int N; scanf("%d", &N);
    printf("%d %d\n", db[N - 1][0], db[N - 1][1]);
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_31429(); 
    return 0;
}
