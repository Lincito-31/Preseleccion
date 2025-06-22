#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
int n,m,con,nums[100001],visited[100002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> nums[i];
        visited[nums[i]]=true;
    }
    nums[m]=n+1;
    for(int i=0;i<m;i++){
        while(visited[++con]);
        if(con<nums[i]){
            cout << con << '\n';
            i--;
        }else{
            cout << nums[i] << '\n';
            con--;
        }
    }
    for(;con<=n;con++){
        if(!visited[con]){
            cout << con << '\n';
        }
    }
}