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
#define Pi 3.14159265358979323846264338327950288419716939937510
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<long long> vll;
int n;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);*/
    scanf("%d",&n);
    n*=n;
    long double eu=(long double)n*Pi;
    long double nue=n*2;
    cout << fixed << setprecision(6) << eu << "\n";
    cout << fixed << setprecision(6) << nue;
}
