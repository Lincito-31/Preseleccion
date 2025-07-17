#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll suma,tam1,tam2,nums1[20],nums2[20],res,x;
//map<int,int> mapa;
vector<int> nume;
void solve1(int pos,ll suma_now){
    if(suma_now>x){
        return;
    }
    if(pos==tam1){
        nume.push_back(suma_now);
        return;
    }
    solve1(pos+1,suma_now);
    solve1(pos+1,suma_now+nums1[pos]);
}
void solve2(int pos,ll suma_now){
    if(suma_now>x){
        return;
    }
    if(pos==tam2){
        res+=upper_bound(ALL(nume),x-suma_now)-lower_bound(ALL(nume),x-suma_now);
        return;
    }
    solve2(pos+1,suma_now);
    solve2(pos+1,suma_now+nums2[pos]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    tam2=n-(tam1=n/2);
    for(int i=0;i<tam1;i++){
        cin >> nums1[i];
    }
    for(int i=0;i<tam2;i++){
        cin >> nums2[i];
    }
    solve1(0,0);
    sort(ALL(nume));
    solve2(0,0);
    cout << res;
}