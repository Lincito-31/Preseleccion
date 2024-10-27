// https://codeforces.com/gym/104875/attachments  problem J
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
    /*for(int i=1;i<n;i++){
        if(nums[i][0]==nums[i-1][0]){  
            int temp=nums[i][1];
            int temp2=nums[i][2];
            nums[i][1]=nums[i-1][1];
            nums[i][2]=nums[i-1][2];
            nums[i-1][1]=temp;
            nums[i-1][2]=temp2;
        }
    }*/
    set<pair<int,int>> gua;
    gua.insert({2e9,0});
    for(int i=0;i<n;i++){
        int b=nums[i].second;
        int c=-nums[i].first.second;
        auto q=gua.lower_bound({c,-2e9});
        res[b]=-((*q).second)+1;
        if((*q).first==c){
            gua.erase(q);
        }
        gua.insert({c,-res[b]});
        auto p=gua.lower_bound({c,res[b]});
        while(p!=gua.begin()){
            p--;
            if((*p).first<c && -(*p).second<=res[b]){
                gua.erase(p);
            }
        }
    }
    /*vector<int> cant(n+5,-1);
    cant[0]=nums[0][1];
    for(int i=1;i<n;i++){
        int limi=0,limd=n-1;
        while(limi!=limd){
            int mid=(limi+limd)/2;
            if(nums[i][1]<=cant[mid]){
                limi=mid+1;
            }else{
                limd=mid;
            }
        }
        while(limi>0){
            if(nums[i][1]>cant[limi]){
                limi--;
            }else{
                break;
            }
        }
        while(limi<n-1){
            if(nums[i][1]<=cant[limi]){
                limi++;
            }else{
                break;
            }
        }
        cant[limi]=nums[i][1];
        res[nums[i][2]]=limi;
    }*/
    for(auto u:res){
        printf("%d ",u-1);
    }
}