/*
ID: simplem2
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n,a,b,maxi1,maxi2,mini=1e9;
int con[1000002];
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        mini=min(a,mini);
        con[a]++;
        con[b]--;
    }
    a=b=0;
    for(int i=1;i<=1000000;i++){
        con[i]+=con[i-1];
    }
    for(int i=0;i<=1000000;i++){
        if(con[i]>0){
            a++;
            if(i>=mini){
                maxi2=max(maxi2,b);
                b=0;
            }
        }else{
            maxi1=max(maxi1,a);
            a=0;
            if(i>=mini){
                b++;
            }
        }
    }
    cout << maxi1 << ' ' << maxi2 << '\n';
}
