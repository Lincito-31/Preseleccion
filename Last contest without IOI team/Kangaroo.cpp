#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> inteset;
int n,s,e;
typedef long long ll;
// queda iz, queda de, k=0:fina en iz,k=1:fina en de, l=0:salto iz,l=1:salto de;
/*
sol2:
dp[now][fin][tipo]
si estoy en now quiero saltar a fin e ir a izquierda
*/
ll dp[2001][2001][2][2];
/*ll solve(int canti,int now,int fin,int tipo){
    
}*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s >> e;
    //cout << solve(s,e,);
    cout << "XD";
}