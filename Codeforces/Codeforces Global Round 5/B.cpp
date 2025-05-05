#include <bits/stdc++.h>
using namespace std;
int n,con,last;
int a[100000],pos[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i=0;i<n;i++){
        cin >> last;
        pos[--last]=i;
    }
    last=0;
    for(int i=0;i<n;i++){
        last=max(last,pos[a[i]]);
        if(pos[a[i]]<last){
            con++;
        }
    }
    cout << con;
}