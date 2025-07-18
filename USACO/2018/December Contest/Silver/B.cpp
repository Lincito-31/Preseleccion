#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,a,b,t,maxi;
int main(){
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    cin >> n;
    vector<vector<ll>> cows(n);
    priority_queue<vector<ll>> pq;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        cows[i]={a,b,i};
    }
    sort(ALL(cows));
    int l=0;
    while(l<n){
        t=cows[l][0];
        pq.push({-cows[l][2],cows[l][0],cows[l][1]});
        l++;
        while(!pq.empty()){
            vector<ll> ant=pq.top();
            pq.pop();
            maxi=max(maxi,t-ant[1]);
            t+=ant[2];
            while(l<n){
                if(cows[l][0]<=t){
                    pq.push({-cows[l][2],cows[l][0],cows[l][1]});
                    l++;
                }else{
                    break;
                }
            }
        }
    }
    cout << maxi;
}