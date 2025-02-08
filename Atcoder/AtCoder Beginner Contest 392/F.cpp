#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define RAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define LsOne(x) (x)&-(x)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int N;
vector<int> res;
vector<int> fenwick;
int sum(int x){
    int sum=0;
    while(x>0){
        sum+=fenwick[x];
        x-=LsOne(x);
    }
    return sum;
}
void update(int x){
    while(x<=N){
        fenwick[x]--;
        x+=LsOne(x);
    }
}
vector<int> sige;
int find(int x){
    return (x==sige[x])?x:sige[x]=find(sige[x]);
}
int main(){
    FASTIO;
    cin >> N;
    vector<int> ord(N+1);
    res.resize(N+1);
    sige.resize(N+1);
    fenwick.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> ord[i];
        sige[i]=i;
    }
    for(int i=N;i>=1;i--){
        int l=1,r=N;
        while(l<r){
            int mid=(l+r)>>1;
            if(sum(mid)+mid>=ord[i]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        int temp=find(l);
        res[temp]=i;
        update(temp);
        sige[temp]=temp+1;
    }
    for(int i=1;i<=N;i++){
        cout << res[i] << " ";
    }
}