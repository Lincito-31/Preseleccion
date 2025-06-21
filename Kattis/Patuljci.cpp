#include <bits/stdc++.h>
using namespace std;
int nums[9];
vector<int> used;
void solve(int pos,int cant,int sum){
    if(cant==7){
        if(sum==100){
            for(int i=0;i<7;i++){
                cout << used[i] << '\n';
            }
        }
        return;
    }
    if(pos==9 || sum>100){
        return;
    }
    solve(pos+1,cant,sum);
    used.push_back(nums[pos]);
    solve(pos+1,cant+1,sum+used.back());
    used.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<9;i++){
        cin >> nums[i];
    }
    solve(0,0,0);
}