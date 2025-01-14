#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    n=n>>1;
    vector<int> d(n),u(n);
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
        scanf("%d",&u[i]);
        u[i]=k-u[i]+1;
    }
    sort(ALL(d));
    sort(ALL(u));
    int cantidad=0,res=1e9;
    for(int i=1;i<=k;i++){
        int x=lower_bound(ALL(d),i)-d.begin();
        int canti=n-x;
        if(canti>res){
            continue;
        }
        int y=upper_bound(ALL(u),i)-u.begin();
        canti+=y;
        if(canti<res){
            res=canti;
            cantidad=1;
        }else if(res==canti){
            cantidad++;
        }
    }
    printf("%d %d",res,cantidad);
}