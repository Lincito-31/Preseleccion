#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vll a(N+2,0),b(N+2,0),ssum(N+2,0),de(N+2,0);
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    for(int i=1;i<=N;i++){
        cin >> b[i];
    }
    for(int i=N;i>=1;i--){
        if(de[i+1]-b[i]<a[i]){
            de[i]=a[i];
        }else{
            de[i]=de[i+1]-b[i];
        }
        de[i]=max(de[i],0ll);
        ssum[i]=ssum[i+1]+b[i];
    }
    ll res=1e9;
    for(int i=1;i<=N;i++){
        ll temp=0;
        if(de[i]+ssum[i]>=de[1]){
            temp=de[i];
        }else{
            temp=de[i]+de[1]-(de[i]+ssum[i]);
        }
        res=min(res,temp);
    }
    cout << res;
} 