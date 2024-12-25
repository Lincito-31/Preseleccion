#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
int main(){
    scanf("%d",&n);
    int arr[n-1],sum=n*(n+1)/2,posi[sum+1];
    for(int i=0;i<n-1;i++){
        arr[i]=i+1;
    }
    for(int i=0;i<=sum;i++){
        posi[i]=0;
    }
    posi[0]=1;
    for(int i=0;i<n-1;i++){
        for(int j=sum;j>=0;j--){
            if(j-arr[i]>=0){
                posi[j]+=posi[j-arr[i]];
                posi[j]%=MOD;
            }else{
                break;
            }
        }
    }
    if(sum%2==0){
        printf("%lld",posi[sum/2]);
    }else{
        printf("0");
    }
}