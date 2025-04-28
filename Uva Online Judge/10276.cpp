#include <bits/stdc++.h>
using namespace std;
int k,t,res=0;
vector<stack<int>> nums;
void solve(int x){
    res=max(res,x-1);
    for(int i=0;i<k;i++){
        if(nums[i].empty()){
            nums[i].push(x);
            solve(x+1);
            nums[i].pop();
            break;
        }else{
            int y=nums[i].top();
            if(pow((int)sqrt(y+x),2)==(y+x)){
                nums[i].push(x);
                solve(x+1);
                nums[i].pop();
                break;
            }
        }
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        nums.clear();
        nums.resize(k);
        solve(1);
        printf("%d\n",res);
    }
}