/*
https://en.wikipedia.org/wiki/Eight_queens_puzzle
One approach[3] is

If the remainder from dividing n by 6 is not 2 or 3 then the list is simply all even numbers followed by all odd numbers not greater than n.
Otherwise, write separate lists of even and odd numbers (2, 4, 6, 8 – 1, 3, 5, 7).
If the remainder is 2, swap 1 and 3 in odd list and move 5 to the end (3, 1, 7, 5).
If the remainder is 3, move 2 to the end of even list and 1,3 to the end of odd list (4, 6, 8, 2 – 5, 7, 9, 1, 3).
Append odd list to the even list and place queens in the rows given by these numbers, from left to right (a2, b4, c6, d8, e3, f1, g7, h5).
For n = 8 this results in fundamental solution 1 above. A few more examples follow.

한 가지 접근법은 다음과 같습니다:

만약 n을 6으로 나눈 나머지가 2 또는 3이 아니라면, 리스트는 단순히 n보다 크지 않은 모든 짝수들 뒤에 홀수들을 나열한 것입니다.
그렇지 않다면, 짝수와 홀수의 별도 리스트를 작성합니다 (2, 4, 6, 8 – 1, 3, 5, 7).
나머지가 2인 경우, 홀수 리스트에서 1과 3을 교체하고 5를 끝으로 이동합니다 (3, 1, 7, 5).
나머지가 3인 경우, 짝수 리스트의 2를 끝으로 이동하고 홀수 리스트에서 1, 3을 끝으로 이동합니다 (4, 6, 8, 2 – 5, 7, 9, 1, 3).
홀수 리스트를 짝수 리스트에 추가하고, 이러한 숫자들에 따라 체스판의 각 행에 왼쪽에서 오른쪽으로 퀸을 배치합니다 (a2, b4, c6, d8, e3, f1, g7, h5).

14 queens (remainder 2): 2, 4, 6, 8, 10, 12, 14, 3, 1, 7, 9, 11, 13, 5.
15 queens (remainder 3): 4, 6, 8, 10, 12, 14, 2, 5, 7, 9, 11, 13, 15, 1, 3.
20 queens (remainder 2): 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 3, 1, 7, 9, 11, 13, 15, 17, 19, 5.
*/

#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;

void solve_9175() {
    int N; scanf("%d", &N);
    int mod = N % 6;
    vector<int> odd, even;
    FOR(i,1,N+1) {
        if (i % 2 == 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }
    if (mod == 2) {
        swap(odd[0], odd[1]);
        odd.erase(odd.begin() + 2);
        odd.push_back(5);
    } else if (mod == 3) {
        even.erase(even.begin());
        even.push_back(2);
        odd.erase(odd.begin());
        odd.erase(odd.begin());
        odd.push_back(1);
        odd.push_back(3);
    } else {
        // do nothing
    }
    printf("%d\n", N);
    for(auto& i: even) printf(" %d", i-1);
    for(auto& i: odd) printf(" %d", i-1);
    printf("\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while(TC--) solve_9175(); 
    return 0;
}
