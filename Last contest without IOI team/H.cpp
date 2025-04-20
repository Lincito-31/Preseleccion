#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,m,d,k,con=0;
int main(){
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> d >> k;
    vector<vector<char>> garden(n+1,vector<char>(m+1));
    vector<vector<int>> psum(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> garden[i][j];
            if(garden[i][j]=='S'){
                psum[max(i-d,0)][max(j-d,0)]++;
                psum[min(i+d+1,n)][min(j+d+1,m)]++;
                psum[max(i-d,0)][min(j+d+1,m)]--;
                psum[min(i+d+1,n)][max(j-d,0)]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            psum[i][j]+=psum[i][j-1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            psum[i][j]+=psum[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout << psum[i][j] << " ";
            if(garden[i][j]=='M' && psum[i][j]>=k){
                con++;
            }
        }
        //cout << endl;
    }
    cout << con;
}