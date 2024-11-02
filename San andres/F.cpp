#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexedset;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,m,a,b;
int main(){
    scanf("%d%d",&n,&m);
    vector<pair<int,int>> arm(n);
    for(int i=0;i<n;i++){
        scanf("%d",&arm[i].second);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        arm[i].first=arm[i].second-a;
    }
    sort(arm.begin(),arm.end());
    int now=arm[0].first;
    for(int i=1;i<n;i++){
        if(arm[i].first==now){
            arm[i]={1e9,1e9};
        }else{
            now=arm[i].first;
        }
    }
    sort(arm.begin(),arm.end());
    for(int i=0;i<n;i++){
        int temp=arm[i].first;
        arm[i].first=arm[i].second;
        arm[i].second=temp;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&a);
        int iz=0,de=n-1;
        while(iz<de){
            int mid=(iz+de)/2;
            if(arm[])
        }
    }
}