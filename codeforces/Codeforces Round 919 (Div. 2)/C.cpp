#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        int con=0;
        scanf("%d",&n);
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        int mcd=0;
        for(int i=1;i*i<=n;i++){
            int x=i;
            if(n%x==0){
                mcd=0;
                for(int j=1;j<n/x;j++){
                    for(int k=0;k<x;k++){
                        mcd=gcd(mcd,nums[j*x+k]-nums[(j-1)*x+k]);
                    }
                }
                if(mcd!=1){
                    con++;
                }
                mcd=0;
                if(x==n/x){
                    continue;
                }
                x=n/x;
                for(int j=1;j<n/x;j++){
                    for(int k=0;k<x;k++){
                        mcd=gcd(mcd,nums[j*x+k]-nums[(j-1)*x+k]);
                    }
                }
                if(mcd!=1){
                    con++;
                }
            }
        }
        printf("%d\n",con);
    }
}