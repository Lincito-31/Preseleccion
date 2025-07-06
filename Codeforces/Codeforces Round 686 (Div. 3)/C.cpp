#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int t,n,a;
int main(){
    scanf("%d",&t);
    while(t--){
        int mini=1e9;
        scanf("%d",&n);
        //vi nums(n);
        map<int,vi> posi;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            posi[a].push_back(i);
        }
        for(auto u:posi){
            int count=0;
            vi nums=u.second;
            nums.push_back(-1);
            nums.push_back(n);
            sort(ALL(nums));
            for(int i=1;i<nums.size();i++){
                if(nums[i]-nums[i-1]!=1){
                    count++;
                }
            }
            mini=min(mini,count);
        }
        printf("%d\n",mini);
    }
}