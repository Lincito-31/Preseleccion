#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,k,m,sum,res=1e9;
bool dp[90001],xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    if(k>m){
        cout << "Impossible";
        return 0;
    }
    vector<int> food(n);
    for(int i=0;i<n;i++){
        cin >> food[i];
        if(food[i]<k){
            cout << "Impossible";
            return 0;
        }
        sum+=food[i];
    }
    vector<int> chef(m);
    for(int i=0;i<m;i++){
        cin >> chef[i];
    }
    if(m<=15){
        sort(ALL(chef));
        for(int i=1;i<(1<<m);i++){
            xd=true;
            if(__builtin_popcount(i)<k){
                continue;
            }
            vector<int> temp;
            for(int j=14;j>=0;j--){
                if(i&(1<<j)){
                    temp.push_back(chef[j]);
                }
            }
            for(int j=0;j<n && xd;j++){
                for(int l=temp.size()-k;l<temp.size();l++){
                    if(temp[l]==0){
                        xd=false;
                        break;
                    }
                    temp[l]--;
                    int now=l;
                    while(now-1>=0 && temp[now]<temp[now-1]){
                        swap(temp[now],temp[now-1]);
                    }
                }
            }
            if(xd){
                int nuesum=0;
                for(auto u:temp){
                    nuesum+=u;
                }
                if(nuesum+n*k>=sum){
                    res=min(res,nuesum+n*k-sum);
                }
            }
        }
        if(res==1e9){
            cout << "Impossible";
        }else{
            cout << res;
        }
    }else{
        dp[0]=true;
        for(int i=0;i<m;i++){
            for(int j=90000;j>=0;j--){
                if(j-chef[i]>=0){
                    dp[j]|=dp[j-chef[i]];
                }
            }
        }
        for(int i=sum;i<=90000;i++){
            if(dp[i]){
                cout << i-sum;
                return 0;
            }
        }
        cout << "Impossible";
    }
}