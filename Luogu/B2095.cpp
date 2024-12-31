#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
float sum=0,maxi=0,mini=1e5,prom,abso=0,maxind,miniind;
int main(){
    scanf("%d",&n);
    float nums[n];
    for(int i=0;i<n;i++){
        scanf("%f",&nums[i]);
        if(nums[i]<mini){
            mini=nums[i];
            miniind=i;
        }
        if(nums[i]>maxi){
            maxi=nums[i];
            maxind=i;
        }
        sum+=nums[i];
    }
    sum-=(maxi+mini);
    prom=sum/(n-2);
    sum=0;
    for(int i=0;i<n;i++){
        if(i==miniind || i==maxind){
            continue;
        }
        abso=max(abso,abs(prom-nums[i]));
    }
    printf("%.2f %.2f",prom,abso);
}