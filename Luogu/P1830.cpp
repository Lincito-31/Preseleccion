#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,m,x,y,a,b;
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    vector<vi> bomb(x,vi(4));
    for(int i=0;i<x;i++){
        scanf("%d%d%d%d",&bomb[i][0],&bomb[i][1],&bomb[i][2],&bomb[i][3]);
    }
    while(y--){
        int con=0,last=-1;
        scanf("%d%d",&a,&b);
        for(int i=0;i<x;i++){
            if(bomb[i][0]<=a && a<=bomb[i][2] && bomb[i][1]<=b && b<=bomb[i][3]){
                con++;
                last=i+1;
            }
        }
        if(con>0){
            printf("Y %d %d\n",con,last);
        }else{
            printf("N\n");
        }
    }
}