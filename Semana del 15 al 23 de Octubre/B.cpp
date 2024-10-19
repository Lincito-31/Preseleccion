// https://codeforces.com/gym/104875/attachments  problem J
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
int n,a,t;
indexed_set hora;
int main(){
    scanf("%d",&n);
    vector<vi> nums(n,vi(3));
    vi res(n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&t);
        t+=a;
        nums[i]={a,t,i};
    }
    sort(ALL(nums));
    for(int i=1;i<n;i++){
        if(nums[i][0]==nums[i-1][0]){  
            int temp=nums[i][1];
            int temp2=nums[i][2];
            nums[i][1]=nums[i-1][1];
            nums[i][2]=nums[i-1][2];
            nums[i-1][1]=temp;
            nums[i-1][2]=temp2;
        }
    }
    for(int i=n-1;i>=0;i--){
        //hora.insert(nums[i][1]);
        int x=hora.order_of_key({nums[i][1]-1,nums[i][2]});
        if(x==i){
            res[nums[i][2]]=0;
        }else{
            res[nums[i][2]]=res[hora.find_by_order(x)->second]+1;
        }
        hora.insert({nums[i][1],nums[i][2]});
    }
    for(int i=0;i<n;i++){
        printf("%d ",res[i]);
    }
}
/*
4
1 8 2
2 10 1
4 9 3
5 7 4

2 6 1
2 4 3
3 6 2
4 6 4
4 5 5
*/