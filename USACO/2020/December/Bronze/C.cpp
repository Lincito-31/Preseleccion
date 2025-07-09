#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,a,b;
vector<vector<int>> E,N;
char c;
int main(){
    cin >> n;
    vector<int> res(n);
    for(int i=0;i<n;i++){
        cin >> c >> a >> b;
        if(c=='E'){
            E.push_back({b,a,i});
        }else{
            N.push_back({a,b,i});
        }
    }
    sort(ALL(E));
    sort(ALL(N));
    for(int i=0;i<E.size();i++){
        swap(E[i][0],E[i][1]);
    }
    for(int i=0;i<E.size();i++){
        // procesar E[i];
        for(int j=0;j<N.size();j++){
            if(E[i][0]>N[j][0] || E[i][1]<N[j][1] || res[N[j][2]]!=0){
                continue;
            }
            int tE=N[j][0]-E[i][0];
            int tN=E[i][1]-N[j][1];
            if(tE<tN){
                res[N[j][2]]=tN;
                //pass;
            }else if(tE>tN){
                res[E[i][2]]=tE;
                break;
            }
        }
        if(res[E[i][2]]==0){
            res[E[i][2]]=1e9+7;
        }
    }
    for(int i=0;i<N.size();i++){
        // procesar N[i];
        for(int j=0;j<E.size();j++){
            if(E[j][0]>N[i][0] || E[j][1]<N[i][1] || res[E[j][2]]!=0){
                continue;
            }
            int tE=N[i][0]-E[j][0];
            int tN=E[j][1]-N[i][1];
            if(tN<tE){
                //pass;
                res[E[j][2]]=tE;
            }else if(tN>tE){
                res[N[i][2]]=tN;
                break;
            }
        }
        if(res[N[i][2]]==0){
            res[N[i][2]]=1e9+7;
        }
    }
    for(int i=0;i<n;i++){
        if(res[i]==1e9+7){
            cout << "Infinity\n";
        }else{
            cout << res[i] << '\n';
        }
    }
}