/*
ID: simplem2
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    scanf("%d",&n);
    char st[n+5];
    scanf("%s",st);
    string X(st);
    int con=0;
    int lastcolor=0;
    for(int i=n-1;i>=0;i--){
        if(X[i]=='b'){
            lastcolor=1;
            break;
        }else if(X[i]=='r'){
            lastcolor=2;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(con>=n){
            break;
        }
        if(X[i]=='b' && lastcolor==1){
            X.push_back(X[i]);
            con++;
        }else if(X[i]=='r' && lastcolor==2){
            X.push_back(X[i]);
            con++;
        }else if(X[i]==X.back() || X[i]=='w'){
            if(X[i]=='b'){
                lastcolor=1;
            }else if(X[i]=='r'){
                lastcolor=2;
            }
            X.push_back(X[i]);
            con++;
        }else{
            break;
        }
    }
    n+=con;
    int temp=1;
    vector<pair<int,int>> val;
    if(X[con]=='w'){
        X[con]='b';
    }
    for(int i=con+1;i<n;i++){
        if(X[i]==X[i-1]){
            temp++;
        }else{
            if(X[i-1]=='w'){
                val.push_back({temp,0});
            }else if(X[i-1]=='b'){
                val.push_back({temp,1});
            }else{
                val.push_back({temp,2});
            }
            temp=1;
        }
    }
    if(X[n-1]=='w'){
        val.push_back({temp,0});
    }else if(X[n-1]=='b'){
        val.push_back({temp,1});
    }else{
        val.push_back({temp,2});
    }
    n=val.size();
    vector<pair<int,int>> nue;
    for(int i=1;i<n-1;i++){
        if(val[i].second==0 && val[i-1].second==val[i+1].second){
            val[i].second=val[i-1].second;
        }
    }
    temp=val[0].first;
    for(int i=1;i<n;i++){
        if(val[i].second==val[i-1].second){
            temp+=val[i].first;
        }else{
            nue.push_back({temp,val[i-1].second});
            temp=val[i].first;
        }
    }
    nue.push_back({temp,val[n-1].second});
    n=nue.size();
    nue.push_back({0,0});
    nue.push_back({0,0});
    nue.push_back({0,0});
    nue.push_back({0,0});
    int maxi=0;
    maxi=nue[0].first;
    for(int i=0;i<n;i++){
        int temp=nue[i].first;
        if(nue[i].second==0){
            temp+=nue[i+1].first;
            if(nue[i+2].second==0){
                temp+=nue[i+2].first;
                temp+=nue[i+3].first;
                if(nue[i+4].second==0){
                    temp+=nue[i+4].first;
                }
            }else{
                temp+=nue[i+2].first;
                if(nue[i+3].second==0){
                    temp+=nue[i+3].first;
                }
            }
        }else{
            if(nue[i+1].second==0){
                temp+=nue[i+1].first;
                temp+=nue[i+2].first;
                if(nue[i+3].second==0){
                    temp+=nue[i+3].first;
                }
            }else{
                temp+=nue[i+1].first;
                if(nue[i+2].second==0){
                    temp+=nue[i+2].first;
                }
            }
        }
        maxi=max(maxi,temp);
    }
    printf("%d\n",maxi);
}
