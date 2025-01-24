#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> graph[n];
        vector<int> degree(n);
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        vector<pair<int,int>> grados(n);
        for(int i=0;i<n;i++){
            grados[i]={degree[i],i};
        }

        sort(ALL(grados));

        int op1=1;
        vector<int> cop=degree;
        op1+=cop[grados[n-1].second]-1;
        cop[grados[n-1].second]=0;
        for(auto u:graph[grados[n-1].second]){
            cop[u]--;
        }
        int best=0;
        for(int i=0;i<n;i++){
            best=max(best,cop[i]);
        }
        op1+=best-1;

        int op2=1;
        op2+=degree[grados[n-2].second]-1;
        degree[grados[n-2].second]=0;

        for(auto u:graph[grados[n-2].second]){
            degree[u]--;
        }
        best=0;
        for(int i=0;i<n;i++){
            best=max(best,degree[i]);
        }
        op2+=best-1;
        printf("%d\n",max(op1,op2));
    }
}
