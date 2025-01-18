#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n;
int main(){
    scanf("%d",&n);
    int posi=-1;
    for(int i=0;i<31;i++){
        if(n&(1<<i)){
            posi=i;
        }
    }
    int k=(1<<(posi+1))+n;
    printf("2 3\n");
    printf("%d %d %d\n",k,1<<(posi+1),n);
    printf("%d %d %d\n",n,k,n);
}