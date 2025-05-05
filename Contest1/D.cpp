#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
int n,k,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    vector<pair<int,int>> fish(n);
    for(int i=0;i<n;i++){
        cin >> fish[i].first >> fish[i].second;
    }
    for(int i=1;i<n;i++){
        if(fish[i].second+fish[i-1].second==1){
            if(fish[i].second==1 && fish[i].first>fish[i-1].first){
                swap(fish[i].first,fish[i-1].first);
            }else if(fish[i-1].second==1 && fish[i-1].first>fish[i].first){
                swap(fish[i].first,fish[i-1].first);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(fish[i].second==1 && fish[i].first<=k){
            con++;
        }
        if(fish[i].second==0 && fish[i].first>k){
            con++;
        }
    }
    cout << con;
}