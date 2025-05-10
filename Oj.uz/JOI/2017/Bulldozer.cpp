#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef __int128_t lll;
lll maxi;
ll n,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<vector<lll>> points(n,{0,0,0});
    for(lll i=0;i<n;i++){
        cin >> x;
        points[i][0]=x;
        cin >> x;
        points[i][1]=x;
        cin >> x;
        points[i][2]=x;
    }
    vector<pair<lll,lll>> nums(n);
    for(lll i=0;i<n;i++){
        for(lll j=i+1;j<n;j++){
            pair<lll,lll> pendiente={points[j][1]-points[i][1],points[j][0]-points[i][0]};
            nums.clear();
            nums.resize(n);
            if(pendiente.second==0){
                //hori
                for(int k=0;k<n;k++){
                    nums[k]={points[k][1],points[k][2]};
                }
                sort(ALL(nums));
                lll sum=0;
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
                sum=0;
                for(int k=1;k<n;k++){
                    if(nums[k].first==nums[k-1].first){
                        swap(nums[k],nums[k-1]);
                    }
                }
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
            }
            if(pendiente.first==0){
                //vertical
                for(int k=0;k<n;k++){
                    nums[k]={points[k][0],points[k][2]};
                }
                sort(ALL(nums));
                lll sum=0;
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
                sum=0;
                for(int k=1;k<n;k++){
                    if(nums[k].first==nums[k-1].first){
                        swap(nums[k],nums[k-1]);
                    }
                }
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
            }else{
                for(lll k=0;k<n;k++){
                    nums[k]={pendiente.first*points[k][0]-pendiente.second*points[k][1],points[k][2]};
                }
                sort(ALL(nums));
                lll sum=0;
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
                sum=0;
                for(int k=1;k<n;k++){
                    if(nums[k].first==nums[k-1].first){
                        swap(nums[k],nums[k-1]);
                    }
                }
                for(int k=0;k<n;k++){
                    maxi=max(maxi,sum=max(nums[k].second,sum+nums[k].second));
                }
            }
        }
    }
    cout << (ll)maxi;
}