#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        char complete[n+5];
        scanf(" %s",complete);
        vector<char> grupo[n];
        int canti=n/k;
        for(int i=0;i<k/2;i++){
            for(int j=0;j<canti;j++){
                grupo[i].push_back(complete[i+j*k]);
                grupo[i].push_back(complete[j*k+k-i-1]);
            }
        }
        if(k%2==1){
            for(int j=0;j<canti;j++){
                grupo[k/2].push_back(complete[(k/2)+j*k]);
            }
        }
        int cantidad=0;
        for(int i=0;i<=k/2;i++){
            map<char,int> dif;
            int maxi=0;
            for(auto u:grupo[i]){
                dif[u]++;
                maxi=max(maxi,dif[u]);
            }
            cantidad+=grupo[i].size()-maxi;
        }
        printf("%d\n",cantidad);
    }
}