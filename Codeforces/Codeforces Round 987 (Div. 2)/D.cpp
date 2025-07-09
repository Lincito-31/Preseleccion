#include <bits/stdc++.h>
using namespace std;
int t,n;
vector<int> arb,masderecha,res,superres;
vector<pair<int,int>> maxiatras;
vector<bool> visitado;
int solve(int x){
    if(visitado[x]){
        return superres[x];
    }
    visitado[x]=true;
    superres[x]=maxiatras[x].first;
    if(res[arb[x]]>x){
        superres[x]=max(superres[x],superres[res[arb[x]]]);
    }
    superres[x]=max(superres[x],solve(maxiatras[x].second));
    return superres[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        arb.clear();
        arb.resize(n+1);
        masderecha=res=superres=arb;
        maxiatras.clear();
        maxiatras.resize(n+1);
        visitado.clear();
        visitado.resize(n+1);
        int maxi=0,inde=0;
        for(int i=0;i<n;i++){
            cin >> arb[i];
            if(arb[i]>maxi){
                maxi=arb[i];
                inde=i;
            }
            maxiatras[i]={maxi,inde};
            //cout << maxiatras[i].first << ' ' << maxiatras[i].second << '\n';
            masderecha[arb[i]]=max(masderecha[arb[i]],i);
        }
        maxi=0;
        for(int i=1;i<=n;i++){
            res[i]=maxi;
            maxi=max(maxi,masderecha[i]);
            //cout << res[i] << ' ';
        }
        for(int i=n-1;i>=0;i--){
            if(!visitado[i]){
                //cout << i << ' ';
                solve(i);
            }
        }
        //cout << masderecha[arb[0]];
        for(int i=0;i<n;i++){
            cout << superres[i] << ' ';
        }
        cout << '\n';
    }
}