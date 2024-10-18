#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int main(){
    string x;
    getline(cin,x);
    string z;
    //z << x;
    stringstream in(x);
    while(in>>z){
        cout << z << "1 ";
    }
}