#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int mat[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=0;
            }
        }
        int now=0,con=1;
        mat[(n-1)/2][(n-1)/2]=now++;
        while((n-1)/2+con<n){
            for(int i=(n-1)/2-con+1;i<(n-1)/2+con;i++){
                mat[i][(n-1)/2+con]=now++;
            }
            for(int i=(n-1)/2-con+1;i<(n-1)/2+con;i++){
                mat[(n-1)/2+con][i]=now++;
            }
            mat[(n-1)/2+con][(n-1)/2+con]=now++;
            if((n-1)/2-con<0){
                break;
            }
            for(int i=(n-1)/2-con+1;i<=(n-1)/2+con;i++){
                mat[i][(n-1)/2-con]=now++;
            }
            for(int i=(n-1)/2-con+1;i<=(n-1)/2+con;i++){
                mat[(n-1)/2-con][i]=now++;
            }
            mat[(n-1)/2-con][(n-1)/2-con]=now++;
            con++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}