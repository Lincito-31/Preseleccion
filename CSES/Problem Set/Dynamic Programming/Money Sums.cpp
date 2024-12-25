#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,arr[101],sum=0,dp[100001],con=0,vec[100001];
bool posi[100001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    for(int i=0;i<=sum;i++){
        posi[i]=vec[i]=false;
    }
    posi[0]=true;
    for(int i=0;i<n;i++){
        for(int j=sum;j>=0;j--){
            if(posi[j]){
                posi[arr[i]+j]=true;
            }
        }
    }
    for(int i=1;i<=sum;i++){
        if(posi[i]){
            vec[con]=i;
            con++;
        }
    }
    printf("%d\n",con);
    for(int i=0;i<=sum;i++){
        if(vec[i]){
            printf("%d ",vec[i]);
        }else{
            break;
        }
    }
}