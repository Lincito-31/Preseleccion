#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int n,j=0,now=0,k;
ll r=0;
map<int,int> con;
int main(){ 
    scanf("%d%d",&n,&k); 
    int nums[n];
    for(int i=0;i<n;i++){ 
        scanf("%d",&nums[i]); 
    }
    for(int i=0;i<n;i++){
        while(now<=k && j<n){
            if(con[nums[j]]==0){
                now++;
            }
            con[nums[j]]++;
            j++;
        }
        if(now>k){
            now--;
            j--;
            con[nums[j]]--;
        }
        r+=j-i;
        con[nums[i]]--;
        if(con[nums[i]]==0){
            now--;
        }
    }
    printf("%lld",r);
}