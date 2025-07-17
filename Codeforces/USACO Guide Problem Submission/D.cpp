#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a,b,c;
int main(){
    cin >> n >> m;
    vector<vector<int>> op(n),query(m);
    vector<ll> nums,nue;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        op[i]={a,b,c};
        nums.push_back(a);
        nums.push_back(b);
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        query[i]={a,b};
        nums.push_back(a);
        nums.push_back(b);
    }
    sort(ALL(nums));
    nue.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nue.push_back(nums[i]);
        }
    }
    nums=nue;
    vector<ll> psum(nums.size()+1),superpsum(nums.size()+1);
    for(int i=0;i<n;i++){
        psum[lower_bound(ALL(nums),op[i][0])-nums.begin()]+=op[i][2];
        psum[lower_bound(ALL(nums),op[i][1])-nums.begin()]-=op[i][2];
    }
    for(int i=1;i<psum.size();i++){
        psum[i]+=psum[i-1];
    }
    /*for(int i=0;i<psum.size();i++){
        cout << psum[i] << ' ';
    }*/
    superpsum[0]=psum[0];
    for(int i=1;i<nums.size();i++){
        superpsum[i]=superpsum[i-1]+(nums[i]-nums[i-1]-1)*psum[i-1]+psum[i];
        //cout << superpsum[i] << ' ';
    }
    cout << endl;
    for(int i=0;i<m;i++){
        int x=lower_bound(ALL(nums),query[i][0])-nums.begin();
        int y=lower_bound(ALL(nums),query[i][1])-nums.begin();
        cout << superpsum[y]-superpsum[x]+psum[x]-psum[y] << '\n';
    }
}