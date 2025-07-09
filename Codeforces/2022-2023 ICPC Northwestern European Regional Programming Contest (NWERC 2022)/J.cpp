#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,a,t;
int main(){
    scanf("%d",&n);
    vector<pair<pair<int,int>,int>> nums(n);
    vi res(n,0);
    for(int i=0;i<n;i++){
        scanf("%d%d",&nums[i].first.first,&nums[i].first.second);
        nums[i].first.second+=nums[i].first.first;
        nums[i].first.second*=-1;
        nums[i].second=i;
    }
    sort(ALL(nums));
    vector<int> cant(n,-1);
    cant[0]=-nums[0].first.second;
    for(int i=1;i<n;i++){
        int limi=0,limd=n-1;
        while(limi!=limd){
            int mid=(limi+limd)/2;
            if(-nums[i].first.second<=cant[mid]){
                limi=mid+1;
            }else{
                limd=mid;
            }
        }
        cant[limi]=-nums[i].first.second;
        res[nums[i].second]=limi;
    }
    for(int i=0;i<n;i++){
        printf("%d ",res[i]);
    }
}