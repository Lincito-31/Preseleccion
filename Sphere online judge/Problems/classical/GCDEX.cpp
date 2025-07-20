#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int x;
ll criba[1000001],psum[1000001],super[1000001],sssuper[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=1000000;i++){
        criba[i]=i;
    }
    for(int i=2;i<=1000000;i+=2){
        criba[i]-=criba[i]/2;
    }
    for(int i=3;i<=1000000;i+=2){
        if(criba[i]==i){
            for(int j=i;j<=1000000;j+=i){
                criba[j]-=criba[j]/i;
            }
        }
    }
    for(int i=1;i<=1000000;i++){
        for(int j=2*i;j<=1000000;j+=i){
            super[j]+=(ll)i*criba[j/i];
        }
    }
    for(int i=1;i<=1000000;i++){
        psum[i]=psum[i-1]+super[i];
    }
    while(cin >>x,x){
        cout << psum[x] << '\n';
    }
}