#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef vector<long long> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
vector<long long> fib(50);
int main(){
    priority_queue<vll> q;
    q.push({-2,0,1,5,4});
    q.push({-100,0,1,5,4});
    q.push({56,0,1,5,4});
    q.push({1000,0,1,5,4});
    q.push({3,0,1,5,4});
    while(!q.empty()){
        vll x=q.top();
        q.pop();
        cout << x[0] << " " << x[1] << " " << x[2] << x[3] << endl;
    }
}