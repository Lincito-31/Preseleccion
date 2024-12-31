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
int n;
string m;
int main()
{
    scanf("%d",&n);
    cin >> m;
    int i=m.size()-1;
    reverse(ALL(m));
    printf("%d*%d^%d",m[i]-48,n,i);
    i--;
    for(;i>=0;i--){
        if(m[i]=='0'){
            continue;
        }
        printf("+%d*%d^%d",m[i]-48,n,i);
    }
}