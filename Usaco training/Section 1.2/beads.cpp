/*
ID: simplem2
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    char st[n+5];
    scanf("%s",st);
    string X(st);
    int con=0;
    for(int i=0;i<n;i++){
        if(X[i]=='w'){
            X[i]=X.back();
        }
        if(X[i]==X.back()){
            X.push_back(X[i]);
            con++;
        }else{
            break;
        }
        if(con>=n){
            break;
        }
    }
    n+=con;
    int temp=1;
    vector<int> val;
    if(X[con]=='w'){
        X[con]='b';
    }
    for(int i=con+1;i<n;i++){
        if(X[i]==X[i-1]){
            temp++;
        }else{
            if(X[i]=='w'){
                temp++;
                X[i]=X[i-1];
            }else{
                val.push_back(temp);
                cout << temp << " ";
                temp=1;
            }
        }
    }
    cout << temp << " ";
    val.push_back(temp);
    n=val.size();
    int maxi;
    if(val.size()==1){
        maxi=val[0];
    }else{
        maxi=val[0]+val.back();
    }
    for(int i=1;i<n;i++){
        maxi=max(maxi,val[i]+val[i-1]);
    }
    printf("%d\n",maxi);
}
