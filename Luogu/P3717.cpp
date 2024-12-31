#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FIN \n
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) x.begin(),x.end()
#define LSOne(x) (x)&-(x)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
int n,m,k,a,b,r;
int main()
{
    scanf("%d %d %d",&n,&m,&r);
    vector<vector<bool>> mat(n+1,vector<bool>(n+1,false));
    vector<pair<int,int>> points(m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&points[i].F,&points[i].S);
    }
    int con=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<m;k++){
                if(pow(i-points[k].F,2)+pow(j-points[k].S,2)<=pow(r,2)){
                    con++;
                    break;
                }
            }
        }
    }
    printf("%d",con);
}
