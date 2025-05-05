#include <bits/stdc++.h>
using namespace std;
int n;
string a[20];
bool cmp(string x,string y){
    if(x==y){
        return true;
    }
    for(int i=0;i<min(x.size(),y.size());i++){
        if(x[i]!=y[i]){
            return x>y;
        }
    }
    if(x.size()>y.size()){
        for(int i=y.size();i<x.size();i++){
            if(x[y.size()]>x[i-y.size()]){
                return true;
            }
        }
        return false;
    }else{
        for(int i=x.size();i<y.size();i++){
            if(y[x.size()]>y[i-x.size()]){
                return false;
            }
        }
        return true;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout << a[i];
    }
}