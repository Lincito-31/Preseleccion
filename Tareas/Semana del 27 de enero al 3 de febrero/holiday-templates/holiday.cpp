#include"holiday.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;
ll findMaxAttraction(int n,int start,int d,int attraction[]){
    if(start==0){
        llset res;
        ll sum=0;
        ll maxi=0;
        for(ll i=0;i<(ll)((d+1)/2) && i<n;i++){
            res.insert(attraction[i]);
            sum+=attraction[i];
        }
        maxi=sum;
        for(ll i=(d+1)/2;i<n;i++){
            sum+=attraction[i];
            res.insert(attraction[i]);
            while(res.size()>0 && res.size()>d-i){
                sum-=*res.begin();
                res.erase(res.begin());
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    ll maxi=0;
    llset res;
    for(ll i=0;i<n;i++){
        res.clear();
        ll sum=0;
        for(ll j=i;j<n;j++){
            ll usado=0;
            if(i<=start && j<=start){
                usado=abs(start-i);
            }else if(i>start && j>start){
                usado=abs(start-j);
            }else{
                usado=2*min(abs(start-i),abs(start-j))+max(abs(start-i),abs(start-j));
            }
            sum+=attraction[j];
            res.insert(attraction[j]);
            while(res.size()>max(0ll,d-usado)){
                sum-=*res.begin();
                res.erase(res.begin());
            }
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}