#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,p,y,canti[2000];
pair<pair<int,int>,int> ranking[2000];
bitset<2000> x[2000];
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first){
        if(a.first.second==b.first.second){
            return a.second<b.second;
        }
        return a.first.second>b.first.second;
    }
    return a.first.first>b.first.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t >> p;
    p--;
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            cin >> y;
            x[i][j]=y;
            if(!y){
                canti[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        int con=0;
        for(int j=0;j<t;j++){
            if(x[i][j]){
                ranking[i].first.first+=canti[j];
                con++;
            }
        }
        ranking[i].first.second=con;
        ranking[i].second=i;
    }
    sort(ranking,ranking+n,cmp);
    for(int i=0;i<n;i++){
        if(ranking[i].second==p){
            cout << ranking[i].first.first << ' ' << i+1;
            break;
        }
    }
}