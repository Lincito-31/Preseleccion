#include <bits/stdc++.h>
using namespace std;
int res[1000000];
int solve(int x,int y,int z,int n){
    if(y==0){
        return 0;
    }
    if(z){
        return x%10+solve(x/10+y-1,y-1,z,n);
    }else{
        if(y==n){
            return x%10+solve(x/10+y-1,y-1,z+1,n);
        }else{
            return x%10+solve(x/10+y+1,y+1,z,n);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    res[0]=0;
    for(int i=1;i<10000;i++){
        res[i]=(int)(i/9)*81+(i%9)*(i%9);
        if(res[i]!=solve(1,1,0,i)){
            cout << i << endl;
        }
    }
}