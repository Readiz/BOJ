#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_32154() {
    // 각 등수의 팀이 푼 문제 수와 푼 문제 리스트

    vector<pair<int, vector<char>>> scoreboard = {
        {11, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'L', 'M'}},  // 1등 (AKARAKA)
        {9,  {'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'}},            // 2등 (goraani)
        {9,  {'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'}},            // 3등 (Raa_FanClub)
        {9,  {'A', 'B', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                 // 4등 (입대 전 라스트댄스)
        {8,  {'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                 // 5등 (진짜1등하러왔습니다)
        {8,  {'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                      // 6등 (돈비고고)
        {8,  {'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                      // 7등 (가지오이당근)
        {8,  {'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                           // 8등 (병공병)
        {8,  {'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'}},                           // 9등 (기령손)
        {8,  {'A', 'B', 'C', 'F', 'G', 'H', 'L', 'M'}},                                 // 10등 (홍하에프)
    };
    
    int N;
    cin >> N;  // 입력 받은 등수
    cout << scoreboard[N-1].first << endl;
    for (char problem : scoreboard[N-1].second) {
        cout << problem << " ";
    }
    cout << endl;
}

int main() {
    int TC = 1;
    // scanf("%d", &TC);
    while(TC--) solve_32154(); 
    return 0;
}
