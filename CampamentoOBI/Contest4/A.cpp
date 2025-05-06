#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a,b,suma=0,sumatemp=0;
string S;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    map<ll,ll> contador;
    vector<ll> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        sumatemp+=nums[i];
        if(!contador.count(nums[i])){
            contador[nums[i]]=1;
        }else{
            contador[nums[i]]++;
        }
    }
    cin >> q;
    while(q--){
        cin >> S;
        if(S=="INFLATION"){
            cin >> a;
            suma+=a;
        }else{
            cin >> a >> b;
            if(a!=b){
                ll x=a-suma;
                sumatemp+=contador[x]*(b-a);
                contador[b-suma]+=contador[a-suma];
                contador[a-suma]=0;
            }
        }
        cout << sumatemp+suma*n << "\n";
    }
}
/*
3
1 4 1
5
SET 1 1
SET 3 4
INFLATION 2
SET 3 1
SET 6 4

6
6
12
8
6
*/