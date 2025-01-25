#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    scanf("%d",&n);
    vector<int> nums(n);
    int x=0;
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        for(int j=0;j<=i;j++){
            x^=nums[i]+nums[j];
        }
    }
    printf("%d",x);
}