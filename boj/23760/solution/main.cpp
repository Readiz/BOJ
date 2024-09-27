#include<bits/stdc++.h>
using namespace std;

struct BIT {
    int size;
    vector<int> tree;
    BIT(int n){
        size = n;
        tree.assign(n+2,0);
    }
    void add(int idx, int delta){
        while(idx <= size){
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }
    int sum(int idx){
        int res=0;
        while(idx >0){
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int find_kth(int k){
        int idx=0, bit=17;
        while(bit >=0){
            int next = idx + (1<<bit);
            if(next <= size && tree[next]<k){
                idx = next;
                k -= tree[next];
            }
            bit--;
        }
        return idx+1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int>c(N);
    for(auto &x:c) cin>>x;
    vector<int>w(M);
    for(auto &x:w) cin>>x;
    vector<int>b(M);
    for(auto &x:b) cin>>x;
    int MAX_C=100000;
    BIT bit(MAX_C+1);
    for(auto x:c){
        bit.add(MAX_C -x +1,1);
    }
    bool flag=true;
    for(int i=0;i<M && flag;i++){
        int bi = b[i];
        if(bi > bit.sum(MAX_C+1)){
            flag=false;
            break;
        }
        int idx = bit.find_kth(bi);
        int c_val = MAX_C - (idx-1);
        if(c_val < w[i]){
            flag=false;
            break;
        }
        bit.add(idx, -1);
        int new_c = c_val -w[i];
        bit.add(MAX_C - new_c +1,1);
    }
    cout<< (flag?1:0);
}
