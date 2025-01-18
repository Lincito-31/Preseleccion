#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,a,b,c,d,x1,x2,yy1,y2,x,y;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&yy1,&x2,&y2);
        if((y==yy1 && y==y2 &&(c+d)>0)||(x==x1 && x==x2 && (a+b)>0)){
            printf("No\n");
            continue;
        }
        if(a>=b){
            a-=b;
            x-=a;
            if(c>=d){
                c-=d;
                y-=c;
                
            }else{
                d-=c;
                y+=d;
            }
        }else{
            b-=a;
            x+=b;
            if(c>=d){
                c-=d;
                y-=c;
                
            }else{
                d-=c;
                y+=d;
            }
        }
        if(!(x1<=x && x<=x2 && yy1<=y && y<=y2)){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
}