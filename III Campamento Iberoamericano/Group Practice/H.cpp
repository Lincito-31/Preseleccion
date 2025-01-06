#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,res=1e9;
int main(){
    scanf("%d%d",&n,&m);
    vector<int> nums(n);
    set<int> conj;map<int,int> con;
    for(int i=0;i<=1e6+6e5;i++){
        conj.insert(i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(int i=0;i<m;i++){
        con[nums[i]]++;
        conj.erase(nums[i]);
    }
    res=*conj.begin();
    for(int i=m;i<n;i++){
        if(--con[nums[i-m]]==0){
            conj.insert(nums[i-m]);
        }
        con[nums[i]]++;
        conj.erase(nums[i]);
        res=min(res,*conj.begin());
    }
    printf("%d",res);
}