#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int t,n,a,b;
vector<vi> graph;
int maxi,node,res;
void dfs(int now,int ante,int con){
    //cout << now << ":" << con << endl;
    if(con>maxi){
        node=now;
        maxi=con;
        //cout << con << ">" << maxi << endl;
    }
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs(u,now,con+graph[u].size()-2);
    }
}
void dfs2(int now,int ante,int con){
    res=max(res,con);
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs2(u,now,con+graph[u].size()-2);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        maxi=0,node=-1,res=-1;
        scanf("%d",&n);
        graph.clear();
        graph.resize(n+5);
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        /*for(int i=0;i<n;i++){
            if(graph[i].size()>maxi){
                //cout << i << " ";
                node=i;
                maxi=graph[i].size();
                
            }
        }*/
        dfs(1,-1,graph[1].size());
        dfs2(node,-1,graph[node].size());
        dfs(0,-1,graph[0].size());
        dfs2(node,-1,graph[node].size());
        dfs(2,-1,graph[2].size());
        dfs2(node,-1,graph[node].size());
        //cout << node;
        //cout << res << endl;
        //cout << endl << endl << endl;
        printf("%d\n",res);
    }
}