#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int t=1,n;
vector<vi> posinums(1000);
vector<vi> Div;
vector<vi> dp;
int main(){
    while(t--){
        scanf("%d",&n);
        Div.resize(n);
        dp.assign(n,vi(1000,1e9));
        vi nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    Div[i].push_back(j);
                    posinums[j].push_back(i);
                    while(nums[i]%j==0){
                        nums[i]/=j;
                    }
                }
            }
            if(nums[i]>1){
                Div[i].push_back(nums[i]);
                posinums[nums[i]].push_back(i);
            }
        }
    }
    ll res=0;
    // ya no puedo xd
    /*for(int i=0;){

    }*/
    /*for(int i=0;i<n;i++){
        for(auto u:Div[i]){
            printf("%d ",u);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<1000;i++){
        if(posinums[i].empty()){
            continue;
        }
        printf("%d:",i);
        for(auto u:posinums[i]){
            printf("%d ",u);
        }
        printf("\n");
    }*/
    
}