#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int>> nums(n);
        vector<int> pos(2*n);
        vector<bool> used(2*n,false);
        for(int i=0;i<n;i++){
            cin >> nums[i].first;
            pos[--nums[i].first]=i;
        }
        for(int i=0;i<n;i++){
            cin >> nums[i].second;
            pos[--nums[i].second]=i;
        }
        int now=0;
        for(int i=0;i<n;i++){
            while(used[now++]);
            now--;
            pair<int,int> temp=nums[pos[now]];
            //swap(nums[pos[now]],nums[i]);
            int nuevpos=pos[now];
            nums[pos[now]]=nums[i];
            nums[i]=temp;
            pos[nums[i].first]=pos[nums[i].second]=i;
            pos[nums[nuevpos].first]=pos[nums[nuevpos].second]=nuevpos;
            used[nums[i].first]=used[nums[i].second]=true;
        }
        bool xd=true;
        for(int i=1;i<n-1 && xd;i++){
            if(nums[i].first>nums[i-1].first&&nums[i].second>nums[i-1].second){
                //nada
            }else{
                swap(nums[i].first,nums[i].second);
                swap(nums[i+1].first,nums[i+1].second);
                if(nums[i].first>nums[i-1].first&&nums[i].second>nums[i-1].second){
                    //nada
                }else{
                    xd=false;
                }
            }
        }
        if(xd){
            int last=n-1;
            while(!(nums[last].first>nums[last-1].first&&nums[last].second>nums[last-1].second)){
                if(last==1){
                    xd=false;
                    break;
                }
                swap(nums[last-1].first,nums[last-1].second);
                swap(nums[last-2].first,nums[last-2].second);
                if(!(nums[last].first>nums[last-1].first&&nums[last].second>nums[last-1].second)){
                    xd=false;
                    break;
                }
                last-=2;
                if(last==0){
                    break;
                }
            }
        }
        if(xd){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}