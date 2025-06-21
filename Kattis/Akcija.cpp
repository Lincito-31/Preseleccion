#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,con,nums[100000];
ll sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    for(int i=n-1;i>=0;i--,con++){
        if(con==2){
            con=-1;
            continue;
        }
        sum+=nums[i];
    }
    cout << sum;
}