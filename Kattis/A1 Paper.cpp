#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,con;
ll need;
double sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n-1);
    for(int i=0;i<n-1;i++){
        cin >> nums[i];
    }
    vector<pair<double,double>> longit(n-1);
    longit[0]={1/pow((double)2,(double)5/4),1/pow((double)2,(double)3/4)};
    for(int i=1;i<n-1;i++){
        longit[i]={longit[i-1].second/2,longit[i-1].first};
    }
    need=2;
    for(int i=0;i<n && need>0;i++){
        sum+=need/2*longit[i].second;
        need-=nums[i];
        need*=2;
    }
    if(need<=0){
        cout << fixed << setprecision(6) << sum;
    }else{
        cout << "impossible";
    }
}