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
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++){
        if(i<10)printf("0");
        printf("%d",i);
        if(i%n==0)printf("\n");
    }
    printf("\n");
    int lim=n-1;
    int con=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=lim){
                printf("  ");
            }else{
                if(con<10)printf("0");
                printf("%d",con);
                con++;
            }
        }
        lim--;
        printf("\n");
    }
}