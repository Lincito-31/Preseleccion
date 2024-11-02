#include <bits/stdc++.h>
using namespace std;
int n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> st;
    int maxi=0;
    int now=1;
    for(int i=0;i<n;i++){
        if(st[i]=='L'){
            now--;
        }else if(st[i]=='R'){
            now++;
        }
        maxi=max(maxi,now);
    }
    string x(maxi,' ');
    int iz=0,de=0;
    int now=0;
    for(int i=0;i<n;i++){
        if(x[now]=='('){
            de--;
        }else if(x[now]==')'){
            de++;
        }
        if(st[i]=='L'){
            now--;
        }else if(st[i]=='R'){
            now++;
        }else if(st[i]=='('){
            de++;
        }else if(st[i]==')'){
            de--;
        }
    }
}