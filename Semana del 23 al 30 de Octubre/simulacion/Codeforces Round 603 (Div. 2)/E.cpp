#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    char st[n+5];
    scanf("%s",st);
    int maxi=0;
    int now=0;
    for(int i=0;i<n;i++){
        if(st[i]=='L'){
            now--;
        }else if(st[i]=='R'){
            now++;
        }
        maxi=max(maxi,now);
    }
}