#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    vector<int> nums(n);
    vector<int> existe(n,0);
    vector<int> diferentes(n,0);
    vector<pair<int,int>> last(n,{-1,-1});
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        nums[i]--;
        if(last[nums[i]]==make_pair(-1,-1)){
            last[nums[i]]={i,-1};
        }else{
            last[nums[i]].second=last[nums[i]].first;
            last[nums[i]].first=i;
        }
        if(i>0){
            diferentes[i]=diferentes[i-1];
        }
        if(existe[nums[i]]==0){
            diferentes[i]++;
        }
        existe[nums[i]]++;
    }
    long long canti=0;
    for(int i=0;i<n;i++){
        if(last[i].second!=-1){
            if(last[i].second-1>=0){
                canti+=(long long)diferentes[last[i].second-1];
                if(existe[i]>2){
                    canti--;
                }
            }
        }
    }
    printf("%lld",canti);
}