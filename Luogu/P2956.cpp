#include <bits/stdc++.h>
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
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
int n,m,k,ax,ay,bx,by;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    vector<vector<bool>> nose(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>> lim(n);
    while(k--){
        scanf("%d %d %d %d",&ax,&ay,&bx,&by);
        ax--;ay--;bx--;by--;
        while(ax<=bx){
            lim[ax].push_back({ay,by});
            ax++;
        }
    }
    int con=0;
    for(int i=0;i<n;i++){
        sort(ALL(lim[i]));
        k=0;
        for(int j=0;j<lim[i].size();j++){
            while(k<=lim[i][j].S){
                if(lim[i][j].F<=k&&k<=lim[i][j].S){
                    con++;
                }
                k++;
            }
        }
    }
    printf("%d ",con);
}