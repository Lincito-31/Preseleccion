#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll ax,bx,ay,by,dist;
int n;
char ch;
int main(){ 
    scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
    dist=abs(ax-bx)+abs(ay-by);
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&ch);
        if(ch=='U'){
            if(ay<by){
                nums[i]=-1;
            }else{
                nums[i]=1;
            }
        }else if(ch=='D'){
            if(ay>by){
                nums[i]=-1;
            }else{
                nums[i]=1;
            }
        }else if(ch=='L'){
            if(ax>bx){
                nums[i]=-1;
            }else{
                nums[i]=1;
            }
        }else{
            if(ax<bx){
                nums[i]=-1;
            }else{
                nums[i]=1;
            }
        }
    }
}