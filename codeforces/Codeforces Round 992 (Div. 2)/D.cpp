#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t=1,n,a,b;
vector<bool> criba(4e5+5,true);
int main(){
    criba[0]=criba[1]=false;
    for(int i=2;i*i<4e5+5;i++){
        if(criba[i]){
            for(int j=i+i;j<4e5+5;j+=i){
                criba[j]=false;
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vi graph[n];
        vi nums(n,0);
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        set<int> posi;
        for(int i=1;i<=2*n;i++){
            posi.insert(i);
        }
        nums[0]=1;
        queue<int> bfs;
        bfs.push(0);
        while(!bfs.empty()){
            int now=bfs.front();
            for(auto u:graph[now]){
                if()
            }
        }
    }
}