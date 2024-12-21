#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int t,r,g,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r,&g,&b);
        int res=0;
        int maxi=max(r,max(g,b));
        int mini=min(r,min(g,b));
        int mid=r+g-maxi-mini+b;
        int can=mid-mini;
        res+=can;
        mid-=can;
        maxi-=can;
        can=min(maxi/2,mini);
        mid-=can;
        mini-=can;
        maxi-=2*can;
        res+=2*can;
        res+=mini;
        printf("%d\n",res);
    }
}