#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,n,a;
int main(){
    int prim[]={2,3,5,7,11,13,17,19,23,29,31};
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int con=1;
        vi res(n);
        map<int,int> mapa;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            for(int j=0;j<11;j++){
                if(a%prim[j]==0){
                    if(mapa.count(j)==0){
                        mapa[j]=con;
                        con++;
                    }
                    res[i]=mapa[j];
                    break;
                }
            }
        }
        printf("%d\n",mapa.size());
        for(int i=0;i<n;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
}