#include <bits/stdc++.h>
using namespace std;
int t,n,a;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    scanf("%d",&t);
    while(t--){
        map<int,pair<int,int>> x;
        scanf("%d",&n);
        vector<int> nums(n);
        vector<int> res(n+1,1);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        double chance=0;
        for(int i=0;i<n;i++){
            int aa=uniform_int_distribution<int>(0,10000)(rng);
            if(aa<=4444){
                for(int j=1;j*j<=nums[i] && j<=100;j++){
                    if(nums[i]%j==0){
                        int k=j;
                        if(x.count(k)==0){
                            x[k]={i,1};
                            res[1]=max(res[1],k);
                        }else{
                            if(x[k].first==(i-1)){
                                x[k].first++;
                                x[k].second++;
                                res[x[k].second]=max(res[x[k].second],k);
                            }else{
                                x[k]={i,1};
                            }
                        }
                        if(nums[i]/j==j){
                            continue;
                        }
                        k=nums[i]/j;
                        if(x.count(k)==0){
                            x[k]={i,1};
                            res[1]=max(res[1],k);
                        }else{
                            if(x[k].first==(i-1)){
                                x[k].first++;
                                x[k].second++;
                                res[x[k].second]=max(res[x[k].second],k);
                            }else{
                                x[k]={i,1};
                            }
                        }
                    }
                }
            }else{
                for(int j=1;j*j<=nums[i] && j<=3000;j++){
                    if(nums[i]%j==0){
                        int k=j;
                        if(x.count(k)==0){
                            x[k]={i,1};
                            res[1]=max(res[1],k);
                        }else{
                            if(x[k].first==(i-1)){
                                x[k].first++;
                                x[k].second++;
                                res[x[k].second]=max(res[x[k].second],k);
                            }else{
                                x[k]={i,1};
                            }
                        }
                        if(nums[i]/j==j){
                            continue;
                        }
                        k=nums[i]/j;
                        if(x.count(k)==0){
                            x[k]={i,1};
                            res[1]=max(res[1],k);
                        }else{
                            if(x[k].first==(i-1)){
                                x[k].first++;
                                x[k].second++;
                                res[x[k].second]=max(res[x[k].second],k);
                            }else{
                                x[k]={i,1};
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
}