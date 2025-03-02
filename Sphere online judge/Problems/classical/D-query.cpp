#include <bits/stdc++.h>
#define LsOne(x) (x)&(-x)
using namespace std;
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    cin >> q;
    vector<vector<int>> query(q);
    vector<int> res(q);
    for(int i=0;i<q;i++){
        cin >> a >> b;
        query[i]={b,a,i};
    }
    sort(query.begin(),query.end());
    vector<int> unic(2e6+1,-1);
    vector<int> con(n+1);
    int last=0;
    for(int i=1;i<=n;i++){
        if(unic[nums[i]]!=-1){
            int x=unic[nums[i]];
            while(x<=n){
                con[x]--;
                x+=LsOne(x);
            }
        }
        unic[nums[i]]=i;
        int x=i;
        while(x<=n){
            con[x]++;
            x+=LsOne(x);
        }
        for(;last<q && query[last][0]==i;last++){
            int sum2=0,sum1=0;
            int x=i;
            while(x>0){
                sum2+=con[x];
                x-=LsOne(x);
            }
            x=query[last][1]-1;
            while(x>0){
                sum1+=con[x];
                x-=LsOne(x);
            }
            res[query[last][2]]=sum2-sum1;
        }
    }
    for(int i=0;i<q;i++){
        cout << res[i] << '\n';
    }
}