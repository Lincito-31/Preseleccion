#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vi buldings(n+2,1e9);
        priority_queue<pair<int,int>> cola;
        for(int i=1;i<=n;i++){
            scanf("%d",&buldings[i]);
        }
        vector<int> res(n+2,-1);
        res[0]=res[n+1]=0;
        for(int i=1;i<=n;i++){
            if(buldings[i]==0){
                cola.push({0,i});
            }
        }
        int level=0,segundo=0;
        while(!cola.empty()){
            pair<int,int> top=cola.top();
            if(res[top.second]!=-1){
                cola.pop();
                continue;
            }
            if((-top.first)<=level){
                cola.pop();
                res[top.second]=segundo;
                cola.push({-buldings[top.second-1],top.second-1});
                cola.push({-buldings[top.second+1],top.second+1});
            }else{
                int canti=((-top.first)-level-1)/k+1;
                level+=canti*k;
                segundo+=canti;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
}