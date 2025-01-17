#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,k,a,m,canti=0,b,con=0;
int main(){
    scanf("%d%d%d",&n,&k,&a);
    set<int> lim;
    lim.insert(0);
    lim.insert(n+1);
    canti=n/(a+1);
    n%=(a+1);
    if(n==a){
        canti++;
    }
    scanf("%d",&m);
    while(con<m){
        scanf("%d",&b);
        auto p=lim.lower_bound(b);
        auto pp=p;
        pp--;
        int ori=(*p-1)-(*pp+1)+1;
        canti-=ori/(a+1);
        ori%=(a+1);
        if(ori==a){
            canti--;
        }
        int nue1=(*p-1)-(b+1)+1;
        canti+=nue1/(a+1);
        nue1%=(a+1);
        if(nue1==a){
            canti++;
        }
        int nue2=(b-1)-(*pp+1)+1;
        canti+=nue2/(a+1);
        nue2%=(a+1);
        if(nue2==a){
            canti++;
        }
        lim.insert(b);
        con++;
        if(canti<k){
            printf("%d",con);
            return 0;
        }
    }
    printf("-1");
}