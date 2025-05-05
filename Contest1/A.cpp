#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
int n;
ll maxi=0,sum=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<pair<ll,ll>,ll>> spots(n);
    for(int i=0;i<n;i++){
        cin >> spots[i].first.first >> spots[i].first.second >> spots[i].second;
    }
    //sort(ALL(spots));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<ll,ll> pendiente={spots[i].first.first-spots[j].first.first,spots[i].first.second-spots[j].first.second};
            for(int k=j+1;k<n;k++){
                // pertenecen a la misma recta?
                if(pendiente.first==0){
                    if(spots[i].first.first==spots[k].first.first){
                        continue;
                    }
                }else{
                    if(pendiente.second*(spots[k].first.first-spots[i].first.first)+spots[i].first.second*pendiente.first==spots[k].first.second*pendiente.first){
                        continue;
                    }
                }
                sum=spots[i].second+spots[j].second+spots[k].second;
                for(int l=k+1;l<n;l++){
                    if(pendiente.first==0){
                        if(spots[l].first.first<=spots[i].first.first && spots[l].first.first>=spots[k].first.first){
                            sum+=spots[l].second;
                        }
                        if(spots[l].first.first>=spots[i].first.first && spots[l].first.first<=spots[k].first.first){
                            sum+=spots[l].second;
                        }
                    }else{
                        if(pendiente.second*(spots[l].first.first-spots[i].first.first)+spots[i].first.second*pendiente.first>=spots[l].first.second*pendiente.first && pendiente.second*(spots[l].first.first-spots[k].first.first)+spots[k].first.second*pendiente.first<=spots[l].first.second*pendiente.first){
                            sum+=spots[l].second;
                        }
                        if(pendiente.second*(spots[l].first.first-spots[i].first.first)+spots[i].first.second*pendiente.first<=spots[l].first.second*pendiente.first && pendiente.second*(spots[l].first.first-spots[k].first.first)+spots[k].first.second*pendiente.first>=spots[l].first.second*pendiente.first){
                            sum+=spots[l].second;
                        }
                    }
                }
                maxi=max(maxi,sum);
            }
        }
    }
    /*sort(ALL(spots));
    for(int i=0;i<n;i++){
        sum=max(spots[i].second,sum+spots[i].second);
        maxi=max(maxi,sum);
    }*/
    cout << maxi;
}