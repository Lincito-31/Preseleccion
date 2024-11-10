#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
int t=1,n,qx,qy;
int main(){
    scanf("%d",&t);
    while(t--){
        int x=0,y=0;
        scanf("%d%d%d",&n,&qx,&qy);
        string st;
        cin >> st;
        int con=1000;
        bool xd=false;
        while(con-- && !xd){
            for(int i=0;i<st.size();i++){
                if(st[i]=='E'){
                    x++;
                }
                if(st[i]=='N'){
                    y++;
                }
                if(st[i]=='S'){
                    y--;
                }
                if(st[i]=='W'){
                    x--;
                }
                if(x==qx && y==qy){
                    xd=true;
                    break;
                }
            }
        }
        if(xd){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}