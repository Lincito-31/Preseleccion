/*
ID: simplem2
TASK: wormhole
LANG: C++
*/
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<pair<int,int>> hole;
vector<int> to;
int used,cont,n,m;
// 0 0
// 0 1
// 1 0
// 1 1
bool check(){
    for(int i=0;i<n;i++){
        int visited=0;
        int ini=to[i];
        /*if(ini>0){
            if(hole[ini-1].first==hole[ini].first && hole[ini-1].second==hole[ini].second-1){
                continue;
            }
        }*/
        while(true){
            //cout << ini << ' ';
            if(visited&(1<<ini)){
                return true;
            }
            visited|=(1<<ini);
            if(ini!=n-1){
                if(hole[ini].first==hole[ini+1].first){
                    ini=to[ini+1];
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    return false;
}
void pairwise(int con){
    if(con==n/2){
        /*for(int i=0;i<n;i++){
            cout << to[i] << ' ';
        }
        cout << '\n';*/
        if(check()){
            cont++;
        }
        //cout << endl << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!(used&(1<<i))){
            used|=(1<<i);
            for(int j=0;j<n;j++){
                if(!(used&(1<<j))){
                    used|=(1<<j);
                    to[i]=j;
                    to[j]=i;
                    pairwise(con+1);
                    used-=(1<<j);
                }
            }
            used-=(1<<i);
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin >> n;
    hole.resize(n);
    to.resize(n);
    for(int i=0;i<n;i++){
        cin >> hole[i].second >> hole[i].first;
    }
    sort(ALL(hole));
    pairwise(0);
    cout << cont << '\n';
}
