#include <bits/stdc++.h>
using namespace std;
int N,a,b,g,k,con,targx,targy;
int main(){
    scanf("%d",&N);
    vector<vector<int>> nums(N);
    con=N;
    while(N--){
        scanf("%d%d%d%d",&a,&b,&g,&k);
        nums[N]={a,b,g+a-1,k+b-1};
    }
    scanf("%d%d",&targx,&targy);
    for(auto u:nums){
        if(u[0]<=targx&&targx<=u[2] && u[1]<=targy&&targy<=u[3]){
            printf("%d",con);
            return 0;
        }
        con--;
    }
    printf("-1");
}