#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vi res;
        for(int i=1;i<=n;i++){
            res.push_back(n/i);
            i=n/(int)(n/i);
        }
        res.push_back(0);
        printf("%d\n",res.size());
        for(int i=res.size()-1;i>=0;i--){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
}