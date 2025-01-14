#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int l=1,r=1e9;
    while(l<r){
        int mid=(l+r+1)>>1;
        vector<int> ps(n),mini(n);
        ps[0]=(nums[0]>=mid?1:-1);
        mini[0]=min(0,ps[0]);
        bool xd=false;
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+(nums[i]>=mid?1:-1);
            mini[i]=min(mini[i-1],ps[i]);
            if(i==k-1 && ps[i]>0){
                xd=true;
                break;
            }else if(i>=k){
                if(ps[i]-mini[i-k]>0){
                    xd=true;
                    break;
                }
            }
        }
        if(xd){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%d",l);
}