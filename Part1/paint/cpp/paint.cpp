#include "paint.h"
#include <bits/stdc++.h>
using namespace std;
int n,suma,m,dp[105][105];
string res;
vector<int> pos,revpos;
vector<int> psum;
string solve_puzzle(string s,vector<int> c) {
    n=s.size();
    m=c.size();
    pos.resize(m);
    revpos.resize(m);
    psum.resize(n+2);
    int last=0;
    res=s;
    for(int i=0;i<n;i++){
        bool xd=true;
        for(int j=0;j<c[last];j++){
            if(s[i+j]=='_'){
                xd=false;
                break;
            }
        }
        if(xd){
            pos[last]=i;
            i+=c[last];
            last++;
            if(last==m){
                break;
            }
        }
    }
    last=m-1;
    for(int i=n-1;i>=0;i--){
        bool xd=true;
        for(int j=0;j<c[last];j++){
            if(s[i-j]=='_'){
                xd=false;
                break;
            }
        }
        if(xd){
            revpos[last]=i;
            i-=c[last];
            last--;
            if(last==-1){
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        revpos[i]-=(c[i]-1);
    }
    for(int i=0;i<m;i++){
        for(int j=pos[i];j<=revpos[i];j++){
            bool xd=true;
            for(int k=0;k<c[i];k++){
                if(s[j+k]=='_'){
                    xd=false;
                    break;
                }
            }
            if(xd){
                // de pos[i] al revpos[i]+c[i]-1;
                psum[j]++;
                psum[j+c[i]]--;
            }
        }
    }
    // calcular cuantas formas hay en total
    // hasta pos i, con c[j];
    // hacer para j=1;
    for(int i=c[0];i<=n;i++){
        bool xd=true;
        dp[i][1]+=dp[i-1][1];
        for(int l=0;l<c[0];l++){
            if(s[i-l-1]=='_'){
                xd=false;
                break;
            }
        }
        if(xd){
            dp[i][1]++;
        }
    }
    for(int j=2;j<=m;j++){
        for(int i=c[j-1]+1;i<=n;i++){
            bool xd=true;
            dp[i][j]+=dp[i-1][j];
            for(int l=0;l<c[j-1];l++){
                if(s[i-l-1]=='_'){
                    xd=false;
                    break;
                }
            }
            if(xd){
                dp[i][j]+=dp[i-c[j-1]-1][j-1];
            }
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=psum[i];
        if(suma==dp[n][m]){
            res[i]='X';
        }else if(suma==0){
            res[i]='_';
        }else{
            res[i]='?';
        }
    }
    return res;
}
