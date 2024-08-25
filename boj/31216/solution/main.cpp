#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

int db[3001];

const int MAX = 1'000'000;
int checker[MAX + 10];
vector<int> primes;
vector<int> specials;
void init() {
    for(int i = 2; i * i <= MAX; ++i) {
        if (checker[i] == 1) continue;
        for(int j = i * i; j <= MAX; j += i) {
            checker[j] = 1;
        }
    }
    primes.push_back(0); // dummy
    FOR(i,2,MAX+1) {
        if (checker[i] == 0) {
            primes.push_back(i);
        }
    }
    for(auto& i: primes) {
        if (i < primes.size()) specials.push_back(primes[i]);
    }
    // printf("%d ---\n", (int)specials.size());
    // for(auto& i: specials) {
    //     printf("%d ", i);
    // }
    // printf("\n");
}
void solve_31216() {
    int N; scanf("%d", &N);
    printf("%d\n", specials[N]);
}

int main() {
    init();
    
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_31216(); 
    return 0;
}
